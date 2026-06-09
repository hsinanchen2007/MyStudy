### 解题思路
/**
 * 栈 + HashMap
 * 1.当栈顶非空且栈顶元素小于当前元素，始终放入哈希表
 * 2.将非空的栈顶元素，配上-1，放入哈希表
 * 3.将结果放入result中，返回result
 */
### 代码

```java
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer,Integer> map = new HashMap<Integer,Integer>();
        Stack<Integer> sta = new Stack<Integer>();
        int len1 = nums1.length;
        int len2 = nums2.length;
        int[] result = new int[len1];

        for(int i = 0; i < len2;i++){
            while(!sta.isEmpty() && sta.peek()<nums2[i])
                map.put(sta.pop(),nums2[i]);
            sta.push(nums2[i]);
        }
        while(!sta.isEmpty())
            map.put(sta.pop(),-1);
        for(int i = 0;i<len1;i++)
            result[i] = map.get(nums1[i]);
        return result;
    }
}
```