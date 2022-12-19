![捕获.JPG](https://pic.leetcode-cn.com/a7d6a81d5cb194a3f60928359c33c26a95a56c59a7d34e6452e209e91e9199ea-%E6%8D%95%E8%8E%B7.JPG)


```
class Solution:
    def simplifyPath(self, path: str) -> str:
        import re
        path=path.rstrip("/")      #去除尾部 /
        path=re.sub("/+","/",path)  #去除多余 /
        if not path.startswith("/"): #如果不是以 / 开头，开头加 /
            path="/"+path
        
        path_lst=path.split("/")    # 以/分割路径，注意：path_lst[0]==""
        
        stack=[""]                  #维护的栈
        for p in path_lst[1:]:
            if p=="..":             #如果指向上级目录
                if stack[-1]!="":   #如果当前目录不是根目录
                    stack.pop()     #出栈
            else:
                if p!=".":          #不是指向当前目录
                    stack.append(p) #入栈
        if len(stack)==1:           #结果只剩根目录，返回 "/"
            return "/"
        return "/".join(stack)  
```


