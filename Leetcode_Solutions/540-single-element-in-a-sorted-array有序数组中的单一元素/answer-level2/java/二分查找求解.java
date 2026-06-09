Java 耗时1ms，内存59.3MB
```
/**
 * Problem
 *      540.Single Element in a Sorted Array
 * Grade of difficulty
 *      Medium
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(log n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 this solution is base on binary search
     *     2.2 compare mid element to adjacent element,recurse with mid+1 to i or mid-1 to j
     * 3.About submit record
     *     3.1 1ms and 59.3MB memory in LeetCode China
     *     3.2 0ms and 37.4MB memory in LeetCode
     * 4.Q&A
     */
    private int num=-1;

    public int singleNonDuplicate(int[] nums) {
        if(nums.length==0){
            return 0;
        }
        if(nums.length==1){
            return nums[0];
        }
        binarySearch(nums,0,nums.length-1);
        return num;
    }

    private void binarySearch(int[] nums,int i,int j){
        if(i<0||j>nums.length-1||i>j){
            return;
        }
        int mid=i+((j-i)>>1);
        if(mid==0){
            if(nums[mid]!=nums[mid+1]){
                num=nums[mid];
                return;
            }
        }
        else{
            if(mid==nums.length-1){
                if(nums[mid]!=nums[mid-1]){
                    num=nums[mid];
                    return;
                }
            }
            else{
                if(nums[mid]!=nums[mid-1]&&nums[mid]!=nums[mid+1]){
                    num=nums[mid];
                    return;
                }
            }
        }
        binarySearch(nums,mid+1,j);
        binarySearch(nums,i,mid-1);
    }
}

```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出pull request，我会及时处理反馈<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路