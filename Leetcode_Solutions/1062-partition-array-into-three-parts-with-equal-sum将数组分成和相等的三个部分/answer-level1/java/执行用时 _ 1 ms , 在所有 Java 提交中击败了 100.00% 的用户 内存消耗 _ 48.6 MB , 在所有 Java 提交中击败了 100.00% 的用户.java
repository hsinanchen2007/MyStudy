### 解题思路
emm..不知道为什么双百，是我想简单了？这题首先求解所有的数的和，平均为三份，除不尽，不符合条件，直接false,除的尽，我们把sum三等分，i从0开始，依次遍历并求和，如果等于sum/3,立刻跳出循环，同时i+1指向下一个地址，如果i已经达到最右端，那么不可能三等分，直接返回false，下面两段类似，三段全部取完，如果符合条件，我们返回ture，其他任何情况下都是false，代码如下，尽量写得很清楚了。

### 代码

```java
class Solution {
    public boolean canThreePartsEqualSum(int[] A) {
        int sum = 0;
        for(int i = 0;i<A.length;i++) {
            sum+=A[i];
        }
        if(sum%3!=0) return false;
        sum = sum/3;
        int i = 0;
        int a = 0;
        for(;i<A.length;i++) {
            a+=A[i];
            if(a==sum) {
                break;
            }
        }
        a=0;
        if(i==A.length) return false;
        for(i++;i<A.length;i++) {
            a+=A[i];
            if(a==sum) {
                break;
            }
        }
        if(i==A.length) return false;
        a=0;
        for(i++;i<A.length;i++) {
            a+=A[i];
            if(a==sum) {
                break;
            }
        }
        if(i==A.length) return false;
        return true;

    }
}
```