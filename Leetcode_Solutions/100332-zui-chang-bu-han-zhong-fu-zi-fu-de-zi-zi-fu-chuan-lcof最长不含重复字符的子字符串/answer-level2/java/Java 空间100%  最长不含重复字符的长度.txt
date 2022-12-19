### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int max = 0, curr = 0;
        int[][] visited = new int[256][2];
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (visited[c][0] == 0) {
                curr++;
                visited[c][0] = 1; // 0下标存储是否该字符已经存在
                visited[c][1] = i; // 1下标存储该字符的下标
            } else {
                // 获取目前重复字符的位置，初始化curr为0，visited初始化
                int index = visited[c][1];
                visited = new int[256][2];
                
                curr = 0;
                i = index;
                // 将i指向当前重复元素的旧位置，从其之后的字符开始继续处理
            }
            if (max < curr) {
                max = curr;
            }
        }

        return max;
    }
}
```