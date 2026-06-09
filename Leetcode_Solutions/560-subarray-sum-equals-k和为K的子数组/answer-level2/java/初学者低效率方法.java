### 解题思路
思路，从index一路往后找，发现有和为target的情况count++
注意负数等情况，第一遍做的就是错的，第一遍代码如下：

```
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            int index = i;
            while (sum < k && index < nums.length) {
                sum += nums[index++];
            }
            if (sum == k) {
                count++;
            }
        }
        return count;
    }
```
这个用例过不了：
{-1,2，-1,2,1} target 是1的情况

后来改成如下：
一直遍历到末尾，只要满足就加1 ，顺利通过
### 代码

```java
class Solution {
    public int subarraySum(int[] nums, int k) {
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            int sum = 0;
            int index = i;
            while (index < nums.length) {
                sum += nums[index++];
                if (sum == k) {
                    count++;
                }
            }
        }
        return count;
    }
}
```