class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        folder=sorted(folder)   #按照字典序排序
        res=["0"]
        for f in folder:
            if not f.startswith(res[-1]+"/"):   #需要加"/"，保证是下一级，而不是目录名不同
                res.append(f)
        return res[1:]
                