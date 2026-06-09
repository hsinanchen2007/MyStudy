```
class Solution {
    public int myAtoi(String str) {
        char[] cArray = str.toCharArray();
        // 符号位
        char sign = '+';
        // 转换为整数后的除符号位部分
        int sum = 0;
        // 标记是否开始寻找
        boolean flag = false;
        for(int i = 0;i < cArray.length;i++){
            if(cArray[i] == ' '){
                if(flag){
                    break;
                }
                continue;
            }
            int n = cArray[i] - '0';
            if(cArray[i] == '-' || cArray[i] == '+'){
                if(flag){
                   break; 
                }
                sign = cArray[i];
                flag = true;
            }
            else if(n >= 0 && n <= 9){
                flag = true;
                // 边界条件判断
                if(sign == '+'){
                    if((Integer.MAX_VALUE - n)/10 >= sum){
                        sum *= 10;
                        sum += n;
                    }
                    else{
                        return Integer.MAX_VALUE;
                    }
                }
                else{
                    if((Integer.MIN_VALUE + n)/-10 >= sum){
                        sum *= 10;
                        sum += n;
                    }
                    else{
                        // 当最后sum是Integer.MIN_VAULE的绝对值时（即2147483648,这个数溢出了），从这里结束，正好也满足。
                        return Integer.MIN_VALUE;
                    }
                }
            }
            else
                break;
        }
        // 符号位判断是否要转换为负数
        if(sign == '-'){
            sum = 0 - sum;
        }
        return sum;
    }
}
```
