1. 关于复杂度
<br />&nbsp;1.1 时间复杂度为O(n!)
<br />&nbsp;1.2 空间负责度为O(n^2)
2. 我的解题思路
<br />&nbsp;2.1 这个解法基于回溯算法
<br />&nbsp;2.2 定义一个操作list以及结果list
<br />&nbsp;2.3 将操作list加入到结果list中
<br />&nbsp;2.4 循环遍历数组
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.4.1 将当前遍历的元素加入操作list中
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.4.2 递归遍历下一元素
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.4.3 移除2.4.1加入的元素
3. 提交记录
<br />&nbsp;3.1 力扣中耗时1ms,消耗36MB内存
<br />&nbsp;3.2 leetcode中耗时0ms,消耗37.5MB内存
4. Q&A

```
/**
 * Problem
 *     78.Subsets
 *     https://leetcode.com/problems/subsets/
 * Grade of difficulty
 *     Medium
 * Related topics
 * @author cartoon
 * @version 1.0
 */
public class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n!)
     *     1.2 Space Complexity is O(n^2)
     * 2.how I solve
     *     2.1 this solution is base on backTracking
     *     2.2 define a operate list and result list
     *     2.3 add current operate list to result list
     *     2.4 circulate current position to nums.length
     *         2.4.1 add current element to operate list
     *         2.4.2 recurse and traverse next element
     *         2.4.3 remove 2.4.1 add element
     * 3.About submit record
     *     3.1 1ms and 36MB memory in LeetCode China
     *     3.2 0ms and 37.5MB memory in LeetCode
     * 4.Q&A
     * @param nums
     * @return
     */
    public List<List<Integer>> subsets(int[] nums) {
        if(nums==null||nums.length==0){
            return Collections.emptyList();
        }
        res=new ArrayList<>();
        backTracking(nums,0,new ArrayList<>());
        return res;
    }

    private List<List<Integer>> res;

    private void backTracking(int[] nums,int position,List<Integer> list){
        res.add(new ArrayList<>(list));
        for(int i=position,size=nums.length;i<size;i++){
            list.add(nums[i]);
            backTracking(nums,i+1,list);
            list.remove(list.size()-1);
        }
    }
}
```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路
