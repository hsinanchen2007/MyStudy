看注释，很清楚。
```
class Solution:
    def numDecodings(self, s: str) -> int:
        l=len(s)
        if l==0:
            return 0 
        if l==1:
            return int(s[0]!='0')
        #以下均为l>=2的情况
        if s[0]=='0':   #首位为0无法解码，GG
            return 0
        d=[0 for i in range(l)]
        d[0],d[1]=1,int(s[1]!='0')  #d[i]表示截止到i(包括i)的字符串s[:i+1]的解码方法数
        if s[:2]<='26':
            d[1]+=1
        #上面初始化前两位，因为下面的循环有用到i-2索引
        for i in range(2,l):
            x=s[i-1:i+1]
            if s[i]=='0':   #当前元素是0
                if x>='1' and x<='26':  #0能够与前一位组成有效数（即前一位为1或2）
                    d[i]=d[i-2]
                else:   #连续两位为0则GG
                    return 0
            else:   #当前元素不是0
                if x>='1' and x<='26':   #若当前位能与前一位组成有效数，则两种情况加一起
                    d[i]=d[i-1]+d[i-2]
                else:   #只能当前位自己做码，d[i]就和前一位一样
                    d[i]=d[i-1]
        # print(d)
        return d[-1]
# print(Solution().numDecodings('226'))
```
