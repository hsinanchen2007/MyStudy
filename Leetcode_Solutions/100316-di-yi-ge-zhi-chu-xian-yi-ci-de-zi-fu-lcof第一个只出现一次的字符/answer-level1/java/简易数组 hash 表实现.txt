### 复杂度分析
时间复杂度：O(n)
空间复杂度：O(1)

### 解题思路
由于 key 值已知为字母，因此使用简单数组模拟 hash 表
遍历两次字符串
第一次遍历，得到所有字母出现次数
第二次遍历，找到第一个出现次数为 1 的字母

### 代码

```java
class Solution {
    public char firstUniqChar(String s) {

        int[] hashTable = new int[123];

        // 初始化 hash 表，记录所有字符出现次数
        for (int i = 0; i < s.length(); i++) {
            hashTable[s.charAt(i)]++;
        }
        
        // 查找第一个出现过一次的字符
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (hashTable[c] == 1) {
                return c;
            }
        }
        return ' ';

    }
}
```