
### 代码

```java
class Solution {
    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums == null || nums.length == 0) {
            return new int[0];
        }
        
        int n = nums.length;
        int[] result = new int[n - k + 1];
        int maxIndex = -1;
        for (int i = 0; i <= n - k; i++) {
            if (maxIndex < i) {
                maxIndex = i;
                for (int j = i + 1; j < i + k; j++) {
                    if (nums[j] > nums[maxIndex]) {
                        maxIndex = j;
                    }
                }
            } else if (nums[i + k - 1] > nums[maxIndex]) {
                maxIndex = i + k - 1;
            } // 判断新增的元素是否更大，新增元素是i+k-1对应的元素！！！！

            result[i] = nums[maxIndex];
        }

        return result;
    }
}
```