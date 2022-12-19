### 解题思路

双指针同时从左右两端逐渐向中间逼近求解

左右两端分别成对儿找到元音字母时交换位置

当left>=right时，循环结束

建议刷题写代码的大神们，变量命名规范些，复杂的算法写下注释，提高代码的可读性，这样我这种菜鸟就不用那么费劲的读大神们的代码了，大家共同进步，算法太有趣了


### 代码

```java
class Solution {
    public String reverseVowels(String s) {
        char[] inputs = s.toCharArray();
        int left = 0;
        int right = inputs.length - 1;
        char temp;
        while (left < right) {
            while (!isVowel(inputs[left]) && left < right) {
                left++;
            }
            while (!isVowel(inputs[right]) && right > left) {
                right--;
            }
            temp = inputs[right];
            inputs[right--] = inputs[left];
            inputs[left++] = temp;
        }
        return new String(inputs);
    }

    public static boolean isVowel(char ch) {
                return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'
                ||ch=='A'|| ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U';
    }
}
```