1. 关于复杂度
    1.1 时间复杂度为O(m+n)
    1.2 空间负责度为O(n)
2. 我的解题思路
    2.1 因为我们需要得到当前元素在nums2的下一个最大元素，所以我们可以构成一个当前元素与在在nums2的下一个最大元素的一对一映射
    2.2 定义一个栈跟队列缓存结果
    2.3 循环遍历nums2
        2.3.1 如果当前栈不为空而且栈顶元素小于当前元素，将他们放入HashMap中
        2.3.2 将当前元素入栈
    2.4 遍历nums1获取HashMap对应的值
<br />
### java实现
```
/**
 * Problem
 *     496.Next Greater Element I
 *     https://leetcode.com/problems/next-greater-element-i/
 *     https://leetcode-cn.com/problems/next-greater-element-i/
 * Grade of difficulty
 *     Easy
 * Related topics
 * @author cartoon
 * @version 1.0
 */
class Solution {

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(m+n)（m is nums1.length,n is nums.length）
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 cache we need to mark next element on nums2,so it forms a one-to-one relationship with element on nums1 and bigger on element which bigger than element on nums2
     *     2.2 define a stack and hashMap to cache calculate result
     *     2.3 circulate nums2
     *         2.3.1 if stack is not empty,compare top element and current element,if current's is bigger than top's,put it to hashMap
     *         2.3.2 add current element to stack
     *     2.4 circulate nums1 and use current element to get value from HashMap
     * 3.About submit record
     *     3.1 9ms and 37.8MB memory in LeetCode China
     *     3.2 2ms and 37.1MB memory in LeetCode
     * 4.Q&A
     * @param nums1
     * @param nums2
     * @return
     */
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Deque<Integer> stack=new LinkedList<>();
        Map<Integer,Integer> map=new HashMap<>();
        for(int temp:nums2){
            while(stack.size()!=0&&stack.peekFirst()<temp){
                map.put(stack.removeFirst(),temp);
            }
            stack.addFirst(temp);
        }
        map.forEach((key,value)->{
            System.out.println(key+" "+value);
        });
        int[] res=new int[nums1.length];
        for(int i=0,length=res.length;i<length;i++){
            res[i]=map.getOrDefault(nums1[i],-1);
        }
        return res;
    }
}

```
<br />
### php实现
```
class Solution{

    /**
     * 1.About Complexity
     *     1.1 Time Complexity is O(m+n)（m is nums1.length,n is nums.length）
     *     1.2 Space Complexity is O(n)
     * 2.how I solve
     *     2.1 cache we need to mark next element on nums2,so it forms a one-to-one relationship with element on nums1 and bigger on element which bigger than element on nums2
     *     2.2 define a stack and hashMap to cache calculate result
     *     2.3 circulate nums2
     *         2.3.1 if stack is not empty,compare top element and current element,if current's is bigger than top's,put it to hashMap
     *         2.3.2 add current element to stack
     *     2.4 circulate nums1 and use current element to get value from HashMap
     * 3.About submit record
     *     3.1 16ms and 15.2MB memory in LeetCode China
     *     3.2 12ms and 15MB memory in LeetCode
     * 4.Q&A
     * @param nums1
     * @param nums2
     * @return
     */
    function nextGreaterElement($nums1, $nums2) {
        $stack = [];
        $map = [];
        for($index = 0, $len = count($nums2); $index < $len; $index++){
            while (count($stack) != 0 && $stack[count($stack) - 1] < $nums2[$index]){
                $map[array_pop($stack)] = $nums2[$index];
            }
            array_push($stack, $nums2[$index]);
        }
        $res = [];
        for($index = 0, $len = count($nums1); $index < $len; $index++){
            array_push($res, isset($map[$nums1[$index]]) ? $map[$nums1[$index]] : -1);
        }
        return $res;
    }
}
```

