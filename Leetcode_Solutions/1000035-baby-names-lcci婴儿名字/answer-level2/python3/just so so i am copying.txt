```
def trulyMostPopular( names, synonyms ):

    # you题意可知
    # 通过synonyms中名字的前后关系，把names中的数据分为一类，
    # 其中输出一类中字典数最小的名字
    # 因此难点在于:
    # 1. 如何通过synonyms找到名字之间的联系(因为有传递性，很容易想到通过并查集去存储不同名字之间的关系)
    # 2. 如何保留字典数最小的名字(利用递归查找并查集，虽然有点慢，因为只有这样，每次遍历到最终点时，都保留当前字典数最小的值为父节点)
    # 因此代码逻辑如下：
    dp = {} # 并查集字典存储(因为是字符串) 只需保留names有的名字即可
    dp_res = {} # 把names转为字典形式
    for name in names:
        temp = name.split('(')
        w, n = temp[ 0 ], int(temp[ 1 ][ :-1 ])
        dp_res[ w ] = n
        dp[ w ] = w

    # 找到最终点，且最终点为最小字典数
    def find( dp, k ):
        while k != dp[ k ]:
            k = dp[ k ]
        return k

    # 合并并查集，即synonyms中的关系
    def union( dp, k, v ):
        kp = find(dp, k)
        vp = find(dp, v)
        if vp > kp:
            dp[ vp ] = kp
        else:
            dp[ kp ] = vp
    
    # 进行合并
    for s in synonyms:
        k, v = s[ 1:-1 ].split(',')
        # 如果names没有关系中的名字，就不用合并
        if k not in dp or v not in dp:
            continue
        union(dp, k, v)

    # 最后统计把同一个祖宗名字，累计到一起即可
    ans = collections.defaultdict(int)
    for key, val in dp.items():
        ans[ find(dp, val) ] += dp_res[ key ]
    return [ k + '(' + str(v) + ')' for k, v in ans.items() ]
```
