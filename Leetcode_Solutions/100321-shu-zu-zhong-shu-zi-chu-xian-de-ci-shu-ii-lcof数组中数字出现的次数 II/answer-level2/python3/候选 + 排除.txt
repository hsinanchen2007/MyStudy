### 解题思路
其实也挺暴力的，只不过选数据结构时转换了一下思路，用两个集合（而不是列表等）去储存候选数字和排除数字。根据题意，最后候选数字有且只有一个，只要把返回候选集合的.pop()返回值就行
![image.png](https://pic.leetcode-cn.com/d1d13687bb456ba92114ba97996f17a62dd1da44a7f531fa2428bbfc6840c3db-image.png)

### 代码

```python3
class Solution:
    def singleNumber(self, nums: List[int]) -> int:
        canditate_set = set()
        except_set = set()
        for n in nums:
            if n not in canditate_set:
                if n not in except_set:
                    canditate_set.add(n)
                else:
                    continue
            else:
                canditate_set.remove(n)
                except_set.add(n)
        return canditate_set.pop()
            





```