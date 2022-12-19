### 解题思路
此处撰写解题思路

### 代码

```c
bool hasAlternatingBits(int n){
    int f=1;
    long num=0;
    while(num<n){
        num=num*2+f;
        if(f==0) f=1;
        else f=0;
    }
    if(num==n) return true;
    else return false;
}
```