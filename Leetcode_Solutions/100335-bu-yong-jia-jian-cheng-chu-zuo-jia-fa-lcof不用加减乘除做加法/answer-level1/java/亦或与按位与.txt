### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int add(int a, int b) {
        while(b!=0){
            int carry =(a^b);
            b =(a&b)<<1;
            a=carry;
        }
        return a;

    }
}
```