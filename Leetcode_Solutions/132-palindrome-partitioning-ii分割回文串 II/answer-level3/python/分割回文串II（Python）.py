这题是第131题-分割回文串的进阶版，在第131题中我是用到了回溯法,本来想这题也生搬硬套回溯法，结果是超出时间限制了，最后没办法用了动态规划法来解决。我突然是发现了一条规律：执行效率：动态规划法 > 回溯法。下面我将分别贴出这两种算法的代码。

# 回溯法

当时因为是第131题用到了该方法，很快解决了问题，所以这题我是毫不犹豫就用该方法，只是做了一些改进，没想到超出时间限制了，这确实是有点超乎我意料了。不过想想也确实，这题号称也是困难级题目了，如果就这么easy解出来了，那有点掉面子了。

本题与第131题最大的不同就是：第131题中是使用了split_result列表来收集最终的分割结果，而此题是用min_split 来专门记录分割的最少次数，参数不一样，所以代码会有些不同。

代码如下：
```python
class Solution(object):
    # 本题采用回溯法，其实和第131题特别类似
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """   
        if len(s) <= 1:
            return 0

        def back(start=0, min_split = len(s), res=[]):
            if start >= len(s):
                min_split = min(min_split, len(res)-1)
                return min_split
            for end in range(start+1, len(s)+1):
                split_s = s[start:end]
                if split_s == s[start:end][::-1]:
                    min_split = back(end, min_split, res+[split_s])
            return min_split
        return back()


if __name__ == "__main__":
    s = "aab"
    min_split = Solution().minCut(s)
    print(min_split)
```

# 动态回归法：
对于此题呢，首先有如下操作：

![qq_pic_merged_1560827656387.jpg](https://pic.leetcode-cn.com/aa04d399805e0422e22e4e7d8244abf1a8b230eb2c5d01590b9866d47546e35b-qq_pic_merged_1560827656387.jpg)

此处有一条规律非常重要：
```
对于起点下标值为start，终点下标值为end的字串s[start:end]来说:
          如果存在：s[start:end] == s[start:end][::-1]
          那么就有record[end] = record[start]+1
```

因为本题求得是最少分割次数，我们只需要遍历（0，end）之间的字串，求其最小值即可得出答案。

代码如下：
```python
class Solution(object):
    # 本题采用动态规划方法，回溯法超出时间限制了
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """   
        if len(s) <= 1:
            return 0
        # 定义标记列表
        record = [index for index in range(-1, len(s))]
        for end in range(1, len(s)+1):
            for start in range(end):
                if s[start:end] == s[start:end][::-1]:
                    record[end] = min(record[end], record[start]+1)
        return record[-1]


if __name__ == "__main__":
    s = "aba"
    min_split = Solution().minCut(s)
    print(min_split)
```

不过执行效率也是很一般，在30%左右。

![image.png](https://pic.leetcode-cn.com/41004cc6da9a0908180d77d1227517664b99b0a581d03b57bff8629becc59189-image.png)

如果大家有更好的方法，也希望积极留言啊！！！
