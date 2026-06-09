照旧记录一下做题思路。
拿到题第一反应就是首尾指针了，因为题目需要前后互换，刚好把数组分为两个部分。首指针只找偶数，尾指针只找奇数，找到后互换就行。
下面给出第一次提交的代码：
```java
class Solution {
    public int[] exchange(int[] nums) {
        int prev = 0;
        int last = nums.length - 1;
        while (prev < last) {
            while (nums[prev] % 2 != 0) {
                prev++;
            }
            while (nums[last] % 2 == 0) {
                last--;
            }
            if (last != prev) {
                int tmp = nums[prev];
                nums[prev] = nums[last];
                nums[last] = tmp;
            }
        }
        return nums;
    }
}
```
跑起来也没啥问题，自己也没发现什么问题。所以说还是在考虑特殊情况这种细节上做得没有大佬们好。
因为首尾指针在循环中是可能超出边界的，当再次进行循环条件判断的时候明显会抛出数组越界异常，理应如下：
```java
class Solution {
    public int[] exchange(int[] nums) {
        int prev = 0;
        int last = nums.length - 1;
        while (prev < last) {
            while (prev < last && nums[prev] % 2 != 0) {
                prev++;
            }
            while (prev < last && nums[last] % 2 == 0) {
                last--;
            }
            if (last != prev) {
                int tmp = nums[prev];
                nums[prev] = nums[last];
                nums[last] = tmp;
            }
        }
        return nums;
    }
}
```
当然，希望下次代码除了正确也可以更简洁，或者用上位运算啥的。会了的东西永远不记得用也太真实了。