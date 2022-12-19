### 解题思路
由于题目已经限定了是小写字母，最多只有 26 个字母。

#### 简单计数
采用简单计数方法，记录 s 中字母的出现次数。
这样第二次遍历时，就要遍历整个 s。 如果 s 远远大于 26，则开销大。

#### 花哨计数
参考 [来自评论区的代码](https://leetcode-cn.com/problems/first-unique-character-in-a-string/solution/zi-fu-chuan-zhong-de-di-yi-ge-wei-yi-zi-fu-by-leet/216674)
为了第二次只遍历 26个字母，我们可以在计数数组上做一些手脚。
+ 没有出现记为 INT_MAX
+ 出现一次记为 i
+ 出现两次记为 -1
 
于是就可以从这里的 i 返回所对应的位置。
这有点像一道智力题。
有 n 个药瓶，n-1 个中每片药为 1g， 但有1个瓶子中每片药为 1.1 g, 问如何称一次来确定那个异常的药瓶？ 
答案：先将 n 个药瓶编号 1~n, 然后从编号为 i 的药瓶中取出 i 颗药片。计算所有药片的总重量，再减去 (1+2+...n) 就可以知道是哪个编号的药瓶的药为 1.1 g。


### 代码
#### 花哨计数
```cpp
class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> counter(26, INT_MAX);
        for (int i = 0; i < s.size(); i++)
            if (counter[s[i] - 'a'] != INT_MAX)
                counter[s[i] - 'a'] = -1;
            else
                counter[s[i] - 'a'] = i;
        
        int minindex = INT_MAX;
        for (int i = 0; i < 26; i++)
            if (counter[i] != -1)
                minindex = min(minindex, counter[i]);
        
        return minindex == INT_MAX ? -1 : minindex;
    }
};
```

``` python3
class Solution:
    def firstUniqChar(self, s: str) -> int:
        num_hash = [0]*26
        for x in s:
            num_hash[ord(x)-ord('a')] += 1
        for i in range(len(s)):
            if num_hash[ord(s[i])-ord('a')] == 1:
                return i
        return -1
```