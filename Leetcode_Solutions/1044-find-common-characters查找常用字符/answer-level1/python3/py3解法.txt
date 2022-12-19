思路：
1、创建一个保存字母出现次数的map命名d，key是a~z，值都是101，假设每个字母出现101次；
2、遍历数组A，每处理一项，更新一次d,当前单词出现过的字母记录出现次数，没出现过的字母值设置为0；
3、遍历处理完之后，新建结果数组r，把d中值大于0的单词输出到r数组中。

```
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        d = {}
        for a in range(ord('a'), ord('z') + 1):
            d[chr(a)] = 101
        for i in range(len(A)):
            d_i = {}
            for j in A[i]:
                if j in d_i:
                    d_i[j] += 1
                else:
                    d_i[j] = 1
            for k in d:
                if k in d_i:
                    d[k] = min(d[k], d_i[k])
                else:
                    d[k] = 0
        r = []
        for k in d:
            if d[k] > 0:
                for i in range(d[k]):
                    r.append(k)
        return r
```
