### 解题思路

移动窗口法，定义 `L` 记录窗口最左，借助 `HashMap` 记录出现过字符的最新位置；

窗口中出现重复字符，窗口左沿挪到该字符最后出现的位置之后，继续匹配。

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        // 最大值
        int max = 0;
        // 当前窗口最左节点
        int L = 0;
        // 记录字符最后一次出现的索引
        Map<Character, Integer> map = new HashMap<>();
        // 遍历一次
        for(int i = 0 ; i < s.length() ; i++){
            char pos = s.charAt(i);
            // 取曾经最后一次出现的索引
            Integer oldIndex = map.get(pos);
            // 曾经出现过，并且在窗口中
            if(oldIndex != null && L <= oldIndex){
                // 重置窗口左节点的索引
                L = oldIndex + 1;
            }
            // 记录字符最后出现的位置
            map.put(pos, i);
            // 判断当前最长的长度
            max = Math.max(max, i - L + 1);
        }
        return max;
    }
}
```