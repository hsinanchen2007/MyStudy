### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int[] c = new int[26];
        for(char cc : chars.toCharArray()){
            c[cc - 'a'] += 1;
        }
        int res = 0;
        a: for(String word : words) {
            int[] w = new int[26];
            for(char ww :word.toCharArray()){
                w[ww - 'a'] += 1;
            }
            for(int i=0; i<26; i++){
                if(w[i] > c[i])
                    continue a;
            }
            res += word.length();
        }
        return res;
    }
}
```