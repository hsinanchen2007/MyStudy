### 解题思路
执行用时 :
0 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
43.2 MB
, 在所有 Java 提交中击败了
18.09%
的用户

### 代码
class Solution {
    public int[] searchRange(int[] nums, int target) {
        int l = 0, r = nums.length - 1;
        if (l > r) return new int[]{-1, -1};
        if (l == r) return nums[0] == target ? new int[] {0 , 0} : new int[] {-1, -1};
        int[] rst = new int[]{-1, -1};
        findFirstIndex(nums, l, r, target, rst);
        findLastIndex(nums, l, r, target, rst);
        return rst;
    }

    private void findFirstIndex(int[] nums, int l, int r, int target, int[] rst) {
        if (r < 0) return;
        if (r <= l) {if (nums[r] == target) rst[0] = r; return;}
        int mid = l + (r - l) / 2;
        if (nums[mid] > target) findFirstIndex(nums, l, mid, target, rst);
        else if (nums[mid] < target) findFirstIndex(nums, mid + 1, r, target, rst);
        else { rst[0] = mid; findFirstIndex(nums, l, mid - 1, target, rst); }
    }

    private void findLastIndex(int[] nums, int l, int r, int target, int[] rst) {
        if (l > nums.length - 1) return;
        if (l >= r) {if(nums[l] == target) rst[1] = l; return;}
        int mid = l + (r - l) / 2;
        if (nums[mid] > target) findLastIndex(nums, l, mid, target, rst);
        else if (nums[mid] < target) findLastIndex(nums, mid + 1, r, target, rst);
        else { rst[1] = mid; findLastIndex(nums, mid + 1, r, target, rst); }
    }
}
