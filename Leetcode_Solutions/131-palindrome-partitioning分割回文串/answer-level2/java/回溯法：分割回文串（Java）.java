执行用时 : 7 ms, 在所有 Java 提交中击败了80.51%的用户

内存消耗 :40.4 MB, 在所有 Java 提交中击败了87.32%的用户
```
class Solution {
    List<List<String>> res=new ArrayList<>();
    public List<List<String>> partition(String s) {
        if(s==""||s.length()==0){
            return res;
        }
        List<String> list=new ArrayList<>();
        backTracing(list,s,0);
        return res;
    }
    public void backTracing(List<String> list,String s, int i){
        if(i==s.length()){
            res.add(list);
        }
        for(int j=i+1;j<=s.length();++j){
            if(isParlindrome(s.substring(i,j))){
                list.add(s.substring(i,j));
                backTracing(new ArrayList<String> (list),s,j);
                list.remove(list.size()-1);
            }
        }
    }
    public boolean isParlindrome(String s){   //判断是否为回文串
        if(s==""||s.length()==0){
            return false;
        }
        int len=s.length();
        for(int i=0;i<=len/2;++i){
            if(s.charAt(i)!=s.charAt(len-1-i)){
                return false;
            }
        }
        return true;
    }
}
```