### 解题思路
此处撰写解题思路
这题和一般的回溯题大同小异。
当字符串遍历完了，return;
否则判断当前子串是否为回文数，是回文数的话加进去，进行性一轮的查找。
看看代码啥都懂了
### 代码

```java
class Solution {
    List<List<String>>ret=new ArrayList<>();
    List<String>p=new ArrayList<>();
    public List<List<String>> partition(String s) {
        if(s==null||s.length()==0) return ret;
        dfs(s);
        return ret;
    }
    private void dfs(String s){
        if(s.length()==0){
            ret.add(new ArrayList(p));
            return;
        }
        for(int i=0;i<s.length();i++){
            if(ispa(s,0,i)){
                p.add(s.substring(0,i+1));
                dfs(s.substring(i+1));
                p.remove(p.size()-1);
            }
        }
    }
    private boolean ispa(String s,int i,int j){
        while(i<j){
            if(s.charAt(i)!=s.charAt(j)) return false;
            i++;
            j--;
        }
        return true;
    }
}
```