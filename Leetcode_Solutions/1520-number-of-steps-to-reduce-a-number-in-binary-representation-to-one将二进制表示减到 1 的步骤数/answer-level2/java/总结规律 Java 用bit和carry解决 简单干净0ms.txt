首先，看下表

![Screen Shot 2020-04-05 at 5.12.37 PM.png](https://pic.leetcode-cn.com/2700978f274bd97924368432eea479c7d3ab85a82e32c11d30c1708beeb8fb89-Screen%20Shot%202020-04-05%20at%205.12.37%20PM.png)

**总结一下**
第一第四情况下的操作为：1. 右移一位 2. carry值不变 3.操作数+1
第三第四情况下操作为：1. 右移一位 2.carry变1 3. 操作数+2（自己+1一次，接着情况一+1一次）

所以当我们用char array来从后向前遍历s中当字符时，仅需要关注第三第四情况。
还有一个特殊情况为，当遍历到首位的时候，如果此刻carry为0，就需要停止任何操作，break循环

代码如下
```java
class Solution {
    public int numSteps(String s) {
        if(s.length() == 0) return 0;
        int ans = 0;
        int carry = 0;

        for(int i = s.length() - 1; i >= 0; i--){
            if(i == 0 && carry == 0) break;
            if(s.charAt(i) - '0' != carry){
                carry = 1;
                ans += 1;
            }
            ans += 1;
        }
        return ans;
        //经评论提醒，发现并不需要一个chararray，虽然改了内存消耗也没有变少多少，还是改一下为好
        // char[] array = s.toCharArray();
        // for(int i = array.length - 1; i >= 0; i--){
        //     if(i == 0 && carry == 0) break;
        //     if(array[i] - '0' != carry){
        //         carry = 1;
        //         ans += 1;
        //     }
        //     ans += 1;
        // }
    }
}
```
