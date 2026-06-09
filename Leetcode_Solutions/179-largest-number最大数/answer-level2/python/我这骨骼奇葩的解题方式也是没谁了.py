### 解题思路
 本题的关键是在两个数的大小比较，有了比较函数后，冒泡排序，插入排序、快速排序等等都可以搞定

 #### 于是我想到了： 比较两个数第一位谁大，如果相等继续比下一位，如果短的那个数到了末尾，就从头再开始取第一位数。直到长的那个数遍历到末尾 #### 
 #### 解完后看别人的答案才发现自己太蠢了。。。 大小比较明明可以用a+b 和b+a比较大小 简单明了 我擦。。。 ####
### 代码

```python
class Solution(object):
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """

        def get_first_num(a):
            return a[0]

        def compare(x,y):
            x=str(x)
            first_x=x
            y=str(y)
            first_y=y
            pos=0
            while(True):
                if get_first_num(x) > get_first_num(y):
                    return True
                if get_first_num(x) < get_first_num(y): 
                    return False
                if get_first_num(x) == get_first_num(y) and len(x)<=1 and len(y)<=1:
                    for idxx in range(len(first_x)+len(first_y)):
                        x=first_x[(pos+1)%len(first_x)]
                        y=first_y[(pos+1)%len(first_y)] 
                        if x>y:
                            return True
                        if x<y:
                            return False
                        pos=pos+1
                    return True
                        

                if len(x)>= 2 :
                    x=x[1:]
                else:
                    x=first_x[(pos+1)%len(first_x)]
                if len(y)>= 2:
                    y=y[1:]
                else:
                    y=first_y[(pos+1)%len(first_y)]
                pos=pos+1

        sorted_nums=sorted(nums,cmp=lambda x,y:-compare(x,y))
        s=''
        for m in sorted_nums:
            s=s+str(m)
            
        s=str(int(s))
        return s
```