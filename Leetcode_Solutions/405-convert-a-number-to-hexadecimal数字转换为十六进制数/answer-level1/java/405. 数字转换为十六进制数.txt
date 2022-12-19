/**
 * @Project
 * @Author zhaozhen
 * @Email 
 * @Date 2019/9/7
 *
 * 解题思路：java里面有 Integer.toHexString() 但是题目要求自己写 位运算，以4位为粒度进行取数,转化为16进制字符串
 *
 * 如：35 == 0010 0011 = 23
 * 
 * 注意：java中
 *      hex to int Integer.valueOf("12ff",16)
 *      int to hex Integer.toHexString(35)
 */
```
    public String toHex(int num) {
        char[] hex = "0123456789abcdef".toCharArray();
        String s = new String();
        while(num != 0){
            int end = num&15;
            s = hex[end] + s;
            //无符号右移
            num >>>=4;
        }
        if(s.length() == 0){
            s = "0";
        }

        return s;
    }
```