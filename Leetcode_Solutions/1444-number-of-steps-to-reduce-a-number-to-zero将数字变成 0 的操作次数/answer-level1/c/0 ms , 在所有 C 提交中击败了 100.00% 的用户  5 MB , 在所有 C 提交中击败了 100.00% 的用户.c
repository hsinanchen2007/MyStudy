### 解题思路
位操作

### 代码

```c
int numberOfSteps (int num){
    if(num==0){
        return 0;
    }
    if(!(num&1)){
        return numberOfSteps(num>>1)+1;
    }else{
       return  numberOfSteps(num-1)+1;
    }
}
```