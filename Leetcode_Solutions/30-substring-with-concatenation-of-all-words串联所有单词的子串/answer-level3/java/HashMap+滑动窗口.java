我菜，大家看看有什么优化意见
这时间也太长了吧。
![屏幕快照 2019-10-29 19.41.43.png](https://pic.leetcode-cn.com/d90145e4689bc527c9728dcdee3731ab530cc6c0bd09d268044acbe06a347e26-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202019-10-29%2019.41.43.png)


啊对了，idea 刷 leetcode 插件地址：https://github.com/shuzijun/leetcode-editor   大神做的良心插件，非常好用，爱了爱了
```
class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        List<Integer> result = new ArrayList<>();
        if (words.length == 0) { return result; }
        Map<String, Integer> wordMap= new HashMap<>(words.length);
        int wordLength = words[0].length();
        int windowLength = words.length * wordLength;
        for (String word : words) {
            if (wordMap.containsKey(word)) { wordMap.put(word, wordMap.get(word) + 1); }
            else { wordMap.put(word, 1); }
        }
        Map<String, Integer> window= new HashMap<>(words.length);
        for(int i = 0; i < s.length(); i ++) {
            if (s.substring(i).length() < windowLength) { return result; }
            // 向 window 里添加 word
            for(int j = i; j <= windowLength - wordLength + i; j += wordLength) {
                String hasWord = s.substring(j, j + wordLength);
                if (window.containsKey(hasWord)) { window.put(hasWord, window.get(hasWord) + 1); }
                else { window.put(hasWord, 1); }
            }
            // 判断
            if(window.equals(wordMap)) { result.add(i); }
            window.clear();
        }
        return result;
    }
}

```
