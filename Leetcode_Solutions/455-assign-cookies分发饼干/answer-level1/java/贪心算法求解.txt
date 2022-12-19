1. 关于复杂度
   1.1 时间复杂度为O(n log n)
   1.2 空间负责度为O(1)
2. 我的解题思路
   2.1 升序排列两个数组
   2.2 判断当前cookie是否能满足孩子的需要

<br/>
### java实现
```
/**
 * Problem
 *      455. Assign Cookies
 * Grade of difficulty
 *      Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n log n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 sort two array ascending
     *     2.2 Determine if current cookie will meet the child's needs
     *     2.3 end circulation when whichever array traverse end
     * 3.About submit record
     *     3.1 20ms and 49.2MB memory in LeetCode China
     *     3.2 8ms and 40MB memory in LeetCode
     * 4.Q&A
     * @param g
     * @param s
     * @return
     */
    public int findContentChildren(int[] g, int[] s) {
        Arrays.sort(g);
        Arrays.sort(s);
        int i=0,j=0;
        int l1=g.length,l2=s.length;
        while(i<l1&&j<l2){
            if(g[i]<=s[j]){
                i++;
            }
            j++;
        }
        return i;
    }
}

```
<br />
### php实现
```
class Solution455{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(n log n)
     *     1.2 Space Complexity is O(1)
     * 2.how I solve
     *     2.1 sort two array ascending
     *     2.2 Determine if current cookie will meet the child's needs
     *     2.3 end circulation when whichever array traverse end
     * 3.About submit record
     *     3.1 64ms and 16.6MB memory in LeetCode China
     *     3.2 64ms and 16.9MB memory in LeetCode
     * 4.Q&A
     * @param g
     * @param s
     * @return
     */
    function findContentChildren($g, $s) {
        sort($g);
        sort($s);
        $i = 0;
        $j = 0;
        $len1 = count($g);
        $len2 = count($s);
        while ($i < $len1 && $j < $len2){
            if($g[$i] <= $s[$j]){
                $i++;
            }
            $j++;
        }
        return $i;
    }
}
```
如果你有更好的想法或者疑问，可以到 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 提出issue，我会及时处理
你也可以关注 [我的leetcode解法仓库](https://github.com/cartoonYu/LeetCodeSolution) 获得其他题目解题思路

