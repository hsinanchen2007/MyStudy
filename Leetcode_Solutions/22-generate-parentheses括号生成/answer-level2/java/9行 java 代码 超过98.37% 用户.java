### 解题思路

其实就是填充位置，每次填充都可以允许你有两步

### 代码

```java
class Solution {
   
    public void gener(List<String> ans,String str,int le,int re,int n){
        if (le == n && re == n) {
            ans.add(str);
        }
        if (le < n ) {
            gener(ans,str+"(",le+1,re,n);
        }
        if (re < n && re<le) {
            gener(ans,str+")",le,re+1,n);
        }
    }

    public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        gener(ans,"(",1,0,n);
        return ans;
    }
}
```