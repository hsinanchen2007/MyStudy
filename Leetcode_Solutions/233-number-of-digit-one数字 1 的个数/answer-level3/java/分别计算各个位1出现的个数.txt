### 解题思路
分别计算个十百千位上1出现的个数。
一般的说如XYZW这种数,计算Y位置上1出现的个数。
有这样的规律，01ZW,21ZW,31ZW...(X-1)1ZW。共X次,因为每次X位置对应Y位置上的1,ZW
必须变100次,Y位置上的1才会变为2;
故有第一部分的公式n/(k*10)*k,k是位权。
第二部分X000到XYZW这段数中Y位置1出现的个数
这部分是一个分段函数,最小值1出现的次数为0,最大值出现的次数就是位权的次数
还有一种比如X176,出现了176-100+1次。
得出Math.min(Math.max(n%(k*10)-k+1,0),k)

### 代码

```java
import java.lang.Math;
class Solution {
    public int countDigitOne(int n) {

        long k=1;
        int count=0;
        while(k<=n){
            count+=n/(k*10)*k+Math.min(Math.max(n%(k*10)-k+1,0),k);
            k*=10;
        }

        return count;
    }
}
```