### 解题思路
此处撰写解题思路
![image.png](https://pic.leetcode-cn.com/0b9e2e5878875b00796330cc5965d3409ffd24491e1352c4b2af52a814312f53-image.png)
  * 使用结果字符串
     * 1双层循环，将第一个出现字符计入result,从下一个字符开始到最后一个字符，如果和选中字符不相等，直接跳出第二层循环
     * 2如果循环中选中字符和当前字符相等，将计数值加一，并且将第一层循环中指针向后移动
     * 3直到指针到达字符数组末端

### 代码

```java
class Solution {
    /**
     * 使用结果字符串
     * 1双层循环，将第一个出现字符计入result,从下一个字符开始到最后一个字符，如果和选中字符不相等，直接跳出第二层循环
     * 2如果循环中选中字符和当前字符相等，将计数值加一，并且将第一层循环中指针向后移动
     * 3直到指针到达字符数组末端
     * @param S
     * @return
     */
    public String compressString(String S) {
        String result = "";
        if (S == null) {
            return result;
        }
        char[] chars = S.toCharArray();
        int length = chars.length;
        for (int i = 0; i < length; i++) {
            int num = 1;
            result += chars[i];
            for (int j = i + 1; j < length; j++) {
                if (chars[j] != chars[i]) {
                    break;
                } else {
                    num++;
                    i++;
                }
            }
            result += num;
        }
          if (result.length() >= S.length()) {
            result = S;
        }
        return result;
    }

}
```