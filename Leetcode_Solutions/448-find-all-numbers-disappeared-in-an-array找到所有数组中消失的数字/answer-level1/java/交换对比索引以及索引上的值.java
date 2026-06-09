1. 关于复杂度
    1.1 时间复杂度为O(n)
    1.2 空间负责度为O(1)
2. 我的解题思路
    2.1 循环遍历数组，若nums[index]!=nums[nums[index]-1]，循环交换直到相等
    2.2 循环遍历数组，若nums[index]!=index+1，将索引加入结果中
3. 提交记录
    3.1 力扣中耗时7ms,消耗48.3MB内存
    3.2 leetcode中耗时5ms,消耗50MB内存
4. Q&A

```
/**
 * Problem
 *     448.Find All Numbers Disappeared in an Array
 *     https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/
 *     https://leetcode-cn.com/problems/find-all-numbers-disappeared-in-an-array/
 * Grade of difficulty
 *     Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
public class Solution448 {

    /**
     * 1.关于复杂度
     *     1.1 时间复杂度为O(n)
     *     1.2 空间负责度为O(1)
     * 2.我的解题思路
     *     2.1 循环遍历数组，若nums[index]!=nums[nums[index]-1]，循环交换直到相等
     *     2.2 循环遍历数组，若nums[index]!=index+1，将索引加入结果中
     * 3.提交记录
     *     3.1 力扣中耗时7ms,消耗48.3MB内存
     *     3.2 leetcode中耗时5ms,消耗50MB内存
     * 4.Q&A
     *
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 circulate from head to tail,if nums[index]!=nums[nums[index]-1],circulate to swap their value
     *     2.2 circulate array,if nums[index]!=index+1,add to result list
     * 3.About submit record
     *     3.1 7ms and 48.3MB memory in LeetCode China
     *     3.2 5ms and 50MB memory in LeetCode
     * 4.Q&A
     * @param nums
     * @return
     */
    public List<Integer> findDisappearedNumbers(int[] nums) {
        if(nums==null){
            return Collections.emptyList();
        }
        int length=nums.length;
        for (int i=0;i<length;i++) {
            while (nums[i]!=nums[nums[i]-1]){
                swap(nums,i,nums[i]-1);
            }
        }
        List<Integer> list = new LinkedList<>();
        for (int i=0;i<length;i++) {
            if(nums[i]!=i+1){
                list.add(i+1);
            }
        }
        return list;
    }

    private void swap(int[] nums, int i, int j){
        int temp=nums[i];
        nums[i]=nums[j];
        nums[j]=temp;
    }
}
```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路