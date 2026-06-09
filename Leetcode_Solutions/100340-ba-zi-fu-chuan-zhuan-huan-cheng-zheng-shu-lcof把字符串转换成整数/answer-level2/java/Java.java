### 解题思路
判断正负号
进行读取数字
判断溢出
计算
结果返回

### 代码

```java
class Solution {
    /**
     * mark :  表示正负号
     * flag : 表示是否开始处理 数字、+号
     * pop : 表示进位
     * @param str
     * @return
     */
    public int strToInt(String str) {
        if(str == null || str.length() == 0) return 0;
        //标记正负号
        int mark = 0;
        //标志取到的第一位是否是数字
        boolean flag = false;
        //存放最终输出的数值
        int number = 0;
        String newStr = str.trim();
        char[] chars = newStr.toCharArray();
        //判断是否为空
        if(chars.length == 0) return 0;
        //若为负号
        if(chars[0] == '-') mark = 1;
        for(int i = mark;i < chars.length;i++){
            //已经判定为负号，却又遇到正号
            if (mark == 1 && chars[i] == '+' && flag == false) {
                return 0;
            }else if (mark == 1 && chars[i] == '+' && flag == true){
                break;
            }
            if(mark == 0 && chars[i] == '+' && flag == false){
                flag = true;
                //第一次遇到正号
                continue;
            }else if (mark == 0 && chars[i] == '+' && flag == true) {
                //第二次遇到正号
                break;
            }
            //判定
            if((chars[i] < '0' || chars[i] > '9') && flag == false){
                //当第一位为非0 - 9
                return 0;
            }else if((chars[i] < '0' || chars[i] > '9') && flag == true){
                break;
            }else{
                int pop = chars[i] - '0';
                //进行最大值的判断与溢出判断
                if ((number > Integer.MAX_VALUE/10 ||
                        (number == Integer.MAX_VALUE/10 && pop > Integer.MAX_VALUE % 10)) && mark == 0)
                    return Integer.MAX_VALUE;
                if ((-number < Integer.MIN_VALUE/10 ||
                        (-number == Integer.MIN_VALUE/10 && -pop < Integer.MIN_VALUE % 10)) && mark == 1)
                    return Integer.MIN_VALUE;
                //char[i]-'0'为转成数字
                number = number * 10 + pop;
                flag = true;
            }
        }
        return mark != 1?number:-number;
    }
}
```