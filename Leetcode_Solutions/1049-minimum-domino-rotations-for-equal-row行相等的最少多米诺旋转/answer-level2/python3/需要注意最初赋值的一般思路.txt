### 解题思路
AB同时确认，但是受到最初赋值的影响，会有冤假错案
如12211111、21111111 ：
A变为（11111111），需要2次;B变为（22222222），需要7次。
这是由于B开始时给的是2，其实可以不考虑相同的部分（8-5）,
比较B需要翻转到A的次数2次，和A翻转到B的次数（8-5-2=）1次

### 代码

```python3
class Solution:
    def minDominoRotations(self, A: List[int], B: List[int]) -> int:
        '''
        思路一：确认AB里有没有len(A)个，但是还是需要在数组里确认数组，太复杂
        思路二：不新增。AB同时确认，但是受到最初赋值的影响，会有冤假错案
        如12211111、21111111  ：
        A变为（11111111），需要2次;B变为（22222222），需要7次。
        这是由于B开始时给的是2，其实可以不考虑相同的部分（8-5）,
        比较B需要翻转到A的次数2次，和A翻转到B的次数（8-5-2=）1次

        对11113/21311等同样适用

        '''
        results=results_B=0
        A_num=A[0]
        B_num=B[0]
        C_num=0                             #记录上下一致的次数

        for i in range(1,len(A)):
            if A[i]==A_num:
                pass
                #continue
            elif B[i]==A_num:
                results+=1
            else:
                A_num=-1                              #A 放弃  交换次数改为20000
                results=20000

            if B[i]==B_num:
                pass
                #continue
            elif A[i]==B_num:
                results_B+=1
            else:
                B_num=-1                              #B 放弃  交换次数改为20000
                results_B=20000
            
            if B[i]==A[i]:
                C_num+=1                            #记录相同的次数

        results=min(results,results_B)              #AB方案里那个小采用哪一个，比如采用A
        if results==20000:
            return -1
        results=min(results,len(A)-C_num-results)   #B方案也没放弃，把A翻过来再试一次
        return results
```