### 解题思路
此处撰写解题思路
通过寻找最大公因数的方法来解决（有点长篇大论了哈哈）
### 代码

```python3
class Solution:
    def mcp(self,Str): # 用来获得最小公共部分的方法（即找到字符串中最小的连接体）:
        Common = False
        for i in range(1,len(Str)):
            if len(Str)%i == 0:
                if Str[:i] == Str[i:2*i]:
                    for m in range(0,len(Str)-i,i):  # 此处m不能取到len（Str），否则m = len(Str)-i时，           Str[m+i:m+2*i]不存在，判别式 Str[m:m+i] == Str[m+i:m+2*i] 必为False。
                        if Str[m:m+i] == Str[m+i:m+2*i]:
                            Common = True
                        else:
                            Common = False
                            break  
                    if Common:
                        Common = Str[:i]
                        break      
        if Common == False: # 当字符串中无连接部分时，字符串整体为它的mcp，只不过只连接一次。
            Common = Str    
        return Common

    def gcdOfStrings(self, str1: str, str2: str) -> str:
        min_str1 = self.mcp(str1) # str1的最小公共部分
        min_str2 = self.mcp(str2)

        # 此时将问题转化为求取两字符串连接次数的最大公因子
        if min_str1 == min_str2:  # 若最小连接体不相等，则必不可能有最大公因子，返回空字符串''。
            max_l,min_l = int(max(len(str1)/len(min_str1),len(str2)/len(min_str2))),int(min(len(str1)/len(min_str1),len(str2)/len(min_str2))) # len(str1)/len(min_str1)为str1中连接体min_str1的连接次数，   max_l为str1、str2的连接次数中取最大值。
            # 下述过程为找到两字符串连接次数的最大公因子。
            times_list = [] # 用来储存较小连接次数min_l的因子
            for i in range(1,(min_l//2)+1):
                if min_l%i == 0:
                    times_list.append(i)
                    times_list.append(int(min_l/i)) # 注意：运算过程 a/b 得到的是一个浮点数（如2.0），此处必须加int。否则return min_str1*max_times时将无法成功返回max_times个最小公共部分。

            max_times = 1 # 将max_l和min_l的最大公因子初始化为1.
            for i in range(len(times_list)):
                if max_l%times_list[i] == 0 and times_list[i] > max_times:
                    max_times = times_list[i]

            return min_str1*max_times #（即为字符串的最大公因子）
        else:
            return ''
```