### 解题思路
执行用时 :144 ms, 在所有 Python3 提交中击败了63.45%的用户
内存消耗 :15.6 MB, 在所有 Python3 提交中击败了17.14%的用户

思路：
1. 遇到'('就将其索引入栈
2. 遇到')'就做判断：栈里是否有与其匹配的'('
        如果栈不为空，则有：把这个已经找到匹配的'('的索引从栈中移除
        如果栈为空，则没有，说明这个')'是应该被删除的，将其索引加入待删除列表
3. 对整个字符串的循环结束，stk中剩下的'('是无法匹配的，将其索引加入待删除列表
4. 将待删除的括号删除，得到最终字符串

注意：
检查某个元素是否在list中复杂度O(n)，而检查某个元素是否在集合中复杂度O(1)
个人理解：
    字符串：任何位置任何操作都是O(n)，因为字符串不可变，每次修改都会重建整个字符串
    list：类似单向链表，查要从头搜索复杂度O(n)，增删中间后面的元素都要随之移动复杂度为O(n)，增删末尾O(1)，
    set：类似散列表(无序)，查、增、删时间复杂度都是O(1)    
    补充：树(有序)，查、增、删时间复杂度都是O(logn)
下面代码中如果将remove从set换成list，速度会下降很多，时间上升到1388 ms左右
### 代码

```python3
class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stk = []
        # remove = []
        remove = set()
        for i in range(len(s)):
            # 遇到'('入栈
            if s[i] == '(':
                stk.append(i)
            # 如果遇到')'判断栈里是否有'('与其匹配
            elif s[i] == ')':
                if len(stk) == 0:
                    # remove.append(i)
                    remove.add(i)
                else:
                    stk.pop()
        # remove += stk
        remove = remove.union(set(stk))
        output = []
        for index, item in enumerate(s):
            if index not in remove:
                output.append(item)
        return ''.join(output)
```