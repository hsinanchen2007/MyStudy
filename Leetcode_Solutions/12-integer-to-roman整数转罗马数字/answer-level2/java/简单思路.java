### 解题思路
分单个数字，简单替换法

### 代码

```java
// package com.leetcode.practices.integerToRoman;

import java.util.ArrayList;

public class Solution {
    public String intToRoman(int num) {
        ArrayList<Integer> numDigit = new ArrayList<>();
        while (num / 10 != 0) {
            numDigit.add(num % 10);
            num = num / 10;
        }
        numDigit.add(num);

        StringBuilder stringBuilder = new StringBuilder();

        for (int i = 0; i < numDigit.size(); i++) {
            stringBuilder.insert(0, handleRoman(i, numDigit.get(i)));
        }

        return stringBuilder.toString();
    }

    String handleRoman(int decimalIndex, int value) {
        if (decimalIndex == 0) {
            return handleRomanOrigin(value);
        } else if (decimalIndex == 1) {
            return handleRomanOrigin(value).replaceAll("X","C").replaceAll("V", "L")
                    .replaceAll("I", "X")
                    ;
        } else if (decimalIndex == 2) {
            return handleRomanOrigin(value).replaceAll("X","M").replaceAll("V", "D")
                    .replaceAll("I", "C");
        } else if (decimalIndex == 3) {
            StringBuilder thou = new StringBuilder();
            for (int i = 0; i < value; i++) {
                thou.append("M");
            }
            return thou.toString();
        }
        return "";
    }

    String handleRomanOrigin(int value) {
        switch (value) {
            case 1:
                return "I";
            case 2:
                return "II";
            case 3:
                return "III";
            case 4:
                return "IV";
            case 5:
                return "V";
            case 6:
                return "VI";
            case 7:
                return "VII";
            case 8:
                return "VIII";
            case 9:
                return "IX";
            default:
                return "";
        }
    }
}

```