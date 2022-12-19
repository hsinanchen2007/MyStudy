本题我采用的是回溯法思想来解决的，怎么求解的步骤我就不多说了，于本题而言，很简单，大家看我下面的代码很容易get清楚。
关于回文串的定义，相信大家也都清楚，就是一个字符串的顺序和逆序是一样的。
代码如下：
```python
class Solution(object):
    # 本题采用回溯法
    def partition(self, s):
        """
        :type s: str
        :rtype: List[List[str]]
        """
        # 定义一列表，用来保存最终结果
        split_result = []
        # 如果给定字符串s为空，则没有分割的必要了
        if len(s) == 0:
            return split_result

        def back(start=0, res=[]):
            if start >= len(s):
                split_result.append(res)
                return 
            for end in range(start+1, len(s)+1):
                split_s = s[start:end]
                # 如果当前子串为回文串，则可以继续递归
                if split_s == s[start:end][::-1]:
                    back(end, res+[split_s])

        back()
        return split_result
            

if __name__ == "__main__":
    s = "aab"
    split_result = Solution().partition(s)
    print(split_result)
```
执行效率还算不错，在80%左右。

![image.png](https://pic.leetcode-cn.com/587b65d4fd266dd562939713d1afb0cebe2b7f4139f0a42eeaeeca3ddeed2324-image.png)

看网上的帖子，还有用动态规划来写的，我偷个懒就没想了，大家如果想到了，还请积极留言啊！