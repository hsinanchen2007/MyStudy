### 解题思路
按部就班

### 代码

```python
class Solution(object):
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """

        ori= ''.join([x for x in licensePlate.lower() if x.isalpha()])
        from collections import Counter
        target=Counter(ori)
        # for c,n in target.items():
        #     print c,n
        def checkone(word,target):

            word=Counter(word)
            # print word
            
            for char,num in target.items():
                # print  char in word.keys() 
                if char in word.keys() and word[char]>=num:
                    continue
                else:
                    # print 'f.24'
                    return False
            # print 'true.26'
            return True
        result=''
        for word in words:
            if checkone(word,target):
                if not result:
                    result=word
                else:
                    result=word if len(result)>len(word) else result
        return result
        
```