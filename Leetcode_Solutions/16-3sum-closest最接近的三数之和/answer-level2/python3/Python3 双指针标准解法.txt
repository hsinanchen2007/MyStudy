### 解题思路
有很多注释

### 代码

```python3
class Solution:
    def threeSumClosest(self, s: List[int], target: int) -> int:
        if len(s)<3: #极端条件，一般是数组长度太短
            return 0
        s.sort() #标准开头，先进行排序，之后就可以利用指标的加减进行逼近target而不是暴力搜索
        RE=sum(s[0:3]) #先计算一个默认值
        for i in range(len(s)): #标准格式，定死一个头
            j=i+1 #j越小越好
            k=len(s)-1 #k越大越好
            while j<k: #标准while语句
                temp=s[i]+s[j]+s[k] 
                if abs(target-RE)>abs(target-temp): #对比当前值和默认值谁更逼近target
                    RE=temp #将默认值更换为更接近的一个
                if temp==target: #逼近成功则之间返回
                    return temp
                elif temp<target: #若比目标值小则需增大当前值
                    j+=1 #因为数组是sorted的，所以增加j可以增加下一次计算的当前值
                else: #必定为目标值小于当前值的情况
                    k-=1 #通过移动下标来减小当前值
        return RE
```