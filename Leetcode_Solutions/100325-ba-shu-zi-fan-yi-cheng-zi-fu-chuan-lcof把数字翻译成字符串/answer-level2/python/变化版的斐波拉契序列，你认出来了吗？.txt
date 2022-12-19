### 解题思路
观察序列，把数拆分成一位一位。每当新增加一位，分析它的前一位，

如果(0<int(s[i-2])<3 and int(s[i-1])<6) or int(s[i-2])==1，说明
1、新增加的这位数字可以和前一位组合起来翻译，那么就和前一位的前一位数量一样多，即f(n-2)，
2、新增加的一位也可以单独翻译，那么就和新增加的前一位一样多即f(n-1)。-----总数是不是f(n)=f(n-1)+f(n-2)---是不是斐波拉契数列

如果不是上述条件：
1、新增加的那位只能单独翻译，就和它的前一位一样多，即f(n)=f(n-1)

最后写成循环形式的斐波拉契序列，时间复杂度O(N),空间复杂度O(1)

### 代码

```python3
class Solution:
    def translateNum(self, num: int) -> int:
        s=str(num)
        x,y=1,1
        if len(s)<2:
            return 1
        for i in range(2,len(s)+1):
            if (0<int(s[i-2])<3 and int(s[i-1])<6) or int(s[i-2])==1:
                x,y=y,x+y
            else:
                x,y=y,y
        return y


```