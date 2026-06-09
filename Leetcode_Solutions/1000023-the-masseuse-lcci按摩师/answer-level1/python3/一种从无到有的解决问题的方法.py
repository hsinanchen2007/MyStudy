### 解题思路
有一组数abcdefg，可以视为：

a+b+c+X。a是开始，b是必须休息，c是最多的情况,X是（0~无限大）的数。
这时候有以下几个值需要对比大小：ac,b

a+b+c+d+X。a是开始，b是必须休息，c是最多的情况，d是因为选了c没能选的。
这时候有以下几个值需要对比大小：ac,bd,ad
上一步ac和b做了对比，所以：
若b<=a,则bd<=ad,
若ac<b,则必定ad<acd<bd；若ac>b,则
        

### 代码

```python3
class Solution:
    def massage(self, nums: List[int]) -> int:
        '''
    i=3                 结果1:B<=A       结果2:AC<=B       结果3:AC>B
        a+b+c            a+c                b               a+c

    i=4  #结果1：可以认为abcd是aacd
        aa+c+d           a+d                a+c             a+d
         #非结果1：
        bb+c+d           b+d                b+c             b+d

        '''

        #预约小于3个的时候
        if len(nums)==0:
            return 0
        if len(nums)==1:
            return nums[0]
        if len(nums)==2:
            return max(nums[0],nums[1])

        #初始化结果                 第一次                              第二次
        res_max=0                   #存放最大数据                       
        re_1=nums[0]                #a      存放前2个预约   a           b
        re_2=nums[1]                #b      存放前一个预约  b           ac
        i=3
        while i<=len(nums):         #ab+c时                             abc+d时
            if re_2<=re_1:          #若b<=a,abcd...可以认为是aacd...
                re_2=re_1
                re_1+=nums[i-1]
                res_max=re_1        #ac最大
            else:                   #若b>a,则需要确认ac和b的大小
                re_1+=nums[i-1]         #ac
                if re_1<=re_2:          #如果ac<=b,abcd...可以认为是bd...
                    res_max=re_2
                else:                   
                    #如果ac>=b,返回ac.   #如果ac>b,需要下一个数d来判断大小
                    res_max=re_1
            re_1,re_2=re_2,re_1  #往后走一步，前一个预约是ac,前2个预约是b
            i+=1

        return res_max        

```