### 解题思路
分析到树的数量可以用卡特兰数来解决，c语言几行代码解决问题，唯一需要注意的数数量太大，不能用int表示，需用long long

### 代码

```c
long long numTrees(int n){
    long long count;
    if(n==0||n==1){
    count=1;
    }
    else {
    count=numTrees(n-1)*(4*n-2)/(n+1);
    }
    return count;
}
```