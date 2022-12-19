### 解题思路
#对于回文串而言，我开始考虑的情况为:当最后一个字符对应的数字为奇数时，我们将从后往前填充，先将奇数数字填充到最中心点，然后依次偶数次填充
#当最后一个字符对应的数字为偶数时，我们当第一个字符对应的数字为奇数时，我们将第一个字符填充，反之，按照偶数次填充
#实际上，我们只需要从小到大找到一个奇数次的字符把它填充到中心，然后依次偶数次填充即可，这样就能保证最大，因为如果字符中有奇数次，而又不填充到最中心的话，会导致浪费，从而不是最大。

### 代码

```python
class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        #回文串就是正读和反读都一样
        hash_table,res,flag={},[],0
        for i in s:
            hash_table[i]=0
        for i in s:
            hash_table[i]+=1
        a=sorted(hash_table,key=lambda x:hash_table[x])
        for i in a:
            if hash_table[i]%2!=0:
                res.append(i)
                hash_table[i]-=1
                break
        for i in range(len(a)):
            while True:
                if hash_table[a[i]]>=2:
                    res.append(a[i])
                    res.insert(0,a[i])
                    hash_table[a[i]]-=2
                else:
                    break        
        return len(''.join(res))
```