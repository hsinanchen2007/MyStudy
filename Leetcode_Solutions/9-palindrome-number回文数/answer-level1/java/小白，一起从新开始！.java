### 解题思路
小白，一起从新开始！

### 代码

```java
class Solution {
    public boolean isPalindrome(int x) {
        if(x<0)return false;//负数直接返回错误
        int count=x;//记录原来的数
        int temp,sum=0;
        //进行倒置
        while(x!=0){
            temp=x%10;
            x/=10;
            sum=sum*10+temp;
        }
        if(sum==count)return true;//与原数进行比较
        return false;
    }
}
```