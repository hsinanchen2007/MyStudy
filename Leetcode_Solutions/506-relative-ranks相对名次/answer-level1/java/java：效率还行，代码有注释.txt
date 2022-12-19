![image.png](https://pic.leetcode-cn.com/d1ae2bf5d06334de756852a1f1db1faafba4f10c7ba40f2b5064d19185af7b18-image.png)
```
class Solution {
    public String[] findRelativeRanks(int[] nums) {
        String[] res = new String[nums.length];
        // 特殊情况进行处理
        if(nums.length == 1) {
            res[0] = "Gold Medal";
            return res;
        }
        if(nums.length == 2) {
            if(nums[0] > nums[1]) {
                res[0] = "Gold Medal";
                res[1] = "Silver Medal";
            } else {
                res[1] = "Gold Medal";
                res[0] = "Silver Medal";
            }
            return res;
        }
        // 找出最大元素
        int max = nums[0];
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] > max) {
                max = nums[i];
            }
        }
        // 对元素下标进行存储
        // site数组下标为nums[i]的位置上存储的为nums[i]这个数字在nums数组中下标
        int[] site = new int[max + 1];
        for(int i = 0; i < nums.length; i++) {
            site[nums[i]] = i;
        }
        // 数组排序，直接调用Arrays.sort()API也可以
        quickSort(nums, 0, nums.length - 1);
        // 将名次存入数组中
        res[site[nums[nums.length - 1]]] = "Gold Medal";
        res[site[nums[nums.length - 2]]] = "Silver Medal";
        res[site[nums[nums.length - 3]]] = "Bronze Medal";
        int rank = nums.length;
        for(int i = 0; i < nums.length - 3; i++) {
            res[site[nums[i]]] = String.valueOf(rank);
            rank--;
        }
        return res;
    }

    // 快速排序
    public void quickSort(int[] nums, int start, int end) {
        if(start > end) return;
        int baseLine = nums[start];
        int temp;
        int low = start;
        int high = end;
        while(low < high) {
            while(nums[high] >= baseLine && low < high) {
                high--;
            }
            while(nums[low] <= baseLine && low < high) {
                low++;
            }
            if(low < high) {
            temp = nums[low];
            nums[low] = nums[high];
            nums[high] = temp;
            }
        }
        nums[start] = nums[low];
        nums[low] = baseLine;
        quickSort(nums, start, low - 1);
        quickSort(nums, low + 1, end);
    }
}
```

