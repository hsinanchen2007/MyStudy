这个题目就是把求公共前缀的过程写出来了~~，每次都只需要遍历上一次的搜索结果即可，代码如下：
```
class Solution(object):
    def suggestedProducts(self, products, searchWord):
        """
        :type products: List[str]
        :type searchWord: str
        :rtype: List[List[str]]
        """
        products.sort()

        def find_pro(pro,sea,l):
            f_p = []
            if len(pro) == 0:
                return f_p
            for i in range(len(pro)):
                if len(pro[i]) > l and pro[i][l] == sea[l]:
                    f_p.append(pro[i])
            return f_p
        r_p = []
        l_f = products
        for i in range(len(searchWord)):
            l_f = find_pro(l_f,searchWord,i)
            if len(l_f) > 3:
                r_p.append(l_f[:3])
            else:
                r_p.append(l_f)            
        return r_p
```
