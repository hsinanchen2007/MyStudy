### 解题思路
数据类型采用字典保存数字-字母对应，
初始为空数字，每多一个数字即用前面的结果和这个数字的情况进行枚举组合。
构建1个函数用于反复迭代

执行用时 :28 ms, 在所有 Python3 提交中击败了92.33% 的用户
内存消耗 :13.5 MB, 在所有 Python3 提交中击败了5.17%的用户
### 代码

```python3
class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if len(digits)==0:
            return []
        res=['']
        def _addnum(X,number):
            '''
              X:前置结果，类型List
              number:2-9的数字，类型str
            '''
            results = []
            num_dict={'2':'abc','3':'def',
                  '4':'ghi','5':'jkl',
                  '6':'mno','7':'pqrs',
                  '8':'tuv','9':'wxyz'}
            for x in X:
                for n in num_dict[number]:
                    results.append(x+n)
            return results
        for s in digits:
            res=_addnum(res,s)

        return res


```