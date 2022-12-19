### 解题思路
先在dp数组中求出所有的子字符串是否是回文串。然后进行dfs回溯，枚举每个分割点。如果回溯过程中的子字符串都是回文串，到字符串末尾进行结算。
执行用时 : 2 ms , 在所有 Java 提交中击败了 99.86% 的用户

### 代码

```java
class Solution {
    public List<List<String>> partition(String s) {
        
        List<List<String>> result = new ArrayList<List<String>>();
        
        boolean[][] dp = initDP(s);

        helper(s, dp, 0, new ArrayList<String>(), result);    
        
                
        return result;   
    }
    
    public boolean[][] initDP(String s)
    {
        boolean[][] dp = new boolean[s.length()][s.length()];
        
        
        for(int t = 0; t<2;t++)
        {
            for(int i=0;i<s.length();i++)
            {
                int start = i;
                int end= i + t;
                while(start >=0 && end<s.length())
                {
                    if(s.charAt(start)==s.charAt(end))
                    {
                        dp[start][end] = true;
                    }
                    else
                    {
                        break;
                    }

                    start--;
                    end++;
                }
            }

        }
        
        return dp;
    }
    
    
    
    public void helper(String s, boolean[][] dp, int curIndex, List<String> curResult, List<List<String>> result)
    {
        if(curIndex == s.length())
        {
            result.add(new ArrayList<String>(curResult));            
            return;
        }

        for(int i=curIndex;i<s.length();i++)
        {
            if(dp[curIndex][i])
            {         
                
                String curSubS = s.substring(curIndex, i+1);
                
                curResult.add(curSubS);

                helper(s, dp, i+1, curResult, result);

                curResult.remove(curResult.size() - 1);                
            }
        }
  
    }
}
```