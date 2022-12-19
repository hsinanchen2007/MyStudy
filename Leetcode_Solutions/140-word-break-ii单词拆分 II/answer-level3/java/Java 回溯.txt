### 解题思路
使用之前一题的动态规划来辅助，不过方向反过来，判断从当前下标到最后是否能够被正确划分。
然后就直接回溯就行了。

### 代码

```java
class Solution {
    private void wordBreak_help(String s, HashSet<String> words, StringBuilder curr, boolean dp[]){
        if (s.isEmpty()){
            ans.add(curr.toString().trim());
            return;
        }
        if (!dp[dp.length-s.length()]){
            return;
        }

        for (int i = 0; i < s.length(); i++){
            String sub = s.substring(0, i+1);
            if (words.contains(sub)){
                curr.append(sub + " ");
                wordBreak_help(s.substring(sub.length()),words,curr,dp);
                curr.delete(curr.length()-sub.length()-1,curr.length());
            }
        }
    }

    List<String> ans = new ArrayList<>();
    public List<String> wordBreak(String s, List<String> wordDict) {
        HashSet<String> words = new HashSet<>(wordDict);
        boolean dp [] = new boolean [s.length()];
        for (int i = s.length()-1; i >= 0; i--){
            for (int j = i; j < s.length(); j++){
                if (j == i && words.contains(s.substring(j,s.length()))){
                    dp[i] = true;
                    break;
                }
                if (j != i && dp[j] && words.contains(s.substring(i,j))){
                    dp[i] = true;
                    break;
                }
            }
        }

        wordBreak_help(s,words,new StringBuilder(),dp);
        return ans;
    }
}
```