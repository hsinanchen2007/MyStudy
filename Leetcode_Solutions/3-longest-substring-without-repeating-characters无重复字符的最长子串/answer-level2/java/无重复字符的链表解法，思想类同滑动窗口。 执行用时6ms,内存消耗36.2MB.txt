### 解题思路
因为看着字符查重复，脑子里就想着用链表的形式就行存储当前无重复的字符串。

通过观察案例："abcabcbb", 字符串按字符走到了abc -> a 的时候，这时会出现重复字符“a”，未了防止出现相同的字符，我们可以把第一个“a”去掉，变成“bca”，这样当前字符串没有包含相同的字符。

同理：bca -> b 的时候，最新当前字符串应该是 “cab”，这样，我们list存储的都是最新的无重复的字符串

max 来存储list存储过的最长无重复字符串，最后返回 max。
list.pop(); 删除最左边的那个元素，直到删除到跟新添加重复的字符。


### 代码

```java
class Solution {
    public int lengthOfLongestSubstring(String s) {
        LinkedList<Character> list = new LinkedList<>();
        int max = list.size(); // 初始化无重复字符串最大长度
        char[] c = s.toCharArray();
        for (int i = 0; i < c.length; i++) {
            if (list.contains(c[i])) { // 如果要添加的字符已存在
                boolean flag = true;
                while (flag) { // 循环 直到删除的字符 = 重复的字符
                    char res = list.pop(); 
                    if (res == c[i]) {
                        flag = false;
                    }
                }
            } 
            list.addLast(c[i]); // 添加当前字符到list中，构成最新字符串
            if (list.size() > max) { // 更新最大长度
                max = list.size();
            }
        }
        return max;
    }
}
```