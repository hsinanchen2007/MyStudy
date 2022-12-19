【题目】:二进制数相邻的两个位数是否永不相等

【思路】:Integer.toBinaryString转成二进制字符串，然后对字符检验。

![image.png](https://pic.leetcode-cn.com/2c069082e5eb56ebdb10625a3f7ad95a2608454c6e1d439008c56b7f18588069-image.png)
```
public static boolean hasAlternatingBits(int n) {
        String ans=Integer.toBinaryString(n);
        char temp='0';
        for(char c:ans.toCharArray()) {
        	if(c==temp) return false;
        	else temp=c;
        }
        return true;
    }
```
