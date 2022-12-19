### 解题思路
哈希计数

### 代码

```java
class Solution {
        public  int countCharacters(String[] words, String chars) {
        HashMap<Character, Integer> charMap = new HashMap<>();
        HashMap<Character, Integer> wordMap = new HashMap<>();
        int ans = 0;
        //初始化charMap
        for(char c : chars.toCharArray()){
            charMap.put(c, charMap.getOrDefault(c, 0)+1);
        }

        wordLoop: for(String word: words){
            wordMap.clear();//清除上一次的记录
            for(char tmp : word.toCharArray()){ //建立wordMap
                wordMap.put(tmp, wordMap.getOrDefault(tmp, 0)+1);
            }

            for(char c: wordMap.keySet()){ //对面charMap和wordMap
                if(!charMap.containsKey(c) || charMap.get(c)<wordMap.get(c)){
                    continue wordLoop;
                }
            }
            ans+=word.length();
        }

        return ans;
    }
}
```