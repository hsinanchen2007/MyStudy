Java 耗时4ms，内存40.1MB
```
/**
 * Problem
 *     541.Reverse String II
 *     https://leetcode.com/problems/reverse-string-ii/
 * Grade of difficulty
 *     Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n)
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 define a stringBuilder to cache result
     *     2.2 according to topic,reverse before k in 2k
     *     2.3 judge remaining length,choose to reverse or append it directly
     * 3.About submit record
     *     3.1 4ms and 40.1MB memory in LeetCode China
     *     3.2 1ms and 37.9MB memory in LeetCode
     * 4.Q&A
     * @param s
     * @param k
     * @return
     */
    public String reverseStr(String s, int k) {
        StringBuilder sb = new StringBuilder();
        int len = s.length();
        int cur = 0;
        while(len >= 2*k){
            sb.append(new StringBuilder(s.substring(cur, cur+k)).reverse().append(s.substring(cur+k, cur+2*k)));
            len -= 2*k;
            cur += 2*k;
        }
        if(len < k){
            sb.append(new StringBuilder(s.substring(cur)).reverse());
        }else if(len < 2*k){
            sb.append(new StringBuilder(s.substring(cur, cur+k)).reverse().append(s.substring(cur+k)));
        }
        return sb.toString();
    }
}

```
如果你有更好的想法或者疑问，可以到[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)提出issue，我会及时处理反馈<br />
你也可以关注[我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution)获得其他题目解题思路