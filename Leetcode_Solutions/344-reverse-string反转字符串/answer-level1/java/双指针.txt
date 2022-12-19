1. 关于复杂度
    1.1 时间复杂度为O(n)
    1.2 空间负责度为O(1)
2. 我的解题思路
    2.1 使用两个指针从头尾两端开始遍历，交换他们所指的元素
    2.2 我认为这个解法跟快排中的交换元素形成基准值有点类似
3. 提交记录
    3.1 力扣中耗时4ms,消耗60.5MB内存
    3.2 leetcode中耗时1ms,消耗49.6MB内存
4. Q&A

```
/**
 * Problem
 *      344.Reverse String
 *      https://leetcode.com/problems/reverse-string/
 *      https://leetcode-cn.com/problems/reverse-string/
 * Grade of difficulty
 *      Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 use two pointer to traverse apart from head and tail,swap them util i<j
     *     2.2 I think it is similar to quick sort in a certain extent
     * 3.About submit record
     *     3.1 4ms and 60.5MB memory in LeetCode China
     *     3.2 1ms and 49.6MB memory in LeetCode
     * 4.Q&A
     * @param s
     */
    public void reverseString(char[] s) {
        int i=0,j=s.length-1;
        while(i<j){
            char temp=s[i];
            s[i++]=s[j];
            s[j--]=temp;
        }
    }
}

```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路