**【历史重难点题目】**
* [历史重难点题目总结](https://mp.weixin.qq.com/mp/homepage?__biz=MzI4Njc4MzMwMw==&hid=1&sn=58bf8e995138b26984c05fd51f198196)

**【核心思想】**
* 这道题对于做过搜索引擎、学过信息检索的读者来说，应该不会陌生感，这道题的核心思想就是：**倒排索引**
* 思维转变一下，不是把两个数组比较，看有没有重复的。而是每次的数字出现，都去检查一下是否出现过，在哪个数组里出现的


**【思路】**
* 遍历`docs[][]`，将数字【在哪个数组中出现的】保存在map中，map的key就是遍历到的数字，value是一个由数组index组成的list
* 用一个`help`矩阵来存储数组与数组之间有多少交集
* 最后遍历`help`数组，按指定格式输出


**【代码】**
```java
public List<String> computeSimilarities(int[][] docs) {
    List<String> ans = new ArrayList<>();
    Map<Integer, List<Integer>> map = new HashMap<>();
    int[][] help = new int[docs.length][docs.length];
    for (int i = 0; i < docs.length; i++) {
        for (int j = 0; j < docs[i].length; j++) {
            List<Integer> list = map.get(docs[i][j]);
            if (list == null) {
                list = new ArrayList<>();
                map.put(docs[i][j], list);
            } else {
                for (Integer k : list) {
                    help[i][k]++;
                }
            }
            list.add(i);
        }

        for (int k = 0; k < docs.length; k++) {
            if (help[i][k] > 0) {
                ans.add(k + "," + i + ": " + String.format("%.4f", (double) help[i][k] / (docs[i].length + docs[k].length - help[i][k])));
            }
        }
    }
    return ans;
}
```


**【备注】**
* 代码不难，可以轻松看懂
* 思想很经典
* 双百通过

**【关注微信公众号，带你拿大厂offer】**
![logo_gif.gif](https://pic.leetcode-cn.com/ed150d8fee8b7cf5847c890e72762668d08496d97138dfa3a2377c1650d0fcf0-logo_gif.gif)
