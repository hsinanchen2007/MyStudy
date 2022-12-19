![F1AE3FC1-2F8E-4F46-B620-6DF0D9EB6DE0.png](https://pic.leetcode-cn.com/20d223ca9371bce5b76f39bc4666a7b9b0040b9ff88a8d21540f24ebdfeaa916-F1AE3FC1-2F8E-4F46-B620-6DF0D9EB6DE0.png)
```
解题思路：
1、考虑到题目要求及和转成int两数相乘可能越界，故采用小学两数相乘思想，一位一位计算相乘；
2、两个字符串相乘，最长长度不超过两个字符串的总长度.
3、定义一个整型数组int[] array=new int[num1.length()+num2.length()]
4、由于在计算时，进位这个在计算时处理太麻烦，于是想着偷懒的原则，
在数组对应位只计算出其累计值，关于进位后面统一处理。
5、最终解题代码如下

public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }
        int len1 = num1.length();
        int len2 = num2.length();
        int len = len1 + len2;
        int[] array = new int[len];
        if (len1 <= len2) {
            multiplyTwoString(num2, num1, array);
        } else {
            multiplyTwoString(num1, num2, array);
        }
        int index = len - 1;
        for (; index >= 0; index--) {
            if (array[index] >= 10) {
                int temp = array[index];
                array[index] = temp % 10;
                array[index - 1] += temp / 10;
            }
        }
        int i = 0;
        StringBuilder sb = new StringBuilder();
        boolean begin = false;
        for (; i < len; i++) {
            if (begin) {
                sb.append(array[i]);
            } else {
                if (array[i] != 0) {
                    sb.append(array[i]);
                    begin = true;
                }
            }
        }
        return sb.toString();
    }

    private void multiplyTwoString(String num1, String num2, int[] array) {
        int len1 = num1.length();
        int len2 = num2.length();
        int len = array.length;
        int i1 = len1 - 1;
        for (; i1 >= 0; i1--) {
            int begin = len - (len1 - i1);
            int numA = num1.charAt(i1) - 48;
            int i2 = len2 - 1;
            for (; i2 >= 0; i2--) {
                int numB = num2.charAt(i2) - 48;
                int value = numA * numB;
                array[begin] += value;
                begin--;
            }
        }
    }
```
