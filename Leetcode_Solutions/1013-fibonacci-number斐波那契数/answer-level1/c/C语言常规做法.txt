```c
int fib(int N){
    switch(N){
        case 0: return 0;
        case 1: return 1;
        default: return fib(N-1)+fib(N-2);
    }
}
```