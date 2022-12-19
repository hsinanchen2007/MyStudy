### 解题思路
此处撰写解题思路
**python用堆栈实现，python的堆栈还是比较简单的，append可解**
### 代码

```python
class Solution(object):
    def longestValidParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """
        st=[]
        Max=0
        st.append(-1)
        for i, val in enumerate(s):
            if val=='(':
                st.append(i)
            else:
                c=st.pop()
                if(len(st)==0):
                    st.append(i)
                else:
                    Max=max(Max,i-st[len(st)-1])
        return Max

```