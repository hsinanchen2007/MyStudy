![image.png](https://pic.leetcode-cn.com/0436009bf121ab425677a9d4faf4ae39a8279dd1a972cbb682f2618f71bea79f-image.png)
```
// 获取最短单词距离：首先获取距离最近的两个单词，随后计算二者距离
// 哈希表：字典功能、无重复：word -> ArrayList<Integer>()
// 遍历数组并储存在HashMap<word, indexes>
// 获取两个整型列表并找出二者之间差的最小值的绝对值

class WordDistance {
    Map<String, ArrayList<Integer>> map = new HashMap<String, ArrayList<Integer>>();
    public WordDistance(String[] words) {
        for (int i = 0; i < words.length; i++) {
            if (map.isEmpty() || !map.containsKey(words[i])) {
                ArrayList<Integer> list = new ArrayList<Integer>();
                list.add(i);
                map.put(words[i], list);
            } else {
                map.get(words[i]).add(i);
            }
        }
    }
    
    public int shortest(String word1, String word2) {
        int res = 2147483647;
        for (Integer i : map.get(word1)) {
            for (Integer j : map.get(word2)) {
                res = Math.min(res, Math.abs(i - j));
            }
        }
        return res;
    }
}

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance obj = new WordDistance(words);
 * int param_1 = obj.shortest(word1,word2);
 */
```
