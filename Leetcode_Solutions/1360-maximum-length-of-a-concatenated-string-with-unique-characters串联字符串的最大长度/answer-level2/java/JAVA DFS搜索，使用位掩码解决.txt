### 解题思路
思路很明显，就是使用深度优先搜索（DFS）。
需要注意的是，如何去判断当前字符串是否与已经组合的字符串是否有重复。

可以使用位掩码来解决。
数字与字母映射('a' -> 1, 'b' -> 2, 'c' -> 4)以此类推，如果已组合的字符位掩码与当前所选择的子字符的位掩码进行与运算后，得到的结果为0，说明无重复。

### 代码
```java
class Solution {
    int[] map = new int[26];
    public int maxLength(List<String> arr) {
        //初始化map,数字与字母映射('a' -> 1, 'b' -> 2, 'c' -> 4)以此类推
        for (int i = 0; i < 26; i++)
            map[i] = (1 << i);
        
        return maxLengthDFS(arr, 0, 0);
    }
    
    //此处函数的目的是为了返回串联字符的最大长度
    public int maxLengthDFS(List<String> arr, int start, int bitMask) {
        //递归终止条件
        if (start == arr.size()) 
            return 0;
        
        int ans = 0;
        for (int i = start; i < arr.size(); i++) {
            String s = arr.get(i);
            //返回当前子字符的位掩码
            int bit = returnBitMask(s);

            //一。当前子字符位掩码不为0（为0的话证明子字符里面有重复字符）
            //二。当前子字符位掩码与前面字符的位掩码与运算结果为0（如果结果不为0，那么说明与之前的字符串有重复）
            //满足上述两个条件才进入一下层递归。
            if ((bit & bitMask) == 0 && bit != 0)
                //此处可以理解为分治思想
                ans = Math.max(ans, maxLengthDFS(arr, i + 1, bitMask | bit) + s.length());
        }
        return ans;
    }
    
    public int returnBitMask(String s) {
        int bitMask = 0;
        HashSet<Character> set = new HashSet<>(); 
        for (char c : s.toCharArray()) {
            if (set.contains(c))
                return 0;
            bitMask |= (map[c - 'a']);
            set.add(c);
        }
        return bitMask;
    }
}
```