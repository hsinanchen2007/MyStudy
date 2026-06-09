你永远想不到我输入的字符串有多么猥琐，边界处理非常恶心
主要是3个边界：
1. 前导空格的去除
2. 正负号的判断
3. 遍历过程中遇到非数字字符
```
class Solution {
    public int myAtoi(String str) {
        if(str == null || str.length() == 0) return 0;
        long res = 0;
        int i = 0;
        boolean isActive = true;
        //去除前导空格
        while (i < str.length() && str.charAt(i) == ' ') i++;
        char[] array = str.toCharArray();
        if(i == str.length()) return (int)res;
        //判断第一位是否为符号位
        if(array[i] == '-' || array[i] == '+'){
            if(array[i] == '-') isActive = false;
            i += 1;
        }else if(array[i] - '0' > 9 || array[i] - '0' < 0) return isActive ? (int) res : (int) res * -1;
        for ( ; i < array.length; i++) {
            //判断是否为数字
            int number = array[i] - '0';
            if(number < 0 || number > 9)
                return isActive ? (int) res : (int) res * -1;
            else
                res = res * 10 + number;
            if(isActive && res > Integer.MAX_VALUE) return Integer.MAX_VALUE;
            if(!isActive && res * -1 < Integer.MIN_VALUE) return Integer.MIN_VALUE;
        }
        return isActive ? (int) res : (int) res * -1;
    }
}
```
![atoi字符串转整数.wmv](3e1b8d99-cc30-4acc-98f6-c37754313e68)
