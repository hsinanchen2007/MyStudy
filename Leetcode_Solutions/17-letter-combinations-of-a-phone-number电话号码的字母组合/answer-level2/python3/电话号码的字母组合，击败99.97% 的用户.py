### 解题思路
执行用时 :16 ms, 在所有 Python3 提交中击败了99.97%的用户
内存消耗 :13.2 MB, 在所有 Python3 提交中击败了60.05%的用户
因为要求所有情况，所有穷举是必须的，这也意味着算法时间复杂度都差不多。因为python的字典是用哈希算法构建的，搜索的时间复杂度可以视为O（1），所以使用字典会比普通的遍历快一点

### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        dic={"2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"}
        r=[]
        for i in digits:
            m=len(r)
            if len(r)==0:
                for j in range(len(dic[i])):
                    r.append(dic[i][j])
            else:
                for n in range(m):
                    for j in range(len(dic[i])):
                        r.append(r[n]+dic[i][j])
                r=r[m:]
        return r

```