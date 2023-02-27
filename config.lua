executable = "./mask"
run_command = "<executable> s1.dna s2.dna"

multiruns_params = {
    { 
        name= "1x16", 
        envv_OMP_NUM_THREADS="16",
    },
    { 
        name= "1x32", 
        envv_OMP_NUM_THREADS="32",
        run_command = "<executable> s1.dna s2.dna",
    },
    { 
        name= "1x64", 
        envv_OMP_NUM_THREADS="64",
        run_command = "<executable> s1.dna s2.dna",
    },
    { 
        name= "1x128", 
        envv_OMP_NUM_THREADS="128",
        run_command = "<executable> s1.dna s2.dna",
    },
    { 
        name= "1x256", 
        envv_OMP_NUM_THREADS="256",
        run_command = "<executable> s1.dna s2.dna",
    },
}

--    $ maqao oneview -R1 -WS c=config.lua