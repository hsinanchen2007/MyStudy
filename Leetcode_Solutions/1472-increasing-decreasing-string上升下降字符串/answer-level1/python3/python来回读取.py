### 解题思路
1.去除重复字符后排序，然后将s中出现的每种字符的数量统计出来（类似官方的设置“桶”，我这个笨了点）
2.然后进行“山峰式”地读取（下标0 1 2 3 3 2 1 0 0 1..）读取一次计数-1，为0则读取下一个
即可得到山峰字符串
### 代码

```python3
class Solution:
    def sortString(self, s: str) -> str:
        str_s = set(s)
        str_l = list(str_s)
        str_l.sort()
        num_arr = []
        for item in str_l:
            num_arr.append(s.count(item))
        
        flag = 0
        cnt = 0
        ans = ''
        while flag != len(s):
            if cnt == 0:
                for i in range(len(str_l)):
                    if num_arr[i]!=0:
                        ans += str_l[i]
                        num_arr[i] -= 1
                        flag += 1
                cnt = 1
            else:
                for i in range(len(str_l)-1, -1, -1):
                    if num_arr[i]!=0:
                        ans += str_l[i]
                        num_arr[i] -= 1
                        flag += 1
                cnt = 0
        return ans




```