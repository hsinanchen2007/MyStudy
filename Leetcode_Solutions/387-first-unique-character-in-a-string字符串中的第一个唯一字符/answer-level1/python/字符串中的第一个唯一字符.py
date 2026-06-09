#### 方法一： 线性时间复杂度解法

这道题最优的解法就是线性复杂度了，为了保证每个元素是唯一的，至少得把每个字符都遍历一遍。

算法的思路就是遍历一遍字符串，然后把字符串中每个字符出现的次数保存在一个散列表中。这个过程的时间复杂度为 $O(N)$，其中 $N$ 为字符串的长度。 

接下来需要再遍历一次字符串，这一次利用散列表来检查遍历的每个字符是不是唯一的。如果当前字符唯一，直接返回当前下标就可以了。第二次遍历的时间复杂度也是 $O(N)$。 

<![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_1.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_2.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_3.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_4.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_5.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_6.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_7.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_8.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_9.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_10.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_11.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_12.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_13.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_14.png),![1200](https://pic.leetcode-cn.com/Figures/387/387_slide_15.png)>

```Java [solution-Java]
class Solution {
    public int firstUniqChar(String s) {
        HashMap<Character, Integer> count = new HashMap<Character, Integer>();
        int n = s.length();
        // build hash map : character and how often it appears
        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            count.put(c, count.getOrDefault(c, 0) + 1);
        }
        
        // find the index
        for (int i = 0; i < n; i++) {
            if (count.get(s.charAt(i)) == 1) 
                return i;
        }
        return -1;
    }
}
```

```Python [solution-Python]
class Solution:
    def firstUniqChar(self, s: str) -> int:
        """
        :type s: str
        :rtype: int
        """
        # build hash map : character and how often it appears
        count = collections.Counter(s)
        
        # find the index
        for idx, ch in enumerate(s):
            if count[ch] == 1:
                return idx
        return -1
```

**复杂度分析**

* 时间复杂度： $O(N)$ 
只遍历了两遍字符串，同时散列表中查找操作是常数时间复杂度的。

* 空间复杂度： $O(N)$ 
用到了散列表来存储字符串中每个元素出现的次数。