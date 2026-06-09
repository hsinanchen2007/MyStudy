### 解题思路
因为刚学python，我的想法比较笨：
输入一个数判断他是否是回文，首先想到原来的数与它反转后的数应该相等，
所以我就想到列表，因为列表里有一个reverse（）功能，是反转列表
输入一个数x,我们先利用str把他转化为字符串x，再利用list(x)转化为列表x_list,
利用reverse反转列表，此时x_list变为反转后的内容，将反转后列表利用"".join(x_list)
转为字符串b,比较此时的字符串和原来的字符串


### 代码

```python
class Solution(object):
    def isPalindrome(self, x):
        if x < 0 or (x != 0 and x % 10 == 0):
            return False
        else:
            x = str(x)
            x_list = list(x)
            x_list.reverse()
            b = "".join(x_list)
            if x==b:
                return True
            else:
                return False

```