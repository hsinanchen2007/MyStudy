### 解题思路
举例501  511  521  说明问题：
① 501在十位上：
501十位 0 ，所以高位 5只能取0~4 ，此时十位才能取1，个位任意取0~9，共50种
② 511在十位上：
511 十位1，所以高位 5只能取0~4 ，此时十位才能取1，个位任意取0~9，共50种，另外当十位取1的时候，低位为1因此可以取到一个数字511，再加上原本的510，共52种。
③ 521在十位上：
521十位2，所以高位5可以取0~5，此时十位取1，个位任意取，共60种

### 代码

```java
class Solution {
    public int countDigitOne(int n) {
        //求每个位的数字所用
        int index = 1;
        //记录1的个数
        int count = 0;
        int high = n,cur = 0,low = 0;
        //由于high = n /(index*10) 中index *10 很容易越位
        //特修改如下
        while(high > 0){
            high /= 10;
            cur = (n / index) % 10;
            low = n - (n / index) * index;
            //以下是计算的公式
            if(cur == 0) count += high * index;
            if(cur == 1) count += high * index + low + 1;
            if(cur > 1) count += (high+1) * index;
            index *= 10;
        }
        return count;
    }
}
```