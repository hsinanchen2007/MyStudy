### 解题思路
此处撰写解题思路
代码比较child。。。重要的是思路，转换为二进制，4的幂，在二进制上，都为100，10000，1000000，首位为1，0的个数为偶数个。

### 代码

```java
class Solution {
    public boolean isPowerOfFour(int num) {
        if(num==1){
            return true;
        }
        if(num<4){
            return false;
        }
        
        String a=Integer.toBinaryString(num);
        String c=a.substring(1,a.length());
        String d=a.substring(0,1);
        Integer b=Integer.valueOf(c,2);
        if(b==0&&d.equals("1")){
            Integer f=(a.length()-1)%2;
            if(f==0){
                return true;
            }
        }

        return false;
        
    }
}
```