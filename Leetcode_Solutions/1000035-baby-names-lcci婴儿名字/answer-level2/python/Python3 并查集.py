### 解题思路
并查集

### 代码

```python3
class Solution:
    def trulyMostPopular(self, names: List[str], synonyms: List[str]) -> List[str]:
        names_dict = dict() #改名为cnt更好
        parent = {key:key for key in names_dict}
        for name in names:#这里可以再优化,我有些啰嗦了
            name_lst1 = name.split("(")
            name_lst2 = name_lst1[1].split(")")
            names_dict[name_lst1[0]] = int(name_lst2[0])
        parent = {key:key for key in names_dict}
        #下面这步确定没必要么? 如果一个name再synonyms里有,但names里没有, 又恰好这个name是真是name呢???
        #print(names_dict)
        # for item in synonyms:
        #     name1,name2 = item.split(",")
        #     name1,name2 = name1[1:],name2[:-1]
        #     if name1 not in names_dict:
        #         names_dict[name1] = 0
        #     if name2 not in names_dict:
        #         names_dict[name2] = 0
        
        parent = {key:key for key in names_dict}
        
        def find_root(name):
            while parent[name] != name:
                name = parent[name]
            return name

            
        def union(name1,name2): #这里一开始做错了, 忘了把name替换为root了
            root1 = find_root(name1)
            root2 = find_root(name2)
            if root1 < root2:
                parent[root2] = root1
            else:
                parent[root1] = root2

        for item in synonyms:
            name1,name2 = item.split(",")
            name1,name2 = name1[1:],name2[:-1]
            if parent.get(name1) is None or parent.get(name2) is None: continue
            union(name1,name2)
        res = collections.defaultdict(int)
        #print(parent)
        for key,val in parent.items():
            res[find_root(val)] += names_dict[key] #这里一开始做错了, 没有加find_root,所以就只得到了parent的.
        print(res)
        return [ key +'(' +str(val)+')' for key,val in res.items()]



```