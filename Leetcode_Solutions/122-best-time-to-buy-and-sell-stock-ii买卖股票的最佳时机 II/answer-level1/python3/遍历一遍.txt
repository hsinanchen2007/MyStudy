遍历一遍，时间复杂度O(n)
需要4个数进行额外储存，空间复杂度O(1)
基本思想是，如果上一个状态是卖出，1.如果当前值比上一个卖出值价格还高，那更新卖出价格  2.如果比上一个卖出值价格低，那买入
如上一个状态是买入， 1.如果当前值比上个买入价格低，那更新买入价格 2.反之卖出

        vnow=0#当前最大利润
        Psell=0#上个卖出点
        Pbuy=-1#初始标志
        status=1#0表示已经买入，本次应卖出
        for x in prices:
            if Pbuy==-1:#买入
                Pbuy=x
                status=0
            else:
                if status==1:#当买入 或 更改卖出点
                    if x>Psell:#更改卖出点
                        vnow+=x-Psell#更改利润
                        Psell=x#更改卖出点
                        status=1
                    else:#比上个卖出点便宜，本次买入
                        Pbuy=x
                        status=0#更改状态
                else:#状态值为0，本次可能卖出
                    if x>=Pbuy:#价格比买的时候贵，卖出
                        vnow+=x-Pbuy#加上利润
                        Psell=x#更新卖出售价
                        status=1
                    else:#价钱比买的时候便宜
                        Pbuy=x

        return vnow