```
class Solution {
    public String toHex(int num) {
		 if(num==0)return "0";		 
	     String[] arr = {"0","1","2","3","4","5","6","7","8","9","a","b","c","d","e","f"};
	     String s = "";
		 for(int i = 1;i <=8;i++){
			 s = arr[(num&15)] + s;
			 num>>>=4;
			 if(num==0)break;
		 }
	     return s;
    }
}
```
要点: 
    1.二进制转十六进制  从二进制低位起每四个数转换成一个十六进制数.
    2.数字15的二进制值为 1111, 任何数与(&)15的结果都是该数字的最低4位二进制数的值.
    3.>>>无符号右移,高位补0,当数值为0时,循环结束