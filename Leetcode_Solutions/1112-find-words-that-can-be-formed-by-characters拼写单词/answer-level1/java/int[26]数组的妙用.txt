### 解题思路
1.根据提示：所有字符均为小写字母，考虑将所有字符串转换为26个长度的字符数组，数组元素的值为当前位置字符出现的次数；
2.比较word字符数组中每个位子上字符出现次数和chars字符数组的大小，如果有任意一个位置上的值大，则说明chars里面的字符不够使用；
3.累加符合要求的word的长度；

### 代码

```java
class Solution {
    public int countCharacters(String[] words, String chars) {
        int sum = 0;
        int[] charsArray = getIntArray(chars);
        for(int i = 0; i < words.length; i++) {
            String word = words[i];
            int[] wordArray = getIntArray(word);
            if(compare(wordArray, charsArray)) {
                sum = sum + word.length();
            }
        }
        return sum;
    }
    
    private boolean compare(int[] wordArray, int[] charsArray) {
        for(int i = 0; i < 26; i++) {
            if(wordArray[i] > charsArray[i]) {
                return false;
            }
        }
        return true;
    }

    private int[] getIntArray(String str) {
        int[] intArray = new int[26];
        for (char c : str.toCharArray()) {
            intArray[c - 'a'] ++;
        }
        return intArray;
    }

}
```