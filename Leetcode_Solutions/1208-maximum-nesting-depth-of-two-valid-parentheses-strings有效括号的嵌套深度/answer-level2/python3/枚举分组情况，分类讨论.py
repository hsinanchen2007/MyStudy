# 动态规划
考虑到A,B 均为深度最小有效括号字符串，
可在遍历seq的过程中以2个字符串为一组对比，列举出所有情况：
字符串      对应组号
'(('        01，10
'()'        00，11
')('        00，11
'))'        01，10
其中'((','))'情况类似，代码如下：


```
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans = [0] #第一位首先分给A
        i=1
        while i < len(seq):
            j=i-1   #遍历seq，2个字符串为一组，与前一个字符串比较
            if seq[i]==seq[j]:  #相同的字符串，那i对应的括号必将分给j的对立组
                if ans[-1]==0:
                    ans.append(1)
                else:
                    ans.append(0)
            else:     #不同的字符串，i必将分给j的对应组
                ans.append(ans[-1])
            i+=1
        return ans

```

菜鸡第一次写答案，欢迎各位大佬指正。