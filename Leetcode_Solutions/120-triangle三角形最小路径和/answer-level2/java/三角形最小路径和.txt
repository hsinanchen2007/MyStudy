### 解题思路
仿杨辉三角II，自顶向下，每次遍历从后向前计算

### 代码

```java
class Solution {
    public int minimumTotal(List<List<Integer>> triangle) {
        if (triangle == null) {
            return -1;
        }

        int[] nums = new int[triangle.size()];
        for (int i = 0; i < triangle.size(); i ++) {
            if (i == 0) {
                nums[0] = triangle.get(0).get(0);
                continue;
            }
            
            List<Integer> list = triangle.get(i);
            for (int j = i; j >= 0; j --) {
                if (j == i) {
                    nums[j] = list.get(j) + nums[j-1];
                } else if (j == 0) {
                    nums[j] += list.get(0);
                } else {
                    nums[j] = list.get(j) + Math.min(nums[j], nums[j-1]);
                }
            }
        }
        
        int min = 10000000;
        for (int num : nums) {
            if (num < min) {
                min = num;
            }
        }

        return min;
    }
}
```