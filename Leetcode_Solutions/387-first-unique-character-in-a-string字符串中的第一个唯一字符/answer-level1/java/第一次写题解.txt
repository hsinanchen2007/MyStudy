### 解题思路
此处撰写解题思路
1. 多数题解用HashMap，这里自己用的是数组，只需要存储26个
2. 其实是借助了Trie数的实现存储结构。
3. [https://leetcode-cn.com/problems/implement-trie-prefix-tree/solution/shi-xian-trie-qian-zhui-shu-by-leetcode/](实现Trie)
### 代码
![1.png](https://pic.leetcode-cn.com/a13ed5251250f6dc1af6fd1f2918b580c0b184241ea603387fed9f2f68be33a7-1.png)

```java
class Solution {
    public int firstUniqChar(String s) {
        if (s.length() == 0) return -1;
        int[] R = new int[26];
        for (int i = 0; i < s.length(); i++) {
            R[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < s.length(); i++) {
            if (R[s.charAt(i) - 'a'] == 1) 
               return i;
        }
        return -1;
    }
}
```