### 解题思路
有现成的轮子可用。。


### 代码

```java

import java.math.BigInteger;
class Solution {
    public String addBinary(String a, String b) {
        BigInteger aNum =new BigInteger(a,2) ;
        BigInteger bNum =new BigInteger(b,2) ;
        BigInteger ans = aNum.add(bNum);
        String strSum=ans.toString(2);
        return strSum;
    }
}
```