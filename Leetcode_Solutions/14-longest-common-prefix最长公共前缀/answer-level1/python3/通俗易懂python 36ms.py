class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        # return os.path.commonprefix(strs)
        if not strs:
            return ""
        if len(strs)==1:
            return strs[0]
        l=min(strs, key=len)
        def cut(x):
            if len(x)<=2:
              return x
            short_str=len(l)
            return x[:short_str]
        result=list(map(cut,strs))
        cnt=0
        str=""
        add=True
        for i in l:
            for j in result:
                if i != j[cnt]:
                    add=False
            if add:
                str+=i   
            cnt+=1
            
        return str
            
            