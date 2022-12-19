```
package ZJM_1_两数之和;

public class Main {
    public static void main(String[] args) {
        int[] nums1 = {2, 7, 11, 15};
        int[] nums2 = {3,2,4};

        int target1 = 9;
        int target2 = 6;

        Solution solution = new Solution();

        int[] temp1 = solution.twoSum(nums1,target1);
        for (int a:temp1) {
            System.out.print(a+" ");
        }
        System.out.println();

        int[] temp2 = solution.twoSum(nums2,target2);
        for (int a:temp2) {
            System.out.print(a+" ");
        }
    }
}

class Solution {
    public int[] twoSum(int[] nums, int target) {
        int[] temp = new int[2];

        for(int i=0;i<nums.length;i++){
            for(int j=i+1;j<nums.length;j++){
                if(nums[i]+nums[j]==target){
                    temp[0]=i;
                    temp[1]=j;
                    return temp;
                }
            }
        }

        return null;
    }
}

/**
 * 本题直接使用双重for循环进行遍历，找到两个下标相加等于target的情况就返回下标
 * 因为是两个数相加，只有两种情况，返回两个下标，或返回空（未找到）
 * 这里需要注意，j从i+1开始即可，不然如果遇到如提交时的测试数据[3,2,4]这种情况，
 * 两个nums[0]相加刚好会等于target的值6，所以返回[0,0]的错误答案
 */

```
