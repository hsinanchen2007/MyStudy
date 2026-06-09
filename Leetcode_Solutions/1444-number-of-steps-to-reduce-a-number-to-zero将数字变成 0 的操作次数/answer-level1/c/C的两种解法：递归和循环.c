### 解题思路
show  code

### 代码

```c
/*
    while循环解法
*/
int numberOfSteps_1 (int num){
    int ret = 0;
    while(num)
    {
        num=(num%2)?num-1:num>>1;
        ret++;
    }
    return ret;
}
/*
    递归解法
*/
int numberOfSteps(int num){
    if(!num) return 0;
    
    if(num%2) return numberOfSteps(num-1)+1;
    else return numberOfSteps(num>>1)+1;
}
```