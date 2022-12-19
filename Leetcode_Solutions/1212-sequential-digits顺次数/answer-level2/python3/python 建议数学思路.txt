### 解题思路
此处撰写解题思路
不是回溯算法

就是计算low,high的位数，
比如是3，和5位
那么就从
123开始到789
1234到6789
12345到56789
看是否在low,high 的区间即可。

然后有一些辅助函数。


### 代码

```python3
class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        def bit(num):
            ans = 0
            while num:
                num = num//10
                ans+=1
            return ans
        
        l = bit(low)
        h = bit(high)

        def ordernum(bits):
            ans = 0
            index=1
            while index<=bits:
                ans= ans*10+index
                index+=1
            return ans
        
        def get_1(bits):
            ans = 0
            index=1
            while bits:
                ans= ans*10+index
                bits-=1
            return ans
        
        def judge_gewei(num):
            while num>10:
                num = num%10
            return num

        ans = []
    
        for i in range(l,h+1):
            d = ordernum(i)
            addnum = get_1(i)
            gewei = judge_gewei(d)
            # print(d,addnum,gewei)
            while 1:
                if d<=high and gewei!=0:
                    if low<=d:
                        ans.append(d)
                    d+=addnum
                    gewei+=1
                    gewei = gewei%10
                elif d>high or gewei==0:
                    break                                    
        return ans

                    





```