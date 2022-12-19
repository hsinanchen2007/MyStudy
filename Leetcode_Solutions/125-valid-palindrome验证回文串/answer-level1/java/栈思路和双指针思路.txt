## 题解思路
判断回文最简单的方式是用栈，思路非常直接。
不那么直接的思路是用双指针。
### 栈思路
把所有的字符推入栈，然后进行数组遍历，每次碰到一个合法字符，就从栈中pop一个字符，比较两者是否相等，如果相等继续，如果不相等这就不是一个合法的回文字符串
### 双指针思路
在字符串头和尾分别放一个指针，两者逼近（头一直跑到往后的第一个合法字符为止，尾一直往前跑到第一个合法的字符为止），判断指针所在位置的字符是否
相等，如果相等那么继续逼近逻辑。这里的细节就是逼近暂停的条件除了头 >= 尾以外还有就是在寻找下一个合法字符的时候，头指针需要小于尾指针。
## 执行结果
如下是双指针的执行结果
![image.png](https://pic.leetcode-cn.com/b947dea4a4d916e1d8713acdd3d27a3dece9e6f5fca1ccd9cc738c64c57c24f6-image.png)
## 代码
### 栈代码：
```
import java.util.Stack;

/**
 * @author michael
 * @Description: 使用栈进行存储
 * @date 2020/1/31 4:59 PM
 */
@SuppressWarnings("Duplicates")
class Solution {
    /**
     * 是否是我们关心的字符，数字或者字母
     * @param alpha
     */
    private boolean isValidAlpha(Character alpha) {
        return Character.isDigit(alpha) || Character.isAlphabetic(alpha);
    }

    public boolean isPalindrome(String s) {
        if (s == null || s.length() == 0) {
            return true;
        }
        Stack<Character> stack = new Stack<>();
        for (Character item : s.toCharArray()) {
            if (isValidAlpha(item)) {
                stack.push(Character.toLowerCase(item));
            }
        }

        for (Character item : s.toCharArray()) {
            if (isValidAlpha(item)) {
                Character alpha = stack.pop();
                Character lowerCaseAlpha = Character.toLowerCase(item);
                if (!lowerCaseAlpha.equals(alpha)) {
                    return false;
                }
             }
        }
        return true;
    }
}
```

### 双指针代码
```
/**
 * @author michael
 * @Description: 使用双指针进行
 * @date 2020/1/31 4:59 PM
 */
class Solution {
    /**
     * 是否是我们关心的字符，数字或者字母
     */
//    private boolean isValidAlpha(Character alpha) {
//        return Character.isDigit(alpha) || Character.isAlphabetic(alpha);
//    }


//    private char toLowerCase(char c) {
//        return Character.toLowerCase(c);
//    }
//
    private char toLowerCase(char c) {
        return (c >= 'A' && c <= 'Z') ? (char) (c  + 'z' - 'Z') : c;
    }

    private boolean isValidAlpha(char c) {
        return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z');
    }

    public boolean isPalindrome(String s) {
        int stringLength = s.length();
        if (s == null || stringLength == 0 || s.trim().equals("")) {
            return true;
        }

        int endIndex = stringLength - 1;
        int startIndex = 0;
        while (startIndex < endIndex) {
            Character alphaStart = toLowerCase(s.charAt(startIndex));
            Character alphaEnd = toLowerCase(s.charAt(endIndex));
            while (startIndex < endIndex && !isValidAlpha(alphaStart)) {
                startIndex++;
                alphaStart = toLowerCase(s.charAt(startIndex));
            }

            while (startIndex < endIndex && !isValidAlpha(alphaEnd)) {
                endIndex--;
                alphaEnd = toLowerCase(s.charAt(endIndex));
            }

            if (alphaStart != alphaEnd) {
                return false;
            }

            startIndex++;
            endIndex--;

        }
        return true;
    }
}
```