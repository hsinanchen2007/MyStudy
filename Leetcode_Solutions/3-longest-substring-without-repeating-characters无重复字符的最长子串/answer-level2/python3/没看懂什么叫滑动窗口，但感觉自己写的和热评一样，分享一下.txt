没看懂滑动窗口的原理，但觉得自己应该用的就是这个。下面是字典法的思路：
1.从左遍历字符串，用字典保存每一个字符的序号，定义left作为左指针
2.每遍历一个字符，检索其是否已经出现。
3.如果出现，称原字符为pre，当前字符是cur。利用max函数将left->cur的子串长度和用来保存最终结果的count进行更新。然后再利用max将left更新至pre的下一位（之所以加上max，是为了解决abba这种情况，防止left向左移动）
4.不管cur是否已经出现，将cur的序号更新进字典
5.最后注意末尾序列，用max处理一下
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        #用列表的切片法
        #left,re=0,0
        #for i in range(len(s)):
         #   if s[i] in s[left:i]:
          #      re,left=max(re,i-left),s[left:i].index(s[i])+left+1
        #return max(re,len(s)-left)
        
        #用字典实现哈希
        left,re,count=0,{},0
        for i in range(len(s)):
            if s[i] in re.keys():
                count=max(count,i-left) 
                left=max(re[s[i]]+1,left) 
            re[s[i]]=i
        return max(count,len(s)-left)
```
