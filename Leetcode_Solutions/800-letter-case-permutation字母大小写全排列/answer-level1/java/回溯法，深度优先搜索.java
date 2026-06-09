```
class Solution {
    List<String> ans = new ArrayList<>();
    int dis = 'A'-'a';
    public List<String> letterCasePermutation(String S) {
        char[] str = S.toCharArray();
        dfs(str,0);
        return ans;
    }
    /**
    *   深度优先搜索
    *   str     字符数组
    *   index   当前搜索深度
    **/
    private void dfs(char[] str,int index){
        if(index==str.length){
            ans.add(new String(str));
            return;
        }
        if(str[index]>='a'&&str[index]<='z'){//该位置为小写字母
            dfs(str,index+1);   //往下一深度搜索
            str[index]+=dis;    //字母大写
            dfs(str,index+1);   //往下一深度搜索
            str[index]-=dis;    //字母变回小写
        }else if(str[index]>='A'&&str[index]<='Z'){
            dfs(str,index+1);
            str[index]-=dis;
            dfs(str,index+1);
            str[index]+=dis;
        }else{
            dfs(str,index+1);
        }
        return;
            
    }
}
```
