### 解题思路
这道题其实不用字典树。。。但是写都写了，还是发上来吧
思路就是先将字符串按照'/'拆开，然后对它建立字典树。在之后的字符串修改字典树

### 代码

```python3
class Solution:
    def removeSubfolders(self, folder: List[str]) -> List[str]:
        #思路：使用字典树
        #先把每个字符串变成列表
        folder_list = []
        for i in folder:
            folder_list.append(i.split('/')[1:])
        #建立字典树
        dict_tree = {}
        for i in range(len(folder_list)):
            current_list = folder_list[i]
            n = len(current_list)
            temp = dict_tree
            for j in range(n):
                if current_list[j] not in temp:
                    if j == n-1:
                        temp[current_list[j]] = None
                    else:
                        temp[current_list[j]] = {}
                        temp = temp[current_list[j]]
                else:
                    if j == n-1:
                        temp[current_list[j]] = None
                    else:
                        temp = temp[current_list[j]]
                        if temp == None:
                            break
        #拿到dict_tree，我们把它展开就是最终答案了
        #怎么展开呢？递归吧
        res =  []
        def unzip_dict_tree(tree,pre):
            for node in tree.keys():
                if tree[node] == None:
                    res.append(pre + [node])
                else:
                    unzip_dict_tree(tree[node],pre+[node])
        # print(dict_tree.keys())
        unzip_dict_tree(dict_tree,[])

        #最后组合成字符串
        for i in range(len(res)):
            res[i] = '/' + '/'.join(res[i])
        return res    

                        

```