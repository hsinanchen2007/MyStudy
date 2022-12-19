执行结果：
通过
显示详情
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
33.5 MB
, 在所有 Java 提交中击败了
60.03%
的用户
```
class Solution {
    public int climbStairs(int n) {
        if(n==1)return 1;
        if(n==2)return 2;
        int[] res = new int[n];
        res[0]=1;
        res[1]=2;
        for(int i=2; i<n; i++){
            res[i]=res[i-1]+res[i-2];
        }
        return res[n-1];
    }
   
}
```
