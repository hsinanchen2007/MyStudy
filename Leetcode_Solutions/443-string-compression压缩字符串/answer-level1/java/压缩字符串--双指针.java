我看到很多人抱怨题目要求返回长度但是输出的却是数组，一开始我也是懵逼的，强调一下这里解出题目的正确做法是直接修改传递进来的数组
```java
class Solution {
    // 双指针
    public int compress(char[] chars) {
        // 数组的长度为1，不需要压缩
        if (chars.length == 1) {
            return 1;
        }
        // 当前的字符
        char currentChar = chars[0];
        // 当前字符的重复数量
        int count = 1;
        // 最后修改元素的索引
        int index = -1;
        for (int i = 1, length = chars.length; i <= length; i++) {
            // 遍历到的新字符不等于当前字符或者是遍历到末尾
            if (i == length || chars[i] != currentChar) {
                // 上次修改字符的下一个字符修改为当前字符
                chars[++index] = currentChar;
                if (count >= 10) {
                    // 将count编程字符并循环插入
                    char[] countCharArray = String.valueOf(count).toCharArray();
                    for (int j = 0, len = countCharArray.length; j < len; j++) {
                        chars[++index] = countCharArray[j];
                    }
                } 
                // count的数量为1的时候不需要压缩
                else if (count != 1) {
                    chars[++index] = (char) (count + '0');
                }
                // 如果这次遍历到的是末尾则结束循环
                if (i == length) {
                    break;
                }
                // 将新字符赋值给当前字符
                currentChar = chars[i];
                // 当前字符的数量重置为1
                count = 1;
            } else {
                // 重复字符，数量加一
                count++;
            }
        }
        // 由于index是上次修改字符的索引，要求返回的是压缩后端数组的长度，因此加一
        return index + 1;
    }    
}
```
