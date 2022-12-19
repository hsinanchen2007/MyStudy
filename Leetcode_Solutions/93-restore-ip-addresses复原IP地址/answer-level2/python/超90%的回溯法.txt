### 解题思路
采用一般的回溯题思路：

1. 当分割4段以后返回，并记录符合要求的path（即IP地址）
2. 每次分割以1——3个字符为一个小节
3. 每个小节保证转换整数的范围在0-255之间
4. 对分割首位含有'0'的小节直接跳过（不包括'0'单个字符的小节）

遇到问题：
1. 采用```int()```直接将str转换为字符串时：
- 无法转换'0'
- 无法采用```int(s[i:j])```之间转换

解决方案： 直接按位计算str
 
### 代码

```python3
class Solution:
    def restoreIpAddresses(self, s: str) -> List[str]:
        ret=[]
        def find(path,s,n):
            
            # print(path)
            if n==0 and s:
                # print(s,type(s))
                ln=len(s)
                if ln>1 and s[0]=='0':
                    return
                if ln<=3:
                    t=0
                    for i in range(ln):
                        t=t*10+int(s[i])
                    # print(s+"/",path+"/",t)
                    if t<=255:
                        ret.append(path+s)
                        # print(ret)
                return
            lens=(len(s))
            l=3
            if lens<3:
                l=lens
            t=0
            s2=""
            for i in range(l):
                t=t*10+int(s[i])
                s2+=s[i]
                # print(t,type(t))
                if len(s2)>1 and s2[0]=="0":
                    continue
                if t<=255 :
                    path2=path+s2+'.'
                    # print(path+"/",s2+"/",path2)
                    find(path2,s[i+1:],n-1)
        find("",s,3)
        return ret




```