### 解题思路
1.准备两个列表：list1:是26个0，[0,0,0,...,0,0],list2:是26个小写英文字母['a','b','c',...,'y','z']
2.遍历所传入的字符串s,在列表list2寻找是否有这个值，如果有，则在列表list1对应位置+1，
字符串t同理，不过是在列表list1对应位置-1。

遍历之后，如果是有效字母的异位词（所使用字母种类、个数一样，只是位置不一样），列表list1还是不变的，全是零。
如果不是有效字母的异位词，那么列表list1就会有不是零的值，例如list1=[-1,0,1,....,0,0]等情况
3.对列表list1进行顺序排序，遍历列表list1，如果开头和结尾的值有一个不等于0，就说明不是，返回False，
其他情况就是返回True
### 代码

```python3
class Solution:
    def isAnagram(self, s: str, t: str):
        list1=[0]
        list1 = list1 * 26
        list2 = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
        for i in s:
            list1[list2.index(i)]+=1
        for l in t:
            list1[list2.index(l)]-=1
        for k in list1:
            list1.sort()
            if list1[0] !=0 or list1[-1]!=0:
                return False
            else:
                return True

```