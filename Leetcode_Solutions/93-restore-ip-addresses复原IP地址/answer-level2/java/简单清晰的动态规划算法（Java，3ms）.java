贡献一个动态规划的思路。

建立dp数组，dp[i]代表截至第i位字符串能够组成的地址集合。对于第i位上的地址集合，可以遍历前三位j，状态转移方程为：
```
dp[i] += dp[j] + num(j,i);
```
其中，+=表示添加，dp[j]表示集合中不大于4位的ip地址，num(j,i)表示字符串[j+1,i]范围构成的0-255的数字。

```java
public List<String> restoreIpAddresses(String s) {
    if(s.length() > 12 || s.length() < 4){
        return new ArrayList<>();
    }
    ArrayList<ArrayList<String>>[] dp = new ArrayList[s.length() + 1];
    dp[0] = new ArrayList<ArrayList<String>>(){{add(new ArrayList<>());}};

    for(int i = 1; i <= s.length(); i++){
        dp[i] = new ArrayList<>();
        for(int j = i - 3 > 0 ? i - 3 : 0; j < i; j++){
            String str = s.substring(j, i);
            int num = Integer.valueOf(str);
            if((str.charAt(0) == '0' && str.length() != 1) || num > 255){
                continue;
            }
            ArrayList<ArrayList<String>> pre = dp[j];
            for(ArrayList<String> prestr : pre){
                if(prestr.size() > 3){
                    continue;
                }
                dp[i].add(new ArrayList<String>(prestr){{add(str);}});
            }
        }
    }
    ArrayList<String> result = new ArrayList<>();
    for(ArrayList<String> strs : dp[s.length()]){
        if(strs.size() != 4){
            continue;
        }
        result.add(strs.get(0) + "." + strs.get(1) + "." + strs.get(2) + "." + strs.get(3));
    }
    return result;
}
```

欢迎与我交流~

[LeetCode 从零单刷个人笔记整理（持续更新）](https://blog.csdn.net/qq_20304723/article/details/89401203)

github：[https://github.com/ChopinXBP/LeetCode-Babel](https://github.com/ChopinXBP/LeetCode-Babel)