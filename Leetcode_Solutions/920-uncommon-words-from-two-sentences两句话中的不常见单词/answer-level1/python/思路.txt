### 解题思路
思路：
1.把Ａ、B句子都加入到ｄｉｃ中，建立dic_A,dic_B,key 存word value存出现次数。
2.把出现次数为1的word并且没有在另一个dic中出现的word加入到res_list
  对两个dic进行同样的 遍历 
3.对res_list 去重。

踩坑：
1.本来只想把出现次数为1次的word加入list，如果出现过 就del dic，但是没有考虑到 a a a情况，加入 删除 加入，就又加入字典了，造成提交之后错误。
2. 句子要按空格分割 加入字典。

### 代码

```python3
class Solution:
    def uncommonFromSentences(self, A: str, B: str):
        dic_A = {}
        dic_B = {}
        cnt = 0
        for aa in A.split(' '):
            if aa in dic_A:
                dic_A[aa] = dic_A[aa] + 1
                # del dic_A[aa]
            else:
                dic_A[aa] = 1
        for bb in B.split(' '):
            if bb in dic_B:
                dic_B[bb] += 1
                # del dic_B[bb]
            else:
                dic_B[bb] = 1
        res_list = []
        for key in dic_A:
            if key not in dic_B and dic_A[key] == 1:
                res_list.append(key)
            else:
                continue
        for kk in dic_B:
            if kk not in dic_A and dic_B[kk] == 1:
                res_list.append(kk)
            else:
                continue
        res_list = list(set(res_list))
        return res_list

```