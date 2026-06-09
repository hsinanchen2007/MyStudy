### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public boolean isPowerOfTwo(int n) {
        double num=(double)n;
        while(num>1){
            num/=2;
        }
        return num==1;
    }
}
```