### 解题思路
很普通的思路，似乎遇到了bug，，，1ms(＠_＠; )

### 代码

```java
class Solution {
    public int reverse(int x) {
     
            long temp=0;
            for(int i=0;x!=0;x=x/10){
                temp=temp*10;
                temp+=x%10;
            }
           if(temp>2147483647||temp<-2147483648)
                temp=0;
            return (int)temp;
    }
}
```