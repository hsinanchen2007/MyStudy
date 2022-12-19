### 解题思路
暴力逐个遍历即可，要注意的是整数溢出问题
以正数为例
溢出发生在temp = ans*10 + e处
若ans > Integer.MAX_VALUE/10，一定会溢出
若ans == Integer.MAX_VALUE / 10 而且e > Integer.MAX_VALUE % 10，一定会溢出
Time O(n)
Space O(1)

### 代码

```java
class Solution {
    public int myAtoi(String str) {
        if(str == null || str.length() == 0)
            return 0;
        int firstNotSp = 0;
        while(firstNotSp < str.length()){
            if(str.charAt(firstNotSp) == ' ')
                firstNotSp++;
            else
                break;
        }
        if(firstNotSp == str.length())
            return 0;
        char temp = str.charAt(firstNotSp);
        if(!(temp == '-' || temp == '+' || (temp <= '9' && temp >= '0')))
            return 0;
        boolean tag = true;
        if(temp == '-' || temp == '+'){
            tag = (temp == '+') ? true : false;
            firstNotSp++;
        }
        int ans = 0;
        for(int i = firstNotSp; i < str.length(); i++){
            if(str.charAt(i) > '9' || str.charAt(i) < '0')
                break;
            int e = str.charAt(i) - '0';
            if(ans > Integer.MAX_VALUE / 10 || (ans == Integer.MAX_VALUE / 10 && e > Integer.MAX_VALUE % 10))
                return tag ? Integer.MAX_VALUE : Integer.MIN_VALUE;
            ans =e + ans * 10;
        }
        return tag ? ans : -ans;
    }
}
```