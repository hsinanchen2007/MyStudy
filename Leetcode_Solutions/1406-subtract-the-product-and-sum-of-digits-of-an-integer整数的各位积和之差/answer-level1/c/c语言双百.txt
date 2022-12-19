### 解题思路
执行用时 :0 ms, 在所有 C 提交中击败了100.00%的用户内存消耗 :5 MB, 在所有 C 提交中击败了100.00%的用户.

### 代码

```c
int subtractProductAndSum(int n){
    int sums=0,mul=1,result=0;
    while(n!=0){
        sums+=n%10;
        mul*=n%10;
        n/=10;
    }
    result=mul-sums;
    return result;
}
```