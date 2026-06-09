### 解题思路
考虑两种情况，子问题是该串的子串的所有情况，子串只与最后两位有关
用一个标识a来标识是否用到了倒数第二位数字，用到了，则为True
剩下的，根据是否是"*"或数字 暴力列出。。。
关于1,2,0都拉出来单独讨论一下
着实有点费劲啊。。。


### 代码

```python3
class Solution:
    def numDecodings(self, s: str) -> int:
        # 考虑两种情况，子问题是该串的子串的所有情况，子串只与最后两位有关
        list_one = [] # 只考虑最后一位数字
        list_two = [] # 考虑后两位数字
        m = 1000000007 
        temp=1 
        list_one.append(temp)
        temp_front=1
        list_two.append(temp_front)
        a = False # 标识是否用到了倒数第二位数字，用到了，则为True
        for i in range(len(s)):
            temp = list_one[i]
            temp_front = list_two[i]
            if s[i]!="*" and s[i]!="0":
                temp *= 1
                if (i-1)>=0 and s[i-1]!="*" and (s[i-1]=="1" or (s[i-1]=="2" and 0<int(s[i])<7)):
                    temp_front*=1
                    a = True
                elif i-1>=0 and s[i-1]=="*":
                    # temp *= 2
                    a = True
                    if 0<int(s[i])<7:
                        temp_front *= 2
                        temp_front %= m
                elif i-1>=0 and s[i-1]=='0':
                   temp=0
                else:
                    a = True
                    temp_front = 0
            if s[i]!="*" and int(s[i]) == 0:
                a=True
                temp = 0
                # if i-1>=0 and (int(s[i-1])==1 or s[i-1]==2):
                #     temp*=1
                if i-1>=0 and s[i-1]=="*": 
                    temp_front*=2
                    temp_front %= m
                elif i-1>=0 and 0<int(s[i-1])<3: 
                    temp_front*=1
                else:
                    a = True
                    temp = 0
                    temp_front = 0
                    return 0

            if s[i]=="*":
                temp *= 9
                temp%= m
                if i-1>=0: 
                    if s[i-1]!="*":
                        # temp -= 1
                        if int(s[i-1])==1:
                            a = True
                            temp_front *= 9
                            temp_front %= m
                        elif int(s[i-1])==2:
                            a = True
                            temp_front *= 6
                            temp_front %= m
                        # if int(s[i-1])==0:
                        #     a = True
                        #     temp_front =0
                        else:
                            a =True
                            temp_front=0
                            # temp=0
                    if s[i-1]=="*":
                        a = True
                        temp_front=temp_front*15
                        
            if a==True:
                temp=(temp +temp_front)
                temp%=m
                list_one.append(temp)
                # list_two.append(temp_front)
            else:
                list_one.append(temp)
            list_two.append(list_one[i])
        return list_one[-1]%m
        
```