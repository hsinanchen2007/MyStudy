**思路：**  这道题用到了异或以及位移
```
异或：符号表示为^,二进制运算遵循两位不相同进1位的规则，如右示  0^0 = 0,1^0 = 1,0^1 = 1,1^1=0. 
```
所以数字x和数字y异或得到的数字，二进制位是1表示两数不同，计算个数就得到答案。
利用一个获取字节的位的技巧——&0x01。高位就会变成0，只剩下最低位。
```java []
public int hammingDistance(int x, int y) {
       int i = x ^ y;
       byte[] bytes1 = new byte[32];
       int index = 0;int num = 0;
       for(int j = 31;j>0;j--){
           byte b = (byte)(i&0x01);
           if(b==0x01){
               num++;
           }
           i = i>>1;
       }
       return num;
   }
```


