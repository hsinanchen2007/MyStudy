### 解题思路
此处撰写解题思路
左括号数大于右括号数，即可添加右括号。
### 代码

```java
class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> ans=new ArrayList<>();
        backtrack(ans,"",0,0,n);
        return ans;
        

    }
    public void backtrack(List<String> ans,String s,int begin,int end,int l) {
        if(s.length()==2*l){
            ans.add(s);
            return ;
        }
        if(begin<l){
            backtrack(ans,s+'(',begin+1,end,l);
        }
        if(end<begin){
            backtrack(ans,s+')',begin,end+1,l);
        }
    }
}
```