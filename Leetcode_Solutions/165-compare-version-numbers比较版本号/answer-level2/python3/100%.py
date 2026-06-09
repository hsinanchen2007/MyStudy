![image.png](https://pic.leetcode-cn.com/7bdbb474390390415d93cbb9b9a7a2da3f344e04f8d7b341de88bc4dc5a18a17-image.png)

快是偶然，慢的时候也测出60-76ms

```
class Solution:
    def compareVersion(self, version1: str, version2: str) -> int:
        s1,s2=[int(i) for i in version1.split('.')],[int(i) for i in version2.split('.')]#分割
        n1,n2=len(s1),len(s2)
        while n1>0:#删除末尾的0元素
            if s1[n1-1]!=0:break
            n1-=1
        while n2>0:
            if s2[n2-1]!=0:break
            n2-=1
        n=min(n1,n2)
        for i in range(n):#比较重叠部分大小
            if s1[i]<s2[i]:
                return -1
            elif s1[i]>s2[i]:
                return 1
        #重叠部分一致则跳出循环
        if n1==n2:
            return 0
        else:#如果不重叠肯定是短的小，反之亦然
            return -1 if n1<n2 else 1
```
