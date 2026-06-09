### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int add(int a, int b) {
        while(b!=0)
        {
            int plus=(a^b);
            b=((a&b)<<1);
            a=plus;
        }
        return  a;
    }
}
```