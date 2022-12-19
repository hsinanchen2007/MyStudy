#### 解题思路：

- 本题考察 **哈希表** 的使用，总体思路为：
  1. 遍历字符串 `s` ，使用哈希表统计 “各字符数量是否 $> 1$ ”。
  2. 再遍历字符串 `s` ，在哈希表中找到首个 “数量为 $1$ 的字符”，并返回。

![Picture1.png](https://pic.leetcode-cn.com/6267458e5029276aa6b2696ea0941fbc4e890c06d02ce72b39f419a8cffad259-Picture1.png){:width=450}

##### 算法流程：

1. **初始化：** 字典（Python）、HashMap（Java），记为 `dic` ；
2. **字符统计：** 遍历字符串 `s` 中的每个字符 `c` ；
   1. 若 `dic` 中 **不包含** 键(key) `c` ：则向 `dic` 中添加键值对 `(c, True)` ，代表字符 `c` 的数量为 $1$ ；
   2. 若 `dic` 中 **包含** 键(key) `c` ：则修改键 `c` 的键值对为 `(c, False)` ，代表字符 `c` 的数量 $> 1$ 。 
3. **查找数量为 $1$ 的字符：** 遍历字符串 `s` 中的每个字符 `c` ；
   1. 若 `dic`中键 `c` 对应的值为 `True` ：，则返回 `c` 。
4. 返回 `' '` ，代表字符串无数量为 $1$ 的字符。

<![Picture2.png](https://pic.leetcode-cn.com/91e3ce2fe86d7d10b9fde23432a940c8fcb0fe0041f8060b161cf1d53e4d4730-Picture2.png),![Picture3.png](https://pic.leetcode-cn.com/92f9757fdf9ec44aeb84e60829ee5d8e3e8b5554d0a225d8e0a1ddcf5c455d85-Picture3.png),![Picture4.png](https://pic.leetcode-cn.com/76d603378fc1a49df726dab0726f98fd70757be6e4fda6c2dc6bfc08560a9611-Picture4.png),![Picture5.png](https://pic.leetcode-cn.com/6a34c384b8115ee94c4a8ea579f617cd3323b9e75843c7fa3d817306a050fb89-Picture5.png),![Picture6.png](https://pic.leetcode-cn.com/21236beaecab5b4b19ee9bf16316c4bdff27dc101b09fcc154319f3a0da3da8c-Picture6.png),![Picture7.png](https://pic.leetcode-cn.com/000011db243f4d66e8148bd23ba1844c6c900a5e78eccd713e1ff75ec0027c1a-Picture7.png),![Picture8.png](https://pic.leetcode-cn.com/83ed2a6a9a8de3cb59126611ea0dbc50e7406fa387953a4dc32ef3d12d3824db-Picture8.png),![Picture9.png](https://pic.leetcode-cn.com/94eff1758b80969b6258784ba579c2aa852b7ce21415c0a146aa187221ee6b90-Picture9.png),![Picture10.png](https://pic.leetcode-cn.com/0625d820c50972692fcaaef38c12d6a9b8feb8e4b21de54442637c4a1a3de796-Picture10.png),![Picture11.png](https://pic.leetcode-cn.com/85f6fae3f7784516b82bd4a43099ca09dd5f049834ec3931621c4a8655601017-Picture11.png),![Picture12.png](https://pic.leetcode-cn.com/361f2a5c01f38856ed23dedec87084697182b51ac25d8696d105c9a1757052fe-Picture12.png)>

##### 复杂度分析：

- **时间复杂度 $O(N)$ ：** $N$ 为字符串 `s` 的长度；需遍历 `s` 两轮，使用 $O(N)$ ；HashMap 查找的操作复杂度为 $O(1)$ ；
- **空间复杂度 $O(N)$ ：** HashMap 需存储 $N$ 个字符的键值对，使用 $O(N)$ 大小的额外空间。

#### 代码：

> Python 代码中的 `not c in dic` 整体为一个布尔值； `c in dic` 为判断字典中是否含有键 `c` 。

```python []
class Solution:
    def firstUniqChar(self, s: str) -> str:
        dic = {}
        for c in s:
            dic[c] = not c in dic
        for c in s:
            if dic[c]: return c
        return ' '
```

```java []
class Solution {
    public char firstUniqChar(String s) {
        HashMap<Character, Boolean> dic = new HashMap<>();
        char[] sc = s.toCharArray();
        for(char c : sc)
            dic.put(c, !dic.containsKey(c));
        for(char c : sc)
            if(dic.get(c)) return c;
        return ' ';
    }
}
```

> **致谢：** 感谢评论区大佬 @[moqimoqidea](https://leetcode-cn.com/u/moqimoqidea/) 提出的解法优化，赞！