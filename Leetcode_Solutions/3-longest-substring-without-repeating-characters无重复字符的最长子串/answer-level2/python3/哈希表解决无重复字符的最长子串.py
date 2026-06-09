### 解题思路
用哈希表存放上次出现的重复字母的位置，通过对字符串分割出备注里的3种结果。针对3种结果，取出最大值即可。

### 代码

```python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:

        '''
        对字符串xxxa*axxxb*bxxx

        需要2个参数：
        le_i记录a1,b1
        ri_i记录s[0],a2,b2

        输出的结果有：
        1.xxxa*      2.a*     3.axxxb*     4.bxxx
        结果3可以看成ri_i后移的结果1，忽略
        '''
        le_i=1
        ri_i=1
        len_ch1=0
        len_ch2=0
        results=0
        hashmap={}
        for ind,ch in enumerate(s):
            if hashmap.get(ch) is None:     #没重复则将字母出现的位置保存
                hashmap[ch]=ind+1
            else:                           #出现重复字母，如abca....
                le_i=hashmap[ch]            #取出重复字母上一次出现的位置
                len_ch1=ind+1-ri_i          #记录结果1
                if ri_i<=le_i:              #排除在这个字符串里有其他重复的字母，abbaxxx
                    len_ch2=ind+1-le_i      #记录结果2
                    ri_i=le_i+1             #记录的指针后移到a1后一位
                len_ch=max(len_ch1,len_ch2)
                if len_ch>results:          #如果本次的比较长就把这个值返回
                    results=len_ch
                hashmap[ch]=ind+1           #记录本次字母出现的位置

        len_ch=len(s)+1-ri_i                #结果4
        if len_ch>results:
                    results=len_ch
        return results


```