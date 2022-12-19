### 解题思路
想把两种情况合并的，结果做到后面心态爆炸了。第三种怎么都揉不到一起。。。。

### 代码

```python3
class Solution:
    def longestPalindrome(self, s: str) -> str:
        '''
        思路一：
        回文的两种情况：XaaY,XabaY              第三种：Xa..aY
        决定了需要3个数据做对比，找到回文后向2头扩展，寻找是否有XbaabY,或者 XcabacY
        '''
        if len(s)==0:
            return s
        if len(s)<=2 :
            if s[0] != s[-1]:
                return s[0] 
            else:
                return s

        i=2
        hw_max=0
        results=s[0]
        if s[0]==s[1]:
            results=s[0:2]
        while i<len(s):
            j=0
            k=0
            hw_len2=hw_len=0
            if s[i]==s[i-1] or s[i]==s[i-2]:        #出现了回文
                if s[i]==s[i-2]:                    #第2种情况
                    i1=2
                    if s[i]==s[i-1]:                #出现XaaaY
                        only_onecha=True
                    else:
                        only_onecha=False        
                    while s[i+j]==s[i-i1-j]:            #往2边查，一致时回文长度+2
                        j+=1
                        if s[i-i1-j]!=s[i-i1-j+1]:
                            only_onecha=False           #说明回文里有其他字符
                        if i+j>=len(s) or i-i1-j<0:
                        #退出之前判断回文串只有1个字母,且回文串左侧有一个相同的字母需要加进来
                            if only_onecha==True and s[i-i1-j]==s[i-i1-j+1] and i-i1-j>=0:
                                only_onecha=True
                            else:
                                only_onecha=False
                            break
                    hw_len=2*j+i1-1+int(only_onecha)            #当前回文长度
                
                #'''
                if s[i]==s[i-1]:                               #第1种情况
                    i2=1
                    only_onecha2=True
                    while s[i+k]==s[i-i2-k]:            #往2边查，一致时回文长度+2
                        k+=1
                        if s[i-i2-k]!=s[i-i2-k+1]:
                            only_onecha2=False           #说明回文里有其他字符
                        if i+k>=len(s) or i-i2-k<0:
                        #退出之前判断回文串只有1个字母,且回文串左侧有一个相同的字母需要加进来
                            if only_onecha2==True and s[i-i2-k]==s[i-i2-k+1] and i-i2-k>=0:
                                only_onecha2=True
                            else:
                                only_onecha2=False
                            break
                    hw_len2=2*k+i2-1+int(only_onecha2)            #当前回文长度
                #'''

                if hw_len2>hw_len:
                    hw_len=hw_len2
                    j,i1=k,i2
                    only_onecha=only_onecha2
                if hw_max<hw_len:
                    results=s[i-i1-j+1:i+j]
                    #return results
                    if only_onecha==True:
                        results=s[i-i1-j:i+j]
                    hw_max=len(results)
            i+=1
        return results
```