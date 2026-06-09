### 解题思路
此处撰写解题思路

### 代码

```java
/*
 * Copyright (c) 2020
 * @Author:xiaoweixiang
 */
public class Solution {
    public  String convert(String s, int numRows) {
                if (numRows == 1) {
            return s;
        }
        int cul = 0;
        int index = 0;
        int len = s.length();
        while (index < s.length()) {
            if (index + numRows <= len) {
                cul++;
                index += numRows;
            } else {
                cul++;
                break;
            }
            if (index + numRows - 2 <= len) {
                cul += numRows - 2;
                index += numRows - 2;
            } else {
                cul += len - index;
                break;
            }
        }

        // System.out.println("cul = " + cul);

        char[][] chars = new char[numRows][cul];
        for (int i = 0; i < chars.length; i++) {
            for (int j = 0; j < chars[0].length; j++) {
                chars[i][j] = '0';

            }
        }
        int ind = 0;
        for (int j = 0; j < chars[0].length; j++) {
            for (int i = 0; i < chars.length; i++) {
                if (ind == len) {
                    break;
                }
                if (j % (numRows - 1) == 0) {
                    chars[i][j] = s.charAt(ind);
                    ind++;
                } else {
                    int k = j % (numRows - 1);
                    chars[numRows - 1 - k][j] = s.charAt(ind);
                    ind++;
                    break;
                }
            }
            if (ind == len) {
                break;
            }
        }
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < chars.length; i++) {
            for (int j = 0; j < chars[0].length; j++) {
                if (chars[i][j] != '0') {
                    builder.append(chars[i][j]);
                }
            }
        }
        return builder.toString();
    }
}

```