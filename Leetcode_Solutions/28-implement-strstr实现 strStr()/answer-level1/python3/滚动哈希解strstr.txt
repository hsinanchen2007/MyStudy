### 解题思路
本质上来说还是去遍历探索haystack的每个元素，判断以当前元素为开始，长度为len(needle)的haystack的子串是否等于needle，只是判断相等方法不同，可以用双指针一个一个元素去比较，也可以计算各自对应的哈希值是否相同去比较(这里需要注意)，并且算出第一个哈希后，可以利用滑动窗口的特性，可以在常熟空间内内算出每一个滑动窗口对应的哈希值

### 代码

```python
class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        L, n = len(needle), len(haystack)
        if L > n:
            return -1
        
        # base value for the rolling hash function
        a = 26
        # modulus value for the rolling hash function to avoid overflow
        modulus = 2**31
        
        # lambda-function to convert character to integer
        h_to_int = lambda i : ord(haystack[i]) - ord('a')
        needle_to_int = lambda i : ord(needle[i]) - ord('a')
        
        # compute the hash of strings haystack[:L], needle[:L]
        h = ref_h = 0
        for i in range(L):
            h = (h * a + h_to_int(i)) % modulus
            ref_h = (ref_h * a + needle_to_int(i)) % modulus
        if h == ref_h:
            return 0
              
        # const value to be used often : a**L % modulus
        aL = pow(a, L, modulus) 
        for start in range(1, n - L + 1):
            # compute rolling hash in O(1) time
            h = (h * a - h_to_int(start - 1) * aL + h_to_int(start + L - 1)) % modulus
            if h == ref_h and haystack[start:start+L] == needle :
                return start

        return -1
```