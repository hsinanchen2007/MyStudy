### 解题思路
暴力法是每个小白走出江湖的第一个招式
map保存相同长度的集合
通过长度找是否有仅有一个字符差异的字符串，有则true，无则false

### 代码

```java
class MagicDictionary {

    Map<Integer, ArrayList<String>> maps;

    public MagicDictionary() {
        maps = new HashMap<>();
    }

    /**
     * Build a dictionary through a list of words
     */
    public void buildDict(String[] dict) {
        for (String string : dict) {
            maps.computeIfAbsent(string.length(), x -> new ArrayList<>()).add(string);
        }
    }

    /**
     * Returns if there is any word in the trie that equals to the given word after modifying exactly one character
     */
    public boolean search(String word) {
        if (!maps.containsKey(word.length())) {
            return false;
        }
        List<String> list = maps.get(word.length());
        for (int i = 0; i < list.size(); i++) {
            String string = list.get(i);
            if (isMatch(word, string)) {
                return true;
            }
        }
        return false;
    }

    private boolean isMatch(String word, String string) {
        int diff = 0;
        for (int i = 0; i < word.length(); i++) {
            if (word.charAt(i) != string.charAt(i)) {
                diff++;
            }
            if (diff > 1) {
                return false;
            }
        }
         return diff == 1;
    }
}

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary obj = new MagicDictionary();
 * obj.buildDict(dict);
 * boolean param_2 = obj.search(word);
 */
```