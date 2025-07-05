
# Memory Optimization Analysis for Embedded Structures


## 📌 Project Overview
This analysis compares two different structure implementations for GPIO control registers in embedded systems, focusing on their memory footprint in microcontroller environments.

## Structure Definitions

#### YAPI-1 (Union-Based Implementation) 
-> Uses nested unions to optimize memory usage  
-> More efficient for memory-constrained MCUs   

    StructVariable → UnionVariable → StructVariable → StructVariable

#### YAPI-2 (Direct Struct Implementation)
-> Traditional struct implementation    
-> Simpler but less memory efficient

    StructVariable → StructVariable → StructVariable → StructVariable
  

## Memory Footprint Analysis
#### YAPI-1 
    printf("Variable size: %d byte\n", sizeof(GpioCtrlRegs));          // Output: 4 bytes
    printf("Variable size: %d byte\n", sizeof(GpioCtrlRegs.GPBMUX1));  // Output: 4 bytes 
    printf("Variable size: %d byte\n", sizeof(GpioCtrlRegs.GPBMUX1.all)); // Output: 4 bytes
    printf("Variable size: %d byte\n", sizeof(GpioCtrlRegs.GPBMUX1.bit)); // Output: 4 bytes

#### YAPI-2
    printf("Variable size: %d byte\n", sizeof(GpioCtrlRegs));          // Output: 8 bytes
    printf("Variable size: %d byte\n", sizeof(GpioCtrlRegs.GPBMUX1));  // Output: 8 bytes
    printf("Variable size: %d byte\n", sizeof(GpioCtrlRegs.GPBMUX1.all)); // Output: 4 bytes
    printf("Variable size: %d byte\n", sizeof(GpioCtrlRegs.GPBMUX1.bit)); // Output: 4 bytes     


## Key Findings
#### Memory Efficiency:

    -> YAPI-1 uses 50% less memory (4 bytes) compared to YAPI-2 (8 bytes)   
    -> Significant advantage in memory-constrained MCU environments

#### Bitfield Benefits:

    -> Using bitfields within structures is far more memory-efficient than separate variables
    -> Particularly valuable when dealing with hardware registers

#### Scalability Impact:

    For 100 register definitions:
        -> YAPI-1 would use ~400 bytes
        -> YAPI-2 would use ~800 bytes
    The memory savings become substantial in larger implementations
