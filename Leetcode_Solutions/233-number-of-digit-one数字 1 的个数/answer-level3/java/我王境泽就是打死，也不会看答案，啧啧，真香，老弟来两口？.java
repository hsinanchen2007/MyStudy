### 解题思路
这种题目不是算法题目，而是数学题目，你妹的

### 代码

```java
class Solution {
    public int countDigitOne(int n) {
        int sum = 0;
        for(long i=1;i<=n;i*=10){
            long div = i*10;
            sum += (n/div) * i + Math.min(Math.max(n % div -i+1, 0),i);
        }
        return sum;
    }
}
```