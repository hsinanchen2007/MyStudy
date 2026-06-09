```
package ZJM_35_搜索插入位置;

public class Main {
    public static void main(String[] args) {
        int[] nums1 = {1, 3, 5, 6};
        int val1 = 5;

        int[] nums2 = {1, 3, 5, 6};
        int val2 = 2;

        int[] nums3 = {1, 3, 5, 6};
        int val3 = 7;

        int[] nums4 = {1, 3, 5, 6};
        int val4 = 0;

        Solution solution = new Solution();
        System.out.println(solution.searchInsert(nums1, val1));
        System.out.println(solution.searchInsert(nums2, val2));
        System.out.println(solution.searchInsert(nums3, val3));
        System.out.println(solution.searchInsert(nums4, val4));
    }
}

class Solution {
    public int searchInsert(int[] nums, int target) {
        int temp = -1;

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] == target) {
                return i;
            }
            if (nums[i] < target) {
                temp = i;
            }
        }

        return temp + 1;
    }
}

/**
 * 难得一遍过秒题，本题在循环中带上两个if就可以，一个if用来判断是否nuns数组中有和target相等的元素，
 * 有的话，返回元素的下标，如果没有将还小于target的元素的下标赋给temp，如果大于自然不进行赋值操作，
 * 得到的就是仅小于target的元素的位置，target如果没有与之相等的元素，则插入在略小于他的元素后面，
 * 注意target比数组所有元素都小的特殊情况，将temp值初始化为-1，后面返回的时候是+1的，因为插入在略小于他的元素后面
 * 这样也能得到0的正确结果
 */

```
