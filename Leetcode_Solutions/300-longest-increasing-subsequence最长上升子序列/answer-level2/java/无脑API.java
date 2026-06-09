### 解题思路
直接Arrays.binarySearch查找，岂不美哉

### 代码

```java
class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] res = new int[nums.length];
        int l = 0;
        for (int num: nums) {
            int index = Arrays.binarySearch(res, 0, l, num);
            index = index < 0? -index - 1: index;
            res[index] = num;
            if (index == l) {
                l++;
            }
        }
        return l;
    }
}
```