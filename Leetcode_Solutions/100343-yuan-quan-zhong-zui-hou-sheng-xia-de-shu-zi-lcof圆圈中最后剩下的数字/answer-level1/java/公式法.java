### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lastRemaining(int n, int m) {
        int count = 0;
        for(int i=2;i < n + 1;i++){
            count = (count + m) % i;
        }
        return count;
    }
}
```