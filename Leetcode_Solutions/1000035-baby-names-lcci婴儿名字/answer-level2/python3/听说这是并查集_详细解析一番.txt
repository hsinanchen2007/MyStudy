### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def trulyMostPopular(self, names, synonyms):
        #对名单进行处理,g字典是个存根的字典,mzz字典是个寻名对应数的字典
        g, mzz = {}, {}
        for name in names:
            n, c = name.split("(")
            g[n], mzz[n] = n, int(c[:-1])

        # 若果它自己存自己,那它自己就是根;若果它自己没放自己,那它放的是根,或者是没更新的根的父节点.所以能沿着找到根
        def find(x):
            t=g[x]=find(g[x]) if x != g[x] else x #x和find顺序颠倒,时间增300ms
            return t

        for synonym in synonyms:
            name1, name2 = synonym.split(",")
            n1,n2=name1[1:],name2[:-1]
            
            # 如果当前同类名不在公布名单中，那么分两种情况,1是只有一个不在,二是都不在,都不在不要无影响,只有一个不在,要看到他是一种关系,相当于关系节点为0,故也无影响.妙啊妙啊.
            if g.get(n1,0)==0 or g.get(n2,0)==0: 
                continue
            p1, p2 = find(n1), find(n2)#找到两个类的根,准备合并到一个根
            # 保证同类根的字典序最小,保证大的里面存放的是小的,小的是它自己表示它自己就是根.经过改变原来一个根的存放值,成功把两个类导入到一个类,把寻到两根改为寻到一个根,就是其到根前的节点还没全改成新根,所以在寻根函数里要判断来赋值更改,提高下次的寻根效率
            if p1 > p2: 
                g[p1] = p2
            else:
                g[p2] = p1

        # 统计总频率
        ans = {}
        for k, v in g.items():
            xt=find(v) #减少一次调用函数
            ans[xt] = ans.get(xt,0)+mzz[k]

        return [k+'('+str(v)+')' for k, v in ans.items()] #不用解析,同语句时间增倍
```