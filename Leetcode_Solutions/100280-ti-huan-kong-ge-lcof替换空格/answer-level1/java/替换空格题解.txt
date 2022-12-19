### 解题思路
计算原字符串中空格数，数据扩容，双指针。具体请看注释，谢谢大家。

### 代码

```java
class Solution {
    public String replaceSpace(String s) {
        if(s == null || s.length() <= 0) {
            return "";
        }
        char[] str = s.toCharArray();
        int originalLength = str.length;
        //统计空格数量
        int blankNum = 0;
        for(int i = 0; i < originalLength; i++) {
            if(str[i] == ' ') {
                blankNum ++;
            }
        }
        //空格替换成“20%”后的实际长度
        int newLength = originalLength + blankNum * 2;
        //new一个新数组存放替换后的字符串
        char[] newStr = new char[newLength];
        //先把原字符串数据拷贝过来
        for(int j = 0; j < originalLength; j++) {
            newStr[j] = str[j];
        }
        //双指针拷贝。indexOfOriginal指向‘.’所在的位置，indexOfNew指向newStr的最后一个位置
        int indexOfOriginal = originalLength - 1;
        int indexOfNew = newLength - 1;
        //当两个指针指向同一个位置时，替换完毕
        while(indexOfOriginal >= 0 && indexOfNew > indexOfOriginal) {
            if(newStr[indexOfOriginal] == ' ') {
                newStr[indexOfNew--] = '0';
                newStr[indexOfNew--] = '2';
                newStr[indexOfNew--] = '%';
            }else {
                newStr[indexOfNew--] = newStr[indexOfOriginal];
            }
            --indexOfOriginal;
        }
        return String.valueOf(newStr);
    }
}
```