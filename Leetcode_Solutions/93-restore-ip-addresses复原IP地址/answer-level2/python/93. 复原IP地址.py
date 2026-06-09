### 解题思路
感谢官方题解 回溯算法

### 代码

```python
class Solution(object):
    def restoreIpAddresses(self, s):
        self.ans = []
        self.Seg = []
        self.address(s,-1,3)
        return self.ans

    #判断每一节的数字是否满足Ip地址条件
    def address(self,s,prepos,dots):
        for curpos in range(prepos + 1,min(len(s) - 1,prepos + 4)):
            seg = s[prepos+1:curpos+1]
            if self.cangetadd(seg):
                self.Seg.append(seg)
                #当最后一个"."放置完，看最后一个字段是否满足条件
                if dots - 1 == 0:
                    self.ipaddress(curpos,s)
                else:
                    self.address(s,curpos,dots - 1)
                self.Seg.pop()
            
    #最后字段满足，输出可能结果
    def ipaddress(self,curpos,s):
        s_last = s[curpos + 1:]
        if self.cangetadd(s_last):
            self.Seg.append(s_last)
            self.ans.append(".".join(self.Seg))
            #继续组合
            self.Seg.pop()
            return self.ans

    #判断每一字段是否满足条件
    def cangetadd(self,seg):
        if (int(seg) == 0 and len(seg) == 1) or (int(seg) <= 255 and seg[0] != '0'):
            return True
        else:
            return False



```