
第一步：

    先遍历一遍，用字典存储每个字符最后的位置。

第二步：
    从第一个字符开始遍历，每获取一个字符就该字符最后一次出现的位置索引定为当前片段的最后位置，
    在达到该位置之前，继续寻找更靠后的最后位置，若达到最后位置之前都没有发现更靠后的最后位置，则将当前最后位置作为一个片段的末尾， 


    class Solution:
        def partitionLabels(self, S: str) -> List[int]:
            dic = {}
            for i ,s1 in enumerate(S):
                dic[s1] = i
            result = []
            cur = dic[S[0]]
            for i ,s1 in enumerate(S):
                if dic[s1] > cur :
                    cur = dic[s1]
                if i == cur :
                    result.append(cur+1-sum(result))
            return result