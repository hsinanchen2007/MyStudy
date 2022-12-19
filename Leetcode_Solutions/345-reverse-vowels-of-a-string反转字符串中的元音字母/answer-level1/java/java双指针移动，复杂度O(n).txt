### 解题思路
左指针从0开始，如果左指针字符不是元音，向右移动，如果左指针字符是元音，判断右指针；
右指针从len-1开始，如果右指针字符不是元音，向左移动，如果右指针是元音，和左指针交换字符，并左移右指针，然后右移左指针；
当左指针位置大于等于右指针位置，结束。
### 代码

```java
class Solution {
  private char[] vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

    private boolean isVowel(char c) {
        for (char tem : vowels) {
            if (c == tem) {
                return true;
            }
        }
        return false;
    }

    public String reverseVowels(String s) {
        int left = 0;
        int right = s.length() - 1;
        char[] chars = s.toCharArray();
        char tem = '0';
        while (left < right) {
            if (isVowel(tem)) {
                char c = chars[right];
                if (isVowel(c)) {
                    chars[right] = tem;
                    chars[left] = c;
                    tem = '0';
                    right--;
                    left++;
                } else {
                    right--;
                }
            } else {
                char c = chars[left];
                if (isVowel(c)) {
                    tem = c;
                } else {
                    left++;
                }
            }
        }
        return new String(chars);
    }
}
```