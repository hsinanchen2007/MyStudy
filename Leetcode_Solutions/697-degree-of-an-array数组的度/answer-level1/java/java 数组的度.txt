思路：
遍历数组，每个数组的元素作为map的key，map的value是一个数组，数组里面有三个值，第一个值是度，第二个值时开始位置，第三个值是长度。
```
class Solution {
    public int findShortestSubArray(int[] nums) {
        int length = nums.length;
        Map<Integer, int[]> map = new HashMap<>();
        int max = 0;
        int len = 0;
        for (int i = 0; i < length; i++) {
            int[] tmp;
            if (null == (tmp = map.get(nums[i]))) {
                // 度，开始位置，长度
                map.put(nums[i], tmp = new int[]{1, i, 1});
            } else {
                tmp[0] = tmp[0] + 1;
                tmp[2] = i - tmp[1] + 1;
            }
            if (tmp[0] > max || (tmp[0] == max && tmp[2] < len)) {
                max = tmp[0];
                len = tmp[2];
            }
        }
        return len;
    }
}
```
