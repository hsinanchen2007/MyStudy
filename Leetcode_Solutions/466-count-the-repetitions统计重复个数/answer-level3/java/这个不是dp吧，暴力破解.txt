### 解题思路
这个不是dp吧，官方的抽屉原理没看明白

### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */
public class Solution {
    public int getMaxRepetitions(String s1, int n1, String s2, int n2) {
        /**
         * 遍历是s1，一个一个来，然后找到起点和终点分别位于两个字符串中，则找到k和m，然后做除法
         * 这根本不是dp啊，就是非常简单的数学啊
         * 就是代码写起来不好写
         */
        int index = 0;
        int count1 = 0;
        int count2 = 0;
        while (count1 < n1) {
            for (int i = 0; i < s1.length(); i++) {
                if (s1.charAt(i) == s2.charAt(index)) {
                    if (index == s2.length() - 1) {
                        count2++;
                        index = 0;
                    } else {
                        index++;
                    }
                }
            }
            count1++;
        }
        return count2 / n2;
    }
}

```