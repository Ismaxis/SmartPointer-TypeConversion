# Example of *Smart pointers* conversion of inherit types.

First of all, take close attention to **converting constructor**. It is not declared as explicit, what allows compiler to use it for *implicit converions*:
https://github.com/Ismaxis/SmartPointer-TypeConversion/blob/8c542c30522f4df8a659919eee5e04e3fd9583b2/SmartPointer.h#L13

#### Now lets have a look at actual *Raw pointers-like* behaviour.

Function ```print``` has ```const SmartPointer<A>&``` as parameter: 
https://github.com/Ismaxis/SmartPointer-TypeConversion/blob/8c542c30522f4df8a659919eee5e04e3fd9583b2/main.cpp#L29

Variable ```b``` has type ```SmartPointer<B>```:
https://github.com/Ismaxis/SmartPointer-TypeConversion/blob/8c542c30522f4df8a659919eee5e04e3fd9583b2/main.cpp#L36

And when we pass ```b``` to ```print``` compiler looks for ways to convert ```SmartPointer<B>``` to ```SmartPointer<A>```:
https://github.com/Ismaxis/SmartPointer-TypeConversion/blob/8c542c30522f4df8a659919eee5e04e3fd9583b2/main.cpp#L40

And here **converting constructor** from ```SmartPointer<T>``` to ```SmartPointer<U>``` comes into play.
Compiler founds it and starts checking if conversion from ```T*``` to ```U*``` is possible.

In that case:
- ```B``` -> ```T```
- ```A``` -> ```U```

Since ```B``` is inherited from ```A```, ```B*``` easily converts into ```A*``` and can be passed to ```SmartPointer``` constructor:
https://github.com/Ismaxis/SmartPointer-TypeConversion/blob/8c542c30522f4df8a659919eee5e04e3fd9583b2/SmartPointer.h#L6

And conversion happends!

#### As the result we have a *Smart pointer* that behaves similar to *Raw pointer*, from inheritance perspective. :tada:

---
#### This example is taken from "More effective C++" by Scott Meyers
