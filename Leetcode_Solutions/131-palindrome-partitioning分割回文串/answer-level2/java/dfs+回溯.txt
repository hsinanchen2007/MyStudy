再难的递归，只要你用测试示例（"aab"就可以）跑一遍就会了。然后注意那个remove。
```java
class Solution {
     List<List<String>>list=new ArrayList<>();
    String s;
    public List<List<String>> partition(String s) {
        //从头到尾递归+回溯。
       this.s=s;
        //这个是满足的每一个集合
        List<String>ll=new ArrayList<>();
        dfs(ll,0);
        return list;
    }
    public void dfs(List<String>ll,int index){
        if(index==s.length())
        {
        list.add(new ArrayList<>(ll));
        return;
        }
        //i从index开始是因为单个字符也是回文子串
        for(int i=index;i<s.length();i++)
        {
            //如果是回文
            if(isPalindrome(index,i)){
                
                //把当前的回文子串s(index,i)加进去
               ll.add(s.substring(index,i+1));
                dfs(ll,i+1);
                //把加进去的回文子串去处。和上面加进去的回文子串是同一个回文子串。
                ll.remove(ll.size()-1);
        }
    
    }
}
    public boolean isPalindrome(int start,int end){
        while(start<end){
            if(s.charAt(start)!=s.charAt(end))
                return false;
            start++;
            end--;
        }
        return true;
    }
}
    
```