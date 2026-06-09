### 第一种方法：动态规划
对于本题，此题中的状态为字符串的长度，设置dp[i]表示长度为i的字符串是否是字典中的单词，状态转移方程比较好想，这里解释一下，对于长度为i的字符串，那它是否可以由字典中的单词组成怎么判断呢，其实就是dp[i]=(dp[0]&&s[0-i])||(dp[1]&&s[1-i])||(dp[2]&&s[2-i])||...||(dp[i-1]&&dp[i-1,i])这些个情况中只要有一种情况是真的，那dp[i]就可以由字典中的单词组成,这里要注意的是当字符串的长度为0时，也就是dp[0],此时主要取决于当前的这个串是不是字典中的单词，所以初始化的时候将dp[0]设置为true，便于以后的求解

```
class Solution {
    public boolean wordBreak(String s, List<String> wordDict) {
        //加快查询速度
        Set<String> Dict=new HashSet<String>();
        for(String cur:wordDict){
            Dict.add(cur);
        }
        
        //获得s的长度
        int len=s.length();
        //构造dp数组
        boolean[]dp=new boolean[len+1];
        dp[0]=true;
        
        //遍历s的所有的子串
        for(int i=1;i<=len;i++){
        	boolean ok=false;
        	for(int j=0;j<i;j++) {
        		ok=ok||dp[j]&&Dict.contains(s.substring(j,i));
                if(ok) break;
        	}
            dp[i]=ok;
        }
        
        return dp[len];
    }
}
```
### 第二种方法 回溯加记忆化
这道题首先想到的肯定是回溯产生该字符串切割后的所有的子串，如果对于每一个子串都在字典中，则返回true，否则返回false，但是这样做是会超时的，因为时间复杂度为阶乘级别的，尤其是在存在很多重复的子串时，这里改进的策略就是对于一个字符串，子串之间有相同的子串，那我们设置一个变量保存以某个子串为开头是否可以，这样在讨论另一种情况的时候，如果遇到了这个子串开头的情况，直接返回对应的布尔类型的值，当然这里我认为对于true的存储没有什么意义，因为结果所对应的情况只有一次，所以如果能一直递归下去，最后递归终止，也就是满足条件了，这时候才会对某个串赋值为true，起不到记忆化的作用，所以不写也可以

```
class Solution {
    Map<String,Boolean> map=new HashMap<>();
    private boolean dfs(Set<String> Dict,String s){
        if(s.equals("")){
            return true;
        }
        
        if(map.containsKey(s)){
            return map.get(s);
        }
        
        //遍历所有的分割位置
        for(int i=1;i<=s.length();i++){
            //获取一段字符串
            String cur=s.substring(0,i);
            
            //如果当前的这个集合中没有这个单词，continue
            if(!Dict.contains(cur)) continue;
            
            //否则的话，dfs
            if(dfs(Dict,s.substring(i))){
                map.put(s.substring(0,i),true);
                return true;
            }
        }
        
        //如果此时以s开头的不能产生答案，就对map进行赋值
        map.put(s,false);
        return false;
    }
    
    public boolean wordBreak(String s, List<String> wordDict) {
        Set<String> Dict=new HashSet<String>();
        for(String cur:wordDict){
            Dict.add(cur);
        }
        
        return dfs(Dict,s);
    }
}
```