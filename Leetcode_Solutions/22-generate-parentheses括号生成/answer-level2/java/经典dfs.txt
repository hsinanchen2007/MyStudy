### 解题思路
太笨了，只想到了dfs一种方法 不知道为什么内存占用特别多，但时间98

### 代码

```java
class Solution {
 public List<String> generateParenthesis(int n) {
        List<String> ans = new ArrayList<>();
        String s="";
        findPath(0,0,n,s,ans);
        return ans;
    }
    public void findPath(int left,int right,int n,String s,List<String> ans){
        if(left==n)
            for (; right <n ; right++) {
                s+=")";
            }
        else if(left<n){
            if(left>right){
                if(left+1<=n)
                    findPath(left+1,right,n,s+"(",ans);
                findPath(left,right+1,n,s+")",ans);
            }
            if(left==right&&left+1<=n)
                findPath(left+1,right,n,s+"(",ans);
            }
        if(left==n&&right==n)
        ans.add(s);
    }
}
```