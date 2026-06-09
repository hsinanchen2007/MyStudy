### 解题思路
此处撰写解题思路
递推公式
### 代码

```java
class Solution {
    public int sumNums(int n) {
        return (int)(n+Math.pow(n,2))>>1;
    }
}
```