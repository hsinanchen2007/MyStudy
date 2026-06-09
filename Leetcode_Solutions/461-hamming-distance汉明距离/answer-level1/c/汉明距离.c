### 解题思路
仔细研究位运算

### 代码

```c
int hammingDistance(int x, int y){
    int sum=0;
    x=x^y;
    while(x!=0)
    {   
        y=1;
        y=y&x;
        if(y)
            ++sum;
        x=x>>1;
    }
    return sum;
}
```