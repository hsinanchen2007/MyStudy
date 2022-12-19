![2019-12-01 23-25-41 的屏幕截图.png](https://pic.leetcode-cn.com/ab9055cf76f708a9a48951f48df491f096616b15f6589e2ae6448351ff9672bd-2019-12-01%2023-25-41%20%E7%9A%84%E5%B1%8F%E5%B9%95%E6%88%AA%E5%9B%BE.png)


思路：
- 当 n >= k 时，记录前 n 个字符分割成 k 个子串需要更改的最小次数
- 在计算前 n + 1 个字符分割成 k + 1 个子串所需的最小改变次数时，动态调整 n 的大小，使得前 n 个字符分割 k 个字符串，后 m 个字符分割成 1 个字符串所需的改变次数之和最小。其中 n , m 满足如下关系：
$$ n + m = len(string)$$

```python
    class Solution(object):
        def palindromePartition(self, s, k):
            """
            :type s: str
            :type k: int
            :rtype: int
            """
            # print(self.minChange(s))
            length = len(s)
            res = [ [101 for col in range(k+1)] for row in range(length+1) ]
            for former_ichr in range(1,length+1):
                res[former_ichr][1] = self.minChange(s[:former_ichr])
            for sub_str_num in range(2,k+1):
                # print(sub_str_num)
                former_ichr = length
                while(former_ichr >= sub_str_num):
                    for i in range(1,former_ichr - sub_str_num + 2):
                        tmp = res[former_ichr-i][sub_str_num-1] + self.minChange(s[former_ichr-i:former_ichr])
                        res[former_ichr][sub_str_num] = min([tmp,res[former_ichr][sub_str_num]])
                    former_ichr -= 1
            # print(res)
            return res[length][k]
            
        def minChange(self,s):
            count = 0
            length = len(s)
            for i in range(int(length/2)):
                if s[i] != s[length-i-1]:
                    count += 1
            return count
       