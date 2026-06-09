### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int reverse(int x) {
        //两种情况 int超过  +-2^31会溢出   不超过2^31即可    其次是 正负号的处理
        int rev = 0;
            while(x != 0){
                int newrev = rev*10 + x%10;    //x *10 +y = x'    个位数就是 x % 10
                if((newrev-x%10)/10 != rev) return 0;   
                //此处
                rev = newrev;
                x = x/10;
            }
            
        return rev;

    }
}
```