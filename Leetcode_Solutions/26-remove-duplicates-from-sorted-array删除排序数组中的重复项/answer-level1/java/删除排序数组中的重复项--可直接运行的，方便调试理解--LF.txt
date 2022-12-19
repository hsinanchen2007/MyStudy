```
package ZJM_26_删除排序数组中的重复项;

public class Main {
    public static void main(String[] args) {
        int[] nums1 = {1, 1, 2};
        int[] nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};

        Solution solution = new Solution();
        int nums1l = solution.removeDuplicates(nums1);
        int nums2l = solution.removeDuplicates(nums2);

        for (int i = 0; i < nums1l; i++) {
            System.out.print(nums1[i]+" ");
        }
        System.out.println();
        for (int i = 0; i < nums2l; i++) {
            System.out.print(nums2[i]+" ");
        }
    }
}

/**
 * // nums 是以“引用”方式传递的。也就是说，不对实参做任何拷贝
 * int len = removeDuplicates(nums);
 * <p>
 * // 在函数里修改输入数组对于调用者是可见的。
 * // 根据你的函数返回的长度, 它会打印出数组中该长度范围内的所有元素。
 * for (int i = 0; i < len; i++) {
 *     print(nums[i]);
 * }
 */

class Solution {
    public int removeDuplicates(int[] nums) {
        int i=0;

        for(int j=0;j<nums.length;j++){
            if(nums[j]!=nums[i]){
                i++;
                nums[i]=nums[j];
            }
        }

        return i+1;
    }
}

/**
 * 本题要注意题目的要求是
 * 给定一个排序数组，你需要在原地删除重复出现的元素，使得每个元素只出现一次，返回移除后数组的新长度。
 * 因为这个数组是已经排好序的，且nums 是以“引用”方式传递的。函数返回的是数组需要输出的长度
 * 所以可以之间通过定义两个指针，一个用来标记不同的数，用来覆盖原数组，一个遇到相同的数就继续遍历原数组
 * 最终返回的就是标记不同的数的指针，因为要保留一个重复的元素，所以先++，后赋值，返回的长度要+1
 */

```
