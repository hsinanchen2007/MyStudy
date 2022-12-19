### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
         int res = 0;
        for (int i = 0; i < words.length; i++) {
            if (isContainsWord(chars,words[i])) {
                res+=words[i].length();
            }
        }
        return res;
    }

    // chars 如果包含s ，返回true
    public boolean isContainsWord(String chars,String s) {
        // 都只有小写英文字母
        int[] array = new int[26];
        for (int i = 0; i < chars.length(); i++) {
            array[chars.charAt(i) - 'a']++;
        }

        for (int j = 0; j < s.length(); j++) {
            char temp = s.charAt(j);
            if (array[temp - 'a'] == 0) {
                return false;
            }
            array[temp - 'a']--;
        }

        return true;

    }
}
```很简单，循环遍历使用数组判断是否包含包含另一个所有的字母即可