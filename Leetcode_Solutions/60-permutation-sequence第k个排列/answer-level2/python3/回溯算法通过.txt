### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def __init__(self):
        self.res=''#找到满足条件的字符=res
        self.num=0 #统计递归满足条件的值的次数，最终判断self.num==k
    def getPermutation(self, n: int, k: int) -> str:
        s=''#首先定义一个空字符串s，然后将1-n数字添加道空字符串当中
        for i in range(1,n+1):self.num==k
            s+=str(i)
        def A(strs,s,k):
            if len(strs)==n:
                self.num+=1 
                if self.num==k:
                    self.res=strs
                return 
            for i in s:
                A(strs+str(i),s.replace(i,''),k)#此处只需注意s的值，将存在的i从字符串中去掉即可
                if self.num==k:
                    return self.res
                else:
                    continue
        A('',s,k)
        return self.res

```
差点超时啊！，个人感觉回溯算法的算法时间复杂度有点高额，不过比较好理解