最简单的按照逻辑进行处理。 从尾部开始，每个字符进行分析。 将转换的阿拉伯数字相加。
同时针对题中六种情况单独处理
当然，罗马数字，也可以按需通过HashMap进行存储
```
/*
 * @lc app=leetcode.cn id=13 lang=java
 *
 * [13] 罗马数字转整数
 */
class Solution {
    public int romanToInt(String s) {
        int result = 0;
        char numC , temp;
        for(int index = s.length() - 1 ; index != -1 ; index -- ){
            numC = s.charAt(index);
            if(numC == 'I'){
                result += 1;
            }
            if(numC == 'V'){
                result += 5;
                if(index != 0 && s.charAt(index - 1) == 'I'){
                    result --;
                    index --;
                }
            }
            if(numC == 'X'){
                result += 10;
                if(index != 0 && s.charAt(index - 1) == 'I'){
                    result --;
                    index --;
                }
            }
            if(numC == 'L'){
                result += 50;
                if(index != 0 && s.charAt(index - 1) == 'X'){
                    result -= 10;
                    index --;
                }
            }
            if(numC == 'C'){
                result += 100;
                if(index != 0 && s.charAt(index - 1) == 'X'){
                    result -= 10;
                    index --;
                }
            }
            if(numC == 'D'){
                result += 500;
                if(index != 0 && s.charAt(index - 1) == 'C'){
                    result -= 100;
                    index --;
                }
            }
            if(numC == 'M'){
                result += 1000;
                if(index != 0 && s.charAt(index - 1) == 'C'){
                    result -= 100;
                    index --;
                }
            }
        }
        return result;
    }
}

```