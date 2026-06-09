#####  方法1：DP+DFS


- `dfs`中：
```
 for (int i = 0; i < end; i++) {
            if (dp[i]) {
                String sub = s.substring(i, end);
                if (wordDict.contains(sub)) {
                    levelList.add(sub);
                    dfs(s, wordDict, dp, i, resList, levelList);
                    levelList.remove(levelList.size() - 1);
                }
            }
        }
```

其中`dp[i]`是`True`时才有效，如果`dp[i]`为`False`，说明以`s[i-1]`结尾的字符串，其不能分割成多个子字符串，这些子字符串在`wordDict`中找到
- 如果`s[0...i-1]`可以拆分，而`s[i...end]`又在`wordDict`中找得到，可以进下一层
- 退出条件：当`end`位置到达`0`位置，也就是到达字符`s`的开头位置


```java []
public List<String> wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && wordDict.contains(s.substring(j, i))) {
                    dp[i] = true;
                    break;//[i]是套在[j]外面的，一旦是True时，没有必要再次判断
                }
            }
        }
        List<String> resList = new ArrayList<>();
        if (dp[n]) {
            dfs(s, wordDict, dp, n, resList, new ArrayList<String>());
            return resList;
        }
        return resList;
    }

    /**
     *
     * @param s 原字符
     * @param wordDict 字典
     * @param dp 动态数组，dp[i]表示以s[i-1]结尾的字符串能否被wordDict拆分，换句话说，
     *           以s[i-1]结尾的字符串拆分为一个或者多个字符串，是否都出现在wordDict中，在wordDict中都能找到
     * @param end 字符s的索引位置
     * @param resList 结果集
     * @param levelList 当前层的结果集
     */
    private void dfs(String s, List<String> wordDict, boolean[] dp, int end, List<String> resList, ArrayList<String> levelList) {
        if (end == 0) {
            //退出条件
            StringBuilder sb = new StringBuilder();
//            System.out.println(JSON.toJSONString(levelList));
            //levelList加入的顺序是倒置的，倒着遍历
            for (int i = levelList.size() - 1; i >= 0; i--) {
                sb.append(levelList.get(i)).append(" ");
            }
            sb.deleteCharAt(sb.length() - 1);//为了去掉最后一个组装后的空格
            resList.add(sb.toString());
            return;
        }
        for (int i = 0; i < end; i++) {
            if (dp[i]) {
                //i到end的位置，去头取尾
                String sub = s.substring(i, end);
                if (wordDict.contains(sub)) {
                    levelList.add(sub);
                    dfs(s, wordDict, dp, i, resList, levelList);
                    levelList.remove(levelList.size() - 1);
                }
            }
        }
    }
```
```python []
print('Hello world!')
```

