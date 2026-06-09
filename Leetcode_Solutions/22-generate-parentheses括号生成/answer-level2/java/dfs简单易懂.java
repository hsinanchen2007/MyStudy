```
class Solution {
    public List<String> generateParenthesis(int n) {
     ArrayList<String>ans=new ArrayList<>();//存放生成的括号组合
     huisu(ans,0,0,n,"");
     return ans;
    }
    public void huisu(ArrayList<String>ans,int left,int right,int n,String s){
        if(right==n)//右边括号到达数量，组合完毕
        ans.add(s);
        if(left<n)
        huisu(ans,left+1,right,n,s+"(");//添加左括号
        if(right<left)
        huisu(ans,left,right+1,n,s+")");//添加右括号
    }
}
```
