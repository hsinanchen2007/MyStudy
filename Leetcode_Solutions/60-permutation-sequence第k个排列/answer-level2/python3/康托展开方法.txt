### 解题思路
康托展开是一个全排列到一个自然数的双射，常用于构建哈希表时的空间压缩。 康托展开的实质是计算当前排列在所有由小到大全排列中的顺序，因此是可逆的。
对于n=3，k=3，我们将k减1（k--）表示k之前有k-1个排列，然后用2 / (3-1)! =1 余 0表示第一位数小的只有1个，所以第一位数为1；然后我们对余数0去除以(2-1)!等于0余0，所以比第二位小的数只有0个，所以第二位数为1；接下来第三位数为3，所以n=3，k=3得到的全排列为213。

举例：
```
n=5,k=119

首先k--得到118，        nums=[1,2,3,4,5]
n=5   118/(5-1)!=4```22   则res第一位为nums[4]=5     nums=[1,2,3,4] 
n=4   22/(4-1)!=3```4     则res第一位为nums[3]=4     nums=[1,2,3]
n=3   4/(3-1)!=2```0      则res第一位为nums[2]=3     nums=[1,2]
n=2   0/(2-1)!=0```0      则res第一位为nums[0]=1     nums=[2]
n=1   0/(1-1)!=0```0      则res第一位为nums[0]=2     nums=[]

res="54312"

```


### 代码

```python3
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        
        tmp=1
        funs=[]
        nums=[]
        for i in range(1,n+1):
            funs.append(tmp)
            nums.append(i)
            tmp*=i
        k = k - 1
        res=""
        while n:
            x,y=k//funs[n-1],k%funs[n-1]
            res+=str(nums[x])
            nums.pop(x)
            k=y
            n-=1
        return res

```