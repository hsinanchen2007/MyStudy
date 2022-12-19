### 解题思路
新手应该都是像我这样的8

### 代码

```c
int hammingWeight(uint32_t n) {
    int sum=0;
    while(n>0){
        if(n%2==1){
            sum++;
        }
        n/=2;
    }
    return sum;
}
```