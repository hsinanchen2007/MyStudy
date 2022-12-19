### 解题思路
此处撰写解题思路
相当于利用三个指针，分别指向*2,*3,*5，判断当前指针指到的最小值，将此最小值累加到丑数列表中。
### 代码

```python3
class Solution:
    def nthUglyNumber(self, n: int) -> int:
        ugly=[1]
        temp=1
        i2=0
        i3=0
        i5=0
        while temp<n:
            u2,u3,u5=2*ugly[i2],3*ugly[i3],5*ugly[i5]
            target=min(u2,u3,u5)
            if target==u2:
                i2+=1
            if target==u3:
                i3+=1
            if target==u5:
                i5+=1
            temp+=1
            ugly.append(target)
        return ugly[-1]

```