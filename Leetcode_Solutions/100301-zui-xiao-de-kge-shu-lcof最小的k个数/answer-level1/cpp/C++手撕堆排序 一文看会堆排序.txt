首先明确一点，在本文里，堆是一种数据结构。

## 堆的定义
堆通常是一个可以被看做一棵树的数组对象。堆总是满足下列性质：
* 堆中某个节点的值总是不大于或不小于其父节点的值；
* 堆总是一棵完全二叉树。不了解完全二叉树的同学，可以[点击这里](https://baike.baidu.com/item/%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91/7773232)。

## 堆的类型
根据性质一可以发现，堆的根节点的值为最大值或者最小值，依此可以将堆分为最大堆（大根堆，大顶堆）或者最小堆（小根堆，小顶堆）。

## 堆的实现
因为堆是一棵完全二叉树，所以一般可以用数组来实现。数组的下标对应堆中节点的编号。为方便起见，我们假设数组下标从 1 开始。那么对于堆中每个节点与其左右子节点的编号关系都有：
* leftID = fatherID * 2
* rightID = fatherID * 2 + 1
* fatherID = sonID / 2

示例如下图：
![完全二叉树.png](https://pic.leetcode-cn.com/f85304e2615fbb046b94891fa5e1488e7c5389c0ce4d6ebe7b165863308331f0-%E5%AE%8C%E5%85%A8%E4%BA%8C%E5%8F%89%E6%A0%91.png)

### 支持的方法
有了数据存储格式之后，来看下堆支持的方法：
1. int size() { ... }; 返回堆内元素个数。
2. int top() { ... }; 返回根节点的元素。
3. void push(int x) { ... }; 插入一个元素。
4. void pop(int x) { ... }; 将根节点元素从堆中弹出。

前两种方法较简单，size() 可以维护一个计数，在 push 和 pop 时更新即可。top() 直接返回根节点的元素即可。

主要讲下第三和第四个灵魂函数：
**push 方法**
由于性质二的限制，push后堆也应该是一棵完全二叉树，所以必须将元素追加到数组末尾。
又由于性质一的限制，需要对刚刚push的元素进行冒泡。
以最大堆为例，设刚刚push的元素的编号为 id，val[id] 表示对应节点的值：
1. 如果 id == 1，冒泡过程结束。
2. 如果 val[id] > val[id/2]，那么需进行交换，swap(val[id], val[id/2])，id /= 2，跳转第 1 步；否则，算法结束。
示例如下图：
![heap_push.png](https://pic.leetcode-cn.com/a93c03eb3c1677997d25594c1aadfc3440a7b6f7d1edabdf308fd4928e02dd06-heap_push.png)


**pop 方法**
pop 需要分两步走：
第一步，先将根节点与编号最大节点的元素互换，并删除编号最大的节点。
此时堆仍然是一棵完全二叉树，但有可能不满足性质一。
所以我们需要对根节点的元素进行下沉操作，以大顶堆为例，设置一个游标 id, 初始指向根节点：
1. 如果id指向叶子节点，算法结束。
2. 如果id指向节点大于其左右子节点的值，算法结束。
3. 设id的左右子节点中，拥有较大值的编号为 p，交换 id 与 p 的值，并将 id 指向 p 节点。跳转步骤 1 .

示例如下图：
![heap_pop.png](https://pic.leetcode-cn.com/92ab57aa13ee7088ca05b318aaf1cf7697085814c91e94cedff673ff01dbc869-heap_pop.png)


在本题中的应用：
topk 问题一般用堆可解。求最小的 k 个元素可以使用大顶堆解决，反之求最大的 k 个元素，可用小顶堆解决。
以本题为例：
我们可以遍历数组 arr，对其元素执行 push 操作。
每次push后，检查size，若 size > k，则执行 pop 操作。这样在遍历过程中，堆始终保存着最小的k个数。

```
class Solution {
    enum { MAXN = 10000 };
    int n;
    int heap[MAXN];
    
    inline int& getRef(int root) {
        return heap[root-1];
    }
public:
    Solution() : n(0) {}
    void push(int v) {
        heap[n++] = v;
        for(int pos = n, nextPos = pos>>1; pos > 1 
                && getRef(pos) > getRef(nextPos); pos = nextPos, nextPos >>= 1) {
            swap(getRef(pos), getRef(nextPos));
        }
    }
    int pop() {
       swap(getRef(1), getRef(n));
       int res = heap[--n];
       for(int root = 1; ; ) {
           int left = root<<1;
           int right = root<<1|1;
           if(right <= n && getRef(root) < max(getRef(left), getRef(right))) {
               if(getRef(left) > getRef(right)) {
                   swap(getRef(left), getRef(root));
                   root = left;
               } else {
                   swap(getRef(right), getRef(root));
                   root = right;
               }
           } else if (left <= n && getRef(root) < getRef(left)) {
                swap(getRef(left), getRef(root));
                root = left;
                break;
           } else {
               break;
           }
       }
       return res;
    }
    int size() const {
        return n;
    }
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        for(auto v : arr) {
            this->push(v);
            if(this->size() > k) {
                this->pop();
            }
        }
        
        return vector<int>(heap, heap+k);
    }
};
```
![](https://pic.leetcode-cn.com/1b72febfa1d1a5d500800c05cfec01c257916423ca7cf97c45e3c0d926748fdc.jpg)
# 扫码关注，快乐加倍