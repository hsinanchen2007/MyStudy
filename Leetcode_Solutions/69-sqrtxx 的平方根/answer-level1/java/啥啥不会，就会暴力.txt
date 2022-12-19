### 解题思路
![QQ截图20200318165628.jpg](https://pic.leetcode-cn.com/121cf4314a1a5ca0ac804f04760cb58a32bdcd3445f4207512133f2519e55532-QQ%E6%88%AA%E5%9B%BE20200318165628.jpg)

### 代码

```java
class Solution {
    public int mySqrt(int x) {
        long i = 0L;
        while (i * i <= x) {
            i++;
        }
        return (int) (i - 1);
    }
}
```