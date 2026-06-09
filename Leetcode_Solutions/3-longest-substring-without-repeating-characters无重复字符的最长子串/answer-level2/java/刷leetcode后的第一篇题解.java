### 解题思路
昨天开始尝试刷leetcode，发现前两题我能写，但是性能方面和官方答案相差甚远，仅仅两道题的官方答案就让我感觉受益匪浅，愈发觉得刷leetcode是一个很好的选择。今天看到这道题时，吸取了两数之和的官方解题思路，尝试用hashmap解题，没想到和该题的官方答案中的一种思路差不多，性能差的也不是很大，希望以此篇来激励自己坚持刷题，不断进步。

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        char arr[] = s.toCharArray();//将字符串转化成数组
        int max = 0;//记录前i个元素中不重复子串长度最大值
        int cur = 0;//记录当前不重复子串长度
        int startIndex = 0;//记录当前不重复子串的起始下标
        HashMap<Character, Integer> c = new HashMap<Character, Integer>();
        //只在出现重复元素和到达数组尾部对max求解
        for (int i = 0; i < arr.length; i++) {
            //如果c中不存在arr[i]或者是当前起始位置在上一个该元素出现之后，就将arr[i]加入c中
            if (!c.containsKey(arr[i]) || c.get(arr[i]) < startIndex) {
                c.put(arr[i], i);
                if (i == arr.length - 1) {//防止从当前起始位置到数组末尾都没有出现重复元素，出现不计算该子串长度的情况
                    cur = i- startIndex + 1;
                    max = (max > cur) ? max : cur;
                }
            } else {//arr[i]在当前起始位置后出现过
                cur = (i - 1 - startIndex) + 1;//计算当前起始位置到该arr[i]出现之前的子串长度
                max = (max > cur) ? max : cur;
                startIndex = c.get(arr[i]) + 1;//起始位置变为上一个该元素的下一个位置，去除重复元素
                c.put(arr[i], i);
            }
        }
        return max;
     
    }
}
```