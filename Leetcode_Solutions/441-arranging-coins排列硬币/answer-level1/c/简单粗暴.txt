### 解题思路
此处撰写解题思路

### 代码

```c
int arrangeCoins(int n){
    long long sum=0, i;
    for(i=1;; i++){
        sum+=i;
        if(sum>n) break;
    }
    return i-1;
}
```