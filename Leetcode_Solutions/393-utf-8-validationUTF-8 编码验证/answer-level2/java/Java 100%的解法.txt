
以下解法快过100%的Java提交。思路见代码和注释

```java
class Solution {
    public boolean validUtf8(int[] data) {
        int i=0;
        
        while(i < data.length) {
            // 取得当前的byte，只会是unicode的第一个字节，后面会跳过同个unicode的剩余字节
            byte b = (byte)(data[i] & 0x000000ff);
            int digits;
            //看首位是不是0，如果是则说明是单字节unicode
            if((b & 0x80) == 0) {
                i++;
                continue;
            } else if((b & 0xe0) == 0xc0) {
                //前4位是不是11 10，如果是说明2字节unicode
                digits = 2;
            } else if((b & 0xf0) == 0xe0) {
                //前5位是不是111 10, 成立则是3字节unicode
                digits = 3;
            } else if((b & 0xf8) == 0xf0) {
                //前6位是不是1111 10, 成立则是4字节unicode
                digits = 4;
            } else {
                // 不符合所有情况，非法。
                return false;
            }
            
            //从i 到 data.length - 1共data.length-i个字节小于字节数，非法
            if(data.length - i < digits) {
                return false;
            }
            
            //跳过第一个字节后逐个字节检验是否以10开始, 0xc0=1100 0000, 按位与后如果是1000 0000，则应是0x80
            for(int j = 1;j < digits; j++) {
                if((data[i+j] & 0x000000c0) != 0x80) {
                    return false;
                }
            }
            //跳过字节数，到下一个unicode开始的位置
            i = i + digits;
        }
        
        return true;
    }
}
```

![image.png](https://pic.leetcode-cn.com/5fd7987971d22cffec375a18872dafec9bd1d02dd1014087ac11539c4bf2ac6f-image.png)


