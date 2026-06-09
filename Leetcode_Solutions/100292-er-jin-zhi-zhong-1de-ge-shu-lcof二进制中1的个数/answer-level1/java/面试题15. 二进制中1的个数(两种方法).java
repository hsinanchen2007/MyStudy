### 解题思路

### 法1：原数右移
题目说明了用无符号数字来处理，因此每次和1与一下计数即可。

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count=0;
        while (n!=0){
            if((n&1)==1){
                count++;
            }
            n>>>=1;
        }
        return count;
    }
}
```
### 法2：无需移动
我们可观察发现原数n如果大于0，n-1后最右边的数字1会变成0，最右边的1右边的全部位数取反。假设原数为101100，-1后变成101011。将-1后的数与原数字与一下，可得101000，刚好将最右边的1去除了。原因很简单，0&1=0，而-1操作则是将元素中的最右边的1与其右边的位数全部取反，所以与原数&之后将变成0000了。
```
public int hammingWeight(int n) {
        int count=0;
        while (n!=0){
            count++;
            n=n&(n-1);
        }
        return count;
    }
```

