1. 关于复杂度
<br />&nbsp;1.1 时间复杂度为O(n^2)
<br />&nbsp;1.2 空间负责度为O(n^2)
2. 我的解题思路
<br />&nbsp;2.1 根据题目给出的动图，我们可以发现一个很明显的规律
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.1.1 每行第一个元素都为1
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.1.2 每行最后一个元素为1
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.1.3 每行之间的元素个数依次递增1
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.1.4 当前元素值等于上一行对应列以及左列的元素之和
<br />&nbsp;2.2 根据2.1寻找的规律，我们定义一个二重嵌套列表source缓存循环计算的结果并返回
<br />&nbsp;2.3 二重循环依次求出每个值，根据2.1得出的规律一共有三个情况(i为外层遍历指针，j为内层遍历指针)
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.3.1 j=0||j=i时，元素为1
<br />&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;2.3.2 current=source.get(i-1).get(j)+source.get(i-1).get(j)
3. 提交记录
<br />&nbsp;3.1 力扣中耗时1ms,消耗32.6MB内存
<br />&nbsp;3.2 leetcode中耗时0ms,消耗35.2MB内存
4. Q&A

```
/**
 * Problem
 *     118.Pascal's Triangle
 *     https://leetcode.com/problems/pascals-triangle/
 * Grade of difficulty
 *     Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n^2)
     *     1.2 Space Complexity is O(n^2)
     * 2.how I solve
     *     2.1 define a double list to cache result
     *     2.2 use double circulation to calculate(i is present row,j is present column),there have three condition
     *          2.2.1 j=0,present current position is at left border,temp num=1
     *          2.2.2 j=i,present current position is at right border,temp num=1
     *          2.2.3 other condition,according to topic,temp num=source.get(j-1)+source.get(j);
     * 3.About submit record
     *     3.1 1ms and 32.6MB memory in LeetCode China
     *     3.2 0ms and 35.2MB memory in LeetCode
     * 4.Q&A
     * @param numRows
     * @return
     */
    public List<List<Integer>> generate(int numRows) {
        List<List<Integer>> list=new ArrayList<>();
        for(int i=0;i<numRows;i++){
            List<Integer> temp=new ArrayList<>();
            for(int j=0;j<i+1;j++){
                int num;
                if(j==0||j==i){
                    num=1;
                }
                else{
                    List<Integer> source=list.get(i-1);
                    num=source.get(j-1)+source.get(j);
                }
                temp.add(num);
            }
            list.add(temp);
        }
        return list;
    }
}

```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路