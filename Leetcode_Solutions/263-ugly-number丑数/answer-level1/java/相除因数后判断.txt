1. 关于复杂度
<br />&nbsp;1.1 时间复杂度为O(n)
<br />&nbsp;1.2 空间负责度为O(1)
2. 我的解题思路
<br />&nbsp;2.1 根据题意可知，丑数的定义为只含有2，3，5任一个质数，重点是在只这个字上
<br />&nbsp;2.2 根据丑数的定义，其实我们可以用原来的数据分别整除掉2，3，5
<br />&nbsp;2.3 在整除完后，如果结果不等于1，就意味着原始数据含有除2，3，5之外的因数
3. 提交记录
<br />&nbsp;3.1 力扣中耗时5ms,消耗33.5MB内存
<br />&nbsp;3.2 leetcode中耗时1ms,消耗33.7MB内存
```
/**
 * Problem
 *     263.Ugly Number
 *     https://leetcode.com/problems/ugly-number/
 * Grade of difficulty
 *     Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
public class Solution263 {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 according to topic,we know ugly number only include 2,3,5 primes factors,the point is only
     *     2.2 according to definition,we can use divide the number with 2,3 or 5
     *     2.3 if though all operation,the rest of number isn't equals 1,it means original number have another factors expect 2,3 or 5
     * 3.About submit record
     *     3.1 5ms and 33.5MB memory in LeetCode China
     *     3.2 1ms and 33.7MB memory in LeetCode
     * 4.Q&A
     * @param num
     * @return
     */
    public boolean isUgly(int num) {
        if(num==0){
            return false;
        }
        if(num==1){
            return true;
        }
        while(num%2==0){
            num/=2;
        }
        while(num%3==0){
            num/=3;
        }
        while(num%5==0){
            num/=5;
        }
        return num==1;
    }
}
```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路