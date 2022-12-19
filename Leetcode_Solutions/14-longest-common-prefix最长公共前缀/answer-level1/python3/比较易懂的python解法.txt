class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if len(strs) == 0:
            return ""
        min=len(strs[0])
        list ,strs_tem= [],[]
        for str in strs:
           if min > len(str):
               min = len(str)
        for i in range(min):
            strs_tem = [str[i]  for str in strs]
            if len(set(strs_tem)) ==1:
                list.append(strs_tem[0])
            else:
                break
        return  "".join(list)