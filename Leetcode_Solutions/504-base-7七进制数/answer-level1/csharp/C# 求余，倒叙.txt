```
public class Solution {
    public string ConvertToBase7(int num) {
        var ab = "";//记录正负
        var ch = "";//记录专成7进制的字符串
        int result = num;
        if(num == 0){
            return "0";
        }else if(num < 0){
            ab = "-";
            result = Math.Abs(num);//取绝对值
        }
        while(result > 0){
            ch += Convert.ToString(result%7);//转成7进制数字字符串
            result /= 7;
        }
        //倒叙
        char[] arr = ch.ToCharArray();
        Array.Reverse(arr);
        //添加符号
        ab+=new string(arr);
        return ab;
    }
}
```