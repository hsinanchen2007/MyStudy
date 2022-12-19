### 解题思路
此处撰写解题思路
MAX记录所有和的最大值，sum记录指针到当前数字时应当取的最大和。
### 代码

```java
class Solution {
    public int maxSubArray(int[] nums) {
        int MAX = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.length; i++ ){
            int tmp = sum + nums[i];
            sum = nums[i] > tmp ? nums[i] : tmp;
            MAX = MAX > sum ? MAX : sum;
        }
        return MAX;
    }
}
```