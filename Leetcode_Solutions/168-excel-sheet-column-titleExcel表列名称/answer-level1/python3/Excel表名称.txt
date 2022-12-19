```python
class Solution(object):
    def convertToTitle(self, n):
        """
        :type n: int
        :rtype: str
        """
        chaDic = {1:'A', 2:'B', 3:'C', 4:'D', 5:'E', 6:'F', 7:'G', 8:'H', 9:'I', 10:'J', 11:'K'
                  , 12:'L', 13:'M', 14:'N', 15:'O', 16:'P', 17:'Q', 18:'R', 19:'S', 20:'T', 21:'U'
                  , 22:'V', 23:'W', 24:'X', 25:'Y', 26:'Z'}      #注意，没有0对应的字母
        rStr = ""
        while n!=0:
            if n<=26:
                rStr = chaDic.get(n)+rStr
                n = 0
            else:
                res = n%26
                if res == 0:     #因为没有0对应的字母，所以如果余数为0的话需要自动提出26
                    res = 26
                    n -= 26
                rStr = chaDic.get(res)+rStr
                n = n//26
        return rStr