![QQ截图20191027130438.png](https://pic.leetcode-cn.com/9228620ec9aee978c105229482af334cf2633c0f5ea28256b32e192a3c4fb8f6-QQ%E6%88%AA%E5%9B%BE20191027130438.png)
思路过程：
1.获取wordDict的长度序列，就是其中包含几种不同类型的长度，方便后面按照字典中出现的长度进行截取dfs,加快搜索过程；
2.进行dfs的搜索，中间使用一个dp数组来进行记忆化进行剪枝 dp[start][len]表示从s的start位置开始截取长度为len是否能够得到最后正确的解
如果不能返回-1，则进行剪枝；否则继续进行dfs寻找全部的最优解
详情见代码注释：
```
class Solution {
  List<String> ans;
    Set<Integer> lenset;//长度种类
    Set<String> wordSet;//单词的字典，方便查询
    String s;
    int[][] dp;//进行记忆化剪枝的数组
    private String gen(List<String> str){
        //生成给定的输出模型
        StringBuilder sb=new StringBuilder();
        boolean first=true;
        for(String s:str){
            if(first){
                first=false;
                sb.append(s);
            }
            else sb.append(" ").append(s);
        }
        return sb.toString();
    }
    private int helper(List<String> temp,int start){
        if(start==s.length()){
            //能够正确拆分单词，返回1
            ans.add(gen(temp));
            return 1;
        }
        boolean ok=false;//标记
        for(int len:lenset){
            if(start+len<=s.length()){
                String st=s.substring(start,start+len);
                if(wordSet.contains(st)&&dp[start][len]!=-1){//如果已经不可拆分，直接剪枝
                    temp.add(st);
                    dp[start][len]=helper(temp,start+len);
                    if(dp[start][len]==1) ok=true;
                    temp.remove(temp.size()-1);
                }
            }
        }
        if(ok==false)
            return -1;
        else return 1;
    }
    public List<String> wordBreak(String s, List<String> wordDict) {
        ans=new ArrayList<>();
        lenset=new HashSet<>();
        wordSet=new HashSet<>();
        this.s=s;
        int max=0;
        for(int i=0;i<wordDict.size();i++){
            max=Math.max(max,wordDict.get(i).length());
            lenset.add(wordDict.get(i).length());
            wordSet.add(wordDict.get(i));
        }
        dp=new int[s.length()+1][max+1];
        helper(new ArrayList<String>(),0);
        return  ans;
    }
}
```


