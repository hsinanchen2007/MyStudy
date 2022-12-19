### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums2.length; i++) {
            map.put(nums2[i], i);
        }

        int[] results = new int[nums1.length];
        for (int i = 0; i < nums1.length; i++) {
            results[i] = getResult(nums1[i], map, nums2);
        }
        return results;
    }

    private int getResult(int i, Map<Integer, Integer> map, int[] nums) {
        int index = map.get(i);
        int result = -1;
        for (int j = index + 1; j < nums.length; j++) {
            if (nums[j] > i) {
                return nums[j];
            }
        }
        return result;
    }
}
```