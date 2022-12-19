### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int reverse(int x) {
        int b=0;
        while (x!=0){
            int a=x%10;
            int res=b;
            if (b==0 && a==0){
            }
            else{
                b=b*10+a;
            }
            x=x/10;
            if ((b-a)/10!=res){ //当加了一位后得到的数反推回去不等于没加时的数，说明整数溢出发生，于是返回0.
                return 0;
            }
        }
        return b;

    }
}
```