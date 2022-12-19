### 解题思路
1：先将字符串转换成list1，利用字符串内置方法split，将原有字符串按照空格分开
2：对于list1，进行翻转
3：去除list1中的“”，生成新的list2
4：用字符串join list2里面的所有元素
缺点：
1：新建了list1和list2
2：时间复杂O(n)

### 代码

```python3
class Solution:
    def reverseWords(self, s: str) -> str:
        list1 = s.split(' ')
        list1 = list1[::-1]
        list2=[]
        for i in list1:
            if i !="":
                list2.append(i)
       # print(list2)
        res = " ".join(list2).strip()
        return res
        
```