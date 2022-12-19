### 解题思路
采用头尾双指针，一个从左向右搜索，另一个从右向左搜索；
搜索时不断判断字符是否属于元音，当找到元音字母就停止搜索；
当左右指针都找到元音字母时，就交换两字母位置；
直至左右指针相遇，表示搜索完成，停止循环。

时间复杂度：O(n)，n指字符串长度；因为需要遍历一次字符串
空间复杂度：O(n)，n指字符串长度；因为python中字符串是不可变类型，不能原地修改，因此需要使用list()将字符串转变为列表类型再进行原地操作，这就需要新建列表作为额外空间，长度为n

### 代码

```python3
class Solution:
    def reverseVowels(self, s: str) -> str:
        hashmap={'a','e','i','o','u','A','E','I','O','U'}
        left=0
        right=len(s)-1
        l=list(s)
        while left < right:
            while l[left] not in hashmap and left < right:
                left+=1
            while l[right] not in hashmap and left < right:
                right-=1
            if left < right:
                l[left],l[right]=l[right],l[left]
                left+=1
                right-=1
        return ''.join(l)

```