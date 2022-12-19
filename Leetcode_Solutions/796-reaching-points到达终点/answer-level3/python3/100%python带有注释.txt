```
class Solution(object):
    def reachingPoints(self, sx, sy, tx, ty):
        # 从叶子节点开始倒推。不做减法，做除法。
        # 一旦tx<sx 或者 ty<sy 就不能在处理了。因为已经超过了界限
        """
        本质上我们看
        tx= Asx+Bsy
        ty = Csx + Dsy
        那么我们判断tx是否可以倒推回sx
        if tx > ty 并且ty>sy，那么就有tx-ty = (A-C)sx + (B-D)sy。这个是没问题的，我们的第一直觉也是这样。但是我们就发现了，此时可能需要减很多次。所以我们就可以在这里做一个处理，用除法取mod来做。就相当于一次性减去了好多个ty。并且此时得到的结果一定是小于ty的。
        
        """
        while tx >= sx and ty >= sy:
            # 我们之所以要将=也包含进来，是因为某一个相等的时候，另一个可能被累加了好多次
            if tx == ty:
                # 如果tx和ty相同，那么就只能直接判断tx和sx，ty和sy的结果是否一致
                break
            elif tx > ty:
                # 如果tx比ty要大，这时候就说明，我们可以从tx中减去ty
                if ty > sy:
                    # ty>sy，要保证的是，ty中是包含sx的。
                    tx %= ty
                else:
                    # 如果此时ty==sy，那么tx=n*ty，ty=sy
                    # 那么我们就发现，应该从tx中减去nty。剩下的应该刚好和sx相同才对，否则就是false. 这里换了一种写法，用tx-sx之后在modty。原因在于，本身sx可能就是ty，那么此时如果直接进行判断是否和sx一致，就会出错。那么我们应该去掉sx。或者可以在等号的右边让sx也%ty。就可以了
                    return (tx-sx) % ty ==0
            else:
                # 否侧，我们就应该先从ty中减去tx
                # 剩下的都是反过来的
                if tx > sx:
                    ty %= tx
                else:
                    return (ty-sy) % tx == 0

        return tx == sx and ty == sy

```
