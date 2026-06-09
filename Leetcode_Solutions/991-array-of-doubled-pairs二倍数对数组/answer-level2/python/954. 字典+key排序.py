### 解题思路
使用字典,key为A里的数，value为A里的数的频率，按照健值从小到大进行排序进行如下操作，假设当前健值为x, 如果x和2x的value都大于0，就让x和2x对应的value减一，这样就消去了一对。
下面思考这样一个问题，以这个数组为例，[-8,-4,-2,-1,0,0,1,2,4,8]，怎么杨确定-4是和-8组成一对还是-4和-2组成一对呢？只需将字典里key排序操作即可，从大到小或从小到大都可以。要使数组恰好匹配完，则负绝对值最大的数一定要和刚好是它一半的数组队，否则该数则落单。正绝对值最小的数肯定要与他的两倍组对。
最后，判断字典是否还有频率为非零的元素即可
### 代码

```python
class Solution(object):
    def canReorderDoubled(self, A):
        
        myDict = {}
        for item in A:      
            if item not in myDict:
                myDict[item] = 1
            else:
                myDict[item] += 1
        for item in sorted(myDict.keys()):
            for i in range(0,myDict[item]):
                if (2*item in myDict) and myDict[2*item] > 0 and myDict[item] > 0:
                    myDict[2*item] -= 1
                    myDict[item]  -= 1

        for item in myDict.keys():
            if myDict[item] > 0:
                return False
        return True
```