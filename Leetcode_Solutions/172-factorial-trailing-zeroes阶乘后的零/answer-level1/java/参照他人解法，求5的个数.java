执行结果：
通过
显示详情
执行用时 :
3 ms
, 在所有 Java 提交中击败了
92.14%
的用户
内存消耗 :
33.9 MB
, 在所有 Java 提交中击败了
79.72%
的用户
```
class Solution {
    
    public int trailingZeroes(int n) {
        int res=0;
        while(n>0){
            res=res+n/5;
            n=n/5;
        }
        return res;
    }
}
```
