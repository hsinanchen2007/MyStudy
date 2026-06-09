![image.png](https://pic.leetcode-cn.com/3224fbb3298baf0d4e3eb450437ee4db3c75c77f15ea7857b786c76da423287a-image.png)
一直想怎么遍历一遍就出结果，一晚上没搞出来，有点生气，随便写个两次遍历的吧。。。
```
class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:

        a,b=None,None
        a_count,b_count=0,0
        for num in nums:
            if a is None:
                a=num
                a_count=1
            elif num==a:
                a_count+=1
            elif b is None:
                b=num
                b_count=1
            elif num==b:
                b_count+=1
            else:
                if a_count>=1 and b_count>=1:
                    a_count-=1
                    b_count-=1
                elif a_count>=1 and b_count==0:
                    b=num
                    b_count=1
                elif a_count==0 and b_count>=1:
                    a=num
                    a_count=1
                else:
                    a=num
                    b=None
        a_all,b_all,length=0,0,0
        for item in nums:
            length+=1
            if a is not None and a==item:
                a_all+=1
            elif b is not None and b==item:
                b_all+=1
        return [a,b] if a_all>length//3 and b_all>length//3  else [a] if a_all>length//3  else [b] if b_all>length//3 else []
```

