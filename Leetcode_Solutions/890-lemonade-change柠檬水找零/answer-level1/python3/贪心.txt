### 解题思路
此处撰写解题思路
一开始以为每收一次钱，即增加5元，却没有考虑到还有5元纸币和10元纸币之分
于是便以每一面值的数量作为变量，看每一次是否可以满足条件
### 代码

```python3
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        f=0;
        t=0;
        for bill in bills:
            if bill==5:
                f+=1;
            elif bill==10:
                if f==0:
                    return False;
                f-=1;
                t+=1;
            elif bill==20:
                if f and t:
                    f-=1;
                    t-=1;
                elif f>=3:
                    f-=3;
                else:
                    return False;
        return True;
```