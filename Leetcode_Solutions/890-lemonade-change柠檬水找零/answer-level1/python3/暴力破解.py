### 解题思路
使用字典记录５元和１０元分别有多少．

### 代码

```python3
class Solution:
    def lemonadeChange(self, bills: List[int]) -> bool:
        dict1={5:0,10:0}
        for i in bills:
            if i==5:
                dict1[5]+=1
            elif i==10 and dict1[5]>0:
                dict1[5]-=1
                dict1[10]+=1
            elif i==20:
                if dict1[10]>=1 and dict1[5]>=1:
                    dict1[10]-=1
                    dict1[5]-=1
                elif dict1[5]>=3:
                    dict1[5]-=3
                else:
                    return False
            else:
                return False
        return True 
```