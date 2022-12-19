### 解题思路
先将n转化成对于的二进制数，(bin(n)[2:]是去掉0b，这可要可不要，可直接s=bin（n）)，然后将二进制数转化成字符串，然后遍历字符串，统计‘1’的个数
小白不知道怎么添加图片，我点击添加图片显示的是图片的路径。总之，执行用时超过92%的同语言用户。

### 代码

```python3
class Solution:
    def hammingWeight(self, n: int) -> int:
        s = bin(n)[2:]
        ss = list(str(s))
        ans = 0
        n = len(ss)
        for i in range(0,n):
            if ss[i]=='1':
                ans +=1
        return ans
```