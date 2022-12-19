### 解题思路
遞歸的for循環語句。參考官方解答使用fib的算數方法。
因爲只有兩種跳法，所以最後一步的時候有兩種情況
f(n)=f(n-1)+f(n-2)，表示分類討論時最後一下為一下跳一階和一次跳兩階的縂可能數，這與斐波那契數列求法是相同的，差別在於基礎條件不同

### 代码

```cpp
class Solution {
public:
    int numWays(int n) {
        return step(n);
    }
    int step(int n){
/*        if(n==0) return 1;
        if(n==1) return 1;
        if(n==2) return 2;
        return step(n-1)+step(n-2);
        */
    if(n==0) return 1;
    else if(n==1) return 1;
    else if(n==2) return 2;
    int a=2,b=1,temp=0;
    for(int i=0;i<n-2;i++)//進行n-2次fib相加，區別為【1：1】【2：2】
    {
        temp=(a+b)%1000000007;
        b=a%1000000007;
        a=temp%1000000007;
        
    }
    return a%1000000007;
    }
};
```