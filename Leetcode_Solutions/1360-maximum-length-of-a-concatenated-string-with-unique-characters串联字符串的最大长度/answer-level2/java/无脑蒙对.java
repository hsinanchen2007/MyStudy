这道题我写的时候想到了使用回溯来解决，然后在写的时候，中间出了一些逻辑上的错误，就是在对合法的字符串的判断那里，如果遍历到当前的这一层，如果当前的字符串和要拼接的字符串不可以拼接，我刚开始的逻辑是就break，但是其实这样想不对，因为和要拼接的这个不可以，就应该continue看后面的，而不应该直接break，去看和当前字符串在一层的下一个字符串，如果有一个可以和这个字符串拼接的字符串，就从这个位置开始继续往后看，因为前面的都已经不合法了，这样就可以得出没有重复元素的一个最大的字符串的长度
```
private int res=0;
    private boolean judge(String s){
        char arr[]=s.toCharArray();
        Set<Character> judge=new HashSet<Character>();
        for(int i=0;i<arr.length;i++){
            if(judge.contains(arr[i])){
                return false;
            }else{
                judge.add(arr[i]);
            }
        }
        return true;
    }
    private void dfs(List<String> arr,String cur,int index){
        for(int i=index;i<arr.size();i++){
            if(!judge(cur+arr.get(i))) {
            	continue;
            }
            cur=cur+arr.get(i);
            res=Math.max(res, cur.length());
            dfs(arr,cur,i+1);
            cur=cur.substring(0,cur.length()-arr.get(i).length());
        }
    }
    public int maxLength(List<String> arr) {
        String cur="";
        int index=0;
        dfs(arr,cur,index);
        return res;
    }
```
