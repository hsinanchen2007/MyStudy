### 解题思路
1.栈结构表示深度
2.只要在遍历过程中，保证栈内一半的括号属于序列 A，一半的括号属于序列 B，那么就能保证拆分后最大的嵌套深度最小，是当前最大嵌套深度的一半。要实现这样的对半分配，只需要把奇数层的 ( 分配给 A，偶数层的 ( 分配给 B 即可。

### 代码

```python3
class Solution:
    def maxDepthAfterSplit(self, seq: str) -> List[int]:
        ans=[]
        d=0   #嵌套深度
        for c in seq:
            if c == '(':
                d+=1      
                ans.append(d%2)  #利用余数判别奇偶（A/B）
            else:
                ans.append(d%2)
                d-=1
        return ans
```