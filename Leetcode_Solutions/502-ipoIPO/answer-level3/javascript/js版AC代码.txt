开始想取巧用数组，通过排序来模拟优先级队列，结果在大容量样本测试时跪了，于是直接手撸了个js版的优先级队列，终于把时间复杂度降下去，于是就AC了。时间都花在实现优先级队列了，本身做题倒是没花多少时间。

```javascript

const father = x => x === 0 ? 0 : Math.floor((x - 1) / 2);
const lc = x => 2 * x + 1;
const rc = x => 2 * x + 2;

class PQueue {  // 优先级队列
    constructor(ctor) { // 接受一个比较器函数，用于扩展队列功能，使得可以自定义队列的排序
        this.s = [];
        this.ctor = ctor;
    }
    get size() {
        return this.s.length;
    }
    heapInsert(item) { //尾插入，并堆化
        const { s, ctor } = this;
        s.push(item);
        let offset = this.s.length - 1;
        let f = father(offset);
        while (ctor(s[offset], s[f]) < 0) {
            [s[f], s[offset]] = [s[offset], s[f]];
            offset = f;
            f = father(offset);
        }
        
    }
    heapify() {  //弹出顶部后，然后进行堆化
        if (this.size <= 1) return;
        const { s, ctor } = this;
        let ofset = 0;
        while (lc(ofset) < this.size) {
            let lcof = lc(ofset);
            let rcof = rc(ofset);
            // console.log('lcof', lcof, ' rcof', rcof);
            let largest = rcof < this.size && ctor(s[rcof], s[lcof]) < 0 ? rcof : lcof;
            // console.log('largest', largest);
            if (ctor(s[largest], s[ofset]) >= 0) largest = ofset;
            if (largest === ofset) break;
            [ s[ofset], s[largest] ] = [ s[largest], s[ofset] ];
            // console.log(this.s);
            ofset = largest;
            // console.log('ofset', ofset);
        }
        
    }
    add(item) {
       this.heapInsert(item);
    }
    pull() {
        if (this.size === 0) return null;
        const { s } = this;
        [ s[0], s[s.length - 1] ] = [ s[s.length - 1], s[0] ];
        const res = s.pop();
        this.heapify();
        return res;
    }
    peek() {
        return this.s[0];
    }

    toString() {
        return String(this.s);
    }

}

var findMaximizedCapital = function(k, W, Profits, Capital) {
    const minCostPQueue = new PQueue((a, b) => {
       if (Capital[a] < Capital[b]) return -1;
       return 1;
    });
    const maxProfitPQueue = new PQueue((a, b) => {
        if (Profits[a] > Profits[b]) return -1;
        return 1;
    });
    for (let i = 0; i < Capital.length; i++) {
        minCostPQueue.add(i);
    }
    for (let i = 0; i < k; i++) {
        while (minCostPQueue.size !== 0 && Capital[minCostPQueue.peek()] <= W) {
            maxProfitPQueue.add(minCostPQueue.pull());
        }
        if (maxProfitPQueue.size === 0) return W;
        W += Profits[maxProfitPQueue.pull()];
    }
    return W;
};
```