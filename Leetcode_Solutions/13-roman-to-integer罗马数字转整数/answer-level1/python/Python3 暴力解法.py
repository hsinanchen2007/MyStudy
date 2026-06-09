从罗马数字我们可以得出这么一条规律：
从左往右一位一位的看，如果这一位数字比它右边一位的数字大或与其相等，则加上这一位代表的值，如果它比右边一位小，则减去这一位代表的数字。
例如： 'MMCMLXIV': 第一位是M，它的后一位也是M，所以 num = 0 + 1000，之后 M > C, num = num + 1000 =2000,之后到特殊值，因为C<M，所以num=num-C =2000-100=1900,之后再加上1000得到 num=2900……以此类推进行下去，最后可得到 num = 2964
需要注意的是，位与后一位的比较只需进行到倒数第二位即可，因为最后一位没有比它小的一位能够进行比较，直接加上最后一位代表的值即可。

```
代码块
class Solution:
    def romanToInt(self, s: str) -> int:
        roma_nums = {'M':1000,'D':500,'C':100,'L':50,'X':10,'V':5,'I':1}
        num = 0
        for i in range(len(s)-1):
            if roma_nums[s[i]]>=roma_nums[s[i+1]]:
                num += roma_nums[s[i]]
            else:
                num -= roma_nums[s[i]]
        last_num = s[len(s)-1]
        num = num + roma_nums[last_num]
        return num
            
```
