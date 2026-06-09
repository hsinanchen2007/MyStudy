![image.png](https://pic.leetcode-cn.com/d4e70bb30ec43340e5fc2fae061f5051c8a26911361ea5578bfe87dd905401d4-image.png)

### 解题思路
思路还是很简单的：依次遍历，依次计数，遇见不同的就进行处理，注意的是，再遍历完成后，把最后的结果也加上去，也就是：compre_strs+=S[-count]+str(count)

### 代码

```

class Solution:
    def compressString(self, S: str) -> str:
        if S=="":
            return ""
        compre_strs = ""
        lens = len(S)
        count = 1
        for i in range(lens-1):
            if S[i]==S[i+1]:
                count+=1
            else:
                compre_strs+=S[i]+str(count)
                count = 1
        compre_strs+=S[-count]+str(count)
        if len(compre_strs)>=lens:
            return S
        else:
            return compre_strs
        
```