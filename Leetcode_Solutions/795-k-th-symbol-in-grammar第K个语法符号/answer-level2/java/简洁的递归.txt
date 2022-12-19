### 解题思路
本来还想秀一下思路的，直到我看到了评论区大佬的写法tql。
如果K大于2 ^ N - 1 ，那这一位一定是从上面第K - (Math.pow(2, N - 1) / 2)取反得到的
否则与上面第K位一致
### 代码

```java
class Solution {
    public int kthGrammar(int N, int K) {
        if (N == 1) return 0;
        int tmp = (int)(Math.pow(2, N - 1) / 2);
        if(K > tmp)
            return 1 - kthGrammar(N - 1, K - tmp);
        else 
            return kthGrammar(N - 1, K);
        
    }
}
```
### 时间复杂度  O(N)