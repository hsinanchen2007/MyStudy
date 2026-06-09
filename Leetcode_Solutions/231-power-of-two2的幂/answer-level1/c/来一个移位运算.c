```
bool isPowerOfTwo(int n){
    unsigned int a=1;
    for(int i=0;i<32;i++){
        if(n<0)return false;
        if(a<<i==n)return true;
    }
    return false;
}
```
