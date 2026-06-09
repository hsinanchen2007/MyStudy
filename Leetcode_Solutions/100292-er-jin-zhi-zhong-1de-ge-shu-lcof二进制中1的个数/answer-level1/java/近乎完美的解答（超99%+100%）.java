### 解题思路
通过将n右移与1比较，得到的结果如果是1，则说明这一位是1，于是就让标志位count++，将32位都比较完之后返会count

### 代码

```java
public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        int count=0;
        for(int i=0;i<32;i++)
        {
           if((n>>i&1)==1)
           {
               count++;
           }
        
        
        
        }
        return count;
    }
}
```