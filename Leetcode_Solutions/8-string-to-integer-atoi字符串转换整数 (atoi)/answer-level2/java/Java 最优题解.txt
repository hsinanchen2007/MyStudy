假想使用插入合格元素的方式获取合格的字符串。  
循环遍历整个字符串，将合格的元素放到新的字符串中，如果遇到一个不合格就立马停止循环，忽略剩余元素
时间复杂度为o(n)  n为字符串的长度
```
class Solution {
    public int myAtoi(String str) {
        //题目虽不会传入null,但为了保险起见做一个字符串非空判断
        if(null == str) return 0;
        //去除掉前后的空格
        String strr = str.trim();
        //存储最终过滤出来的字符串
        String strrr = null;
        //字符串不为空时并且字符串不全是空白字符串时才转换
        if(strr != null && strr.isEmpty() == false){
            char f = strr.charAt(0);
            //判断字符串中的第一个非空格字符是不是一个有效整数字符
            if(f >= '0' && f <= '9' || f == '+'|| f == '-'){
                strrr = strr.substring(0,1); // 把第一位放进去(只能是数字、正负号)
                //这时候循环只要数字，因为正负号只能出现在第一位
                for(int i = 1; i<strr.length();i++){
                    if(strr.charAt(i) >= '0' && strr.charAt(i) <= '9'){
                        strrr = strr.substring(0,i+1);
                    }
                    //这是遇到不符合要求的字符，直接忽略剩余元素
                    else{break;}
                }
            }
        }
        //判断最终字符串是否为空或则只有一个正负号
        if(strrr == null || strrr.equals("+") || strrr.equals("-"))
            //此时strrr是String对象，如果使用==比较则比较的时内存地址
            return 0;
        //最终转换成的数字
        int num = 0;
        //使用异常机制打印结果
        try{
            num = Integer.parseInt(strrr);
        }catch (Exception e){
            if(strrr.charAt(0) == '-')
                return Integer.MIN_VALUE;
            return Integer.MAX_VALUE;
        }
        return num;
    }
}
```