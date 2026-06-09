 我应该算是小白，虽然学了好几个月的Python了，但对于算法一窍不通。下面是我的代码，如果有错误望指正
思路：
1.求最长无重复字符串，准备一个容器（列表）放不重复的字符串，准备一个变量存放最长长度
2.每次放进一个元素都取一下列表的长度，与当今最长长度作比较，大的话就赋值。否则，继续遍历，直到字符串遍历结束。
3.只要重复了元素就切掉列表中重复元素前面所有的元素，当然重复的元素要追加到列表中。
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        st=[]
        nummax = 0
        for i in s:
            if i not in st:
                st.append(i)
                if len(st)> nummax:
                    nummax = len(st)
            else:
                n = st.index(i)
                st = st[n+1:]
                st.append(i)
        return nummax 
```



