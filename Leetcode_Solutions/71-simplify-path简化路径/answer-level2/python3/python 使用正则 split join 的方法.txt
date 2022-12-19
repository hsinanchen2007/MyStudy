先通过正则消除多余“/”
然后通过split形成list
循环遍历list 遇到“..” or “.” 特殊处理 其他直接放入新的list
然后用join方法返回结果

```python
class Solution:
    def simplifyPath(self, path: str) -> str:
        import re
        path=re.sub("/+/","/",path)
        path+="/"
        path=path.split("/")
        result=[]
        # for i in path:
        #      print("a=",i)
        for i in path:
            if i==".":
                continue
            elif  i =="":
                continue
            elif i=="..":
                if len(result) >0:
                    result.pop()
                continue
            else:
                print(i)
                result.append(i)
        # print(result)
        if len(result)==0 or result[0]=="..":
            return "/"
        return "/"+"/".join(result)

```