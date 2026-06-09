首先对列表A中所有元素逐一按字母大小排序
随后遍历A[0]并保存已遍历过的字母

遍历至某一字母时根据：
1.该字母曾被遍历过且已输入结果列表
2.该字母曾被遍历过但未输入结果列表
3.该字母第一次被遍历到
三种不同情况做处理

情况2可直接continue遍历下一字母
情况3需根据当前遍历字母已使用过的次数将字母串乘以相应倍数再去A[0]之后的各个元素中查找子串
```
class Solution:
    def commonChars(self, A: List[str]) -> List[str]:
        for i in range(len(A)):
            A[i] = "".join((lambda x:(x.sort(),x)[1])(list(A[i])))
        B = []
        used = ""
        for i in range(len(A[0])):
            if A[0][i] in used and A[0][i] in "".join(B):
                for j in range(1, len(A)):
                    if A[0][i] * (used.count(A[0][i]) + 1) not in A[j]:
                        break
                    if j == len(A) - 1:
                        B.append(A[0][i])
                used += A[0][i]
            elif A[0][i] in used and A[0][i] not in "".join(B):
                continue
            else:
                for j in range(1, len(A)):
                    if A[0][i] not in A[j]:
                        break
                    if j == len(A) - 1:
                        B.append(A[0][i])
                used += A[0][i]
        return B

```
