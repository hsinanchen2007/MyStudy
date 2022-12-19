### 解题思路
此处撰写解题思路
就很简单

### 代码

```c
bool hasAlternatingBits(int n){
    int wei1,wei2;
    while(n){
        wei1=n&1;
        wei2=(n&2)>>1;
        if(!(wei1^wei2))
            return false;
        n>>=1;
    }
    return true;
}
```