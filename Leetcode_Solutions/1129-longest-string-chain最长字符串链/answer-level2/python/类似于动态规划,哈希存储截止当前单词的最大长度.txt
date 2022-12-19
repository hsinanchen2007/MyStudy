### 解题思路
有点像那个,连续最大递增数组长度

### 代码

```python
class Solution(object):
    def longestStrChain(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        def judgein(a,b):
            #a if b child
            if len(b)-len(a)!=1:
                return False
            ai,bi=0,0
            # print a,b
            while  ai<len(a) and a[ai]==b[bi]  :
                ai+=1
                bi+=1
            # print ai,bi,a[ai:],b[bi+1:],'后缀相比',a[ai:]==b[bi+1:] or ai==len(a)
            if a[ai:]==b[bi+1:] or ai==len(a):
                return True
            else:
                return False
        
        worddict={}
        resword={}
        for word in words:
            if len(word) not in worddict:
                worddict[len(word)]=[word]
            else:
                worddict[len(word)].append(word)
        result=0
        #类似于动态规划,储存截止每个单词,迄今为止的最长子连长度
        # print sorted(worddict.items(),key=lambda x :x[0])
        for i,wordlist in sorted(worddict.items(),key=lambda x :x[0]):
            for oneword in wordlist:
                if i-1 in worddict:
                    for beforeword in worddict[i-1]:
                        if judgein(beforeword,oneword):
                            # print oneword,beforeword
                            resword[oneword]=max(resword.get(oneword,1),resword.get(beforeword,1)+1)
        # print resword.items()
        return max(resword.values()) if resword else 1

```