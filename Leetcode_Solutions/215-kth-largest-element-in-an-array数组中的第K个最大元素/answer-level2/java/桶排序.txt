### 解题思路
此处撰写解题思路

### 代码

```java
        class Solution {
            public int findKthLargest(int[] nums, int k) {
                  int min = Integer.MAX_VALUE;
            int max = Integer.MIN_VALUE;
            int len = nums.length;
            for (int i = 0; i < len; i++) {
                min = Math.min(min, nums[i]);
                max = Math.max(max, nums[i]);
            }
            int offset = max - min + 1;
            int[] bucket = new int[offset];
            for (int i = 0; i < len; i++) {
                bucket[nums[i] - min]++;
            }
            int index = offset - 1;
            int indexK = 0;
            while (indexK < k) {
                if (bucket[index] != 0) {
                    indexK = indexK + bucket[index];
                    if (indexK>=k){
                        return min+index;
                    }
                }
                index--;
            }
            return min + index;
            }
        }
```
建桶，逐个放入，从最大桶找起，找到第K个出来
Space O(N)
Time O(N)