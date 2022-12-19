# 尝试
- 从头开始遍历s,若遍历到i形成的字符串`s[0-i]`在字典中`wordDict`，则只要判断`s[i+1 - s.length()]`是否可以被空格拆分为一个或多个在字典中出现的单词即可。以这种思想构建递归
- 代码如下：
```
    public boolean wordBreak(String s, List<String> wordDict) {
        // 创建字典中字符串存在的set，创建的同时记录字典中最长的字符串的长度
        HashSet<String> set = new HashSet<>();
        for (String str : wordDict) {
            set.add(str);
        }
        return getResult(s,0,set);
    }

    private boolean getResult(String s, int start, HashSet<String> set) {
        if(start == s.length()){
            return true;
        }
        for (int i = start;i < s.length(); i++) {
            if(set.contains(s.substring(start,i + 1))){
                if(getResult(s,i+1,set)){
                    return true;
                }
            }
        }
        return false;
    }
```
- 可惜结果超时：
- ![image.png](https://pic.leetcode-cn.com/260f601ab93f9f2da4823877a6b62a025e36664cc37c1abe7f8b4e89b9c770dc-image.png)
# memorization技术优化
- 考虑到每次计算`getResult(s,i+1,set)`回带来大量重复的计算，所以这里使用memorization技术存储重复计算的结果
- 代码如下：
```
    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> set = new HashSet<>();
        for (String str : wordDict) {
            set.add(str);
        }
        HashMap<Integer,Boolean> memo = new HashMap<Integer,Boolean>();
        return getResult(s,0,set,memo);
    }

    private boolean getResult(String s, int start, HashSet<String> set,HashMap<Integer,Boolean> memo) {
        if(start == s.length()){
            return true;
        }
        if(memo.containsKey(start)){
            return memo.get(start);
        }
        for (int i = start;i < s.length(); i++) {
            if(set.contains(s.substring(start,i + 1))){
                if(getResult(s,i+1,set,memo)){
                    memo.put(start,true);
                    return true;
                }
            }
        }
        memo.put(start,false);
        return false;
    }
```
![image.png](https://pic.leetcode-cn.com/51f39d36a0a4fd6b4732e44495e4623bbeff7bf62757ad78d2131816c44be13e-image.png)
- 顺利通过，可惜时间成本上并不是很完美。
- 考虑到每次遍历s字符串，检查是否在set中存在是，每次都是从头遍历到尾，这样必定回带来大量的无效遍历，如果当前遍历的长度大于字段中字符串的最大长度，则一定不可能匹配成功。
- 所以下面就是对遍历s做出进一步优化。
`遍历优化`
- 在上一步已经简单介绍过了优化思想，所以这里直接上代码，如下：
```
    public boolean wordBreak(String s, List<String> wordDict) {
        HashSet<String> set = new HashSet<>();
        int max = Integer.MIN_VALUE;
        for (String str : wordDict) {
            max = Math.max(str.length(),max);
            set.add(str);
        }
        // 记录map，记录重复的计算的结果
        HashMap<Integer,Boolean> map = new HashMap<>();
        return getResult(s,0,set,max,map);
    }

    /**
     *
     * @param s
     * @param start  表示索引开始位置
     * @param set    字段中字符串的集合
     * @param max    每次遍历s时不可以超出max长度，否则肯定为false
     * @param map    记忆表
     * @return
     */
    private boolean getResult(String s, int start, HashSet<String> set,int max,HashMap<Integer,Boolean> map) {
        if(start == s.length()){
            return true;
        }
        if(map.containsKey(start)){
            return map.get(start);
        }
        // 关键步骤： 遍历的时候加上max的长度限制，避免无限遍历至s结尾
        for (int i = start; i < start + max && i < s.length(); i++) {
            if(set.contains(s.substring(start,i + 1))){
                if(getResult(s,i+1,set,max,map)){
                    map.put(start,true);
                    return true;
                }
            }
        }
        map.put(start,false);
        return false;
    }

```
![image.png](https://pic.leetcode-cn.com/e0ab88f18d7903f604259248e6c870cdeff2f1bd9c7c2a1453de4cfd9810cfe1-image.png)
优化效果明显~~~