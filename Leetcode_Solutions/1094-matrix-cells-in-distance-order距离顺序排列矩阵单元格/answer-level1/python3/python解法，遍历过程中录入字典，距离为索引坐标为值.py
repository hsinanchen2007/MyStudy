![微信截图_20190807110729.png](https://pic.leetcode-cn.com/26b467717a4ba2aa40f4c5eef42d983c24d60ae917514197058f6c8fd968d9db-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190807110729.png)
python解法，定义字典类型，遍历二维数组没计算出一个距离就把<值，坐标>添加到字典中，然后字典值的大小顺序合并。
```
class Solution(object):
    def allCellsDistOrder(self, R, C, r0, c0):
        res = []
        hmap = {}
        for x in range(R):
            for y in range(C):
                dp = abs(x-r0)+abs(y-c0)
                if dp not in hmap.keys():
                    hmap[dp] = [[x,y]]
                else:
                    hmap[dp].append([x,y])
        max_index = max(hmap.keys())
        for i in range(max_index+1):
            res = res + hmap[i]
        return res
```

