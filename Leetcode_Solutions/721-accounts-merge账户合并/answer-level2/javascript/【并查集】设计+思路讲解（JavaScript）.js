题目提到，用户可能会重名，不能通过用户名判断用户，应该通过邮箱地址。并且一个用户由多个邮箱地址，要做的就是将同一个用户的多个邮箱地址合并到一起。

## 解法：并查集

借助并查集，整体的处理思路如下：

1. 初始化并查集 uf。初始化映射 map，保存 `email => username` 的映射
2. 遍历 accounts 中的每个列表 account
    - 从 account 列表的第 2 个元素开始遍历，将 `email => username` 保存到 map 中，将当前元素和下一个元素放入 uf 中
3. 初始化映射 sets，保存 `email => email[]` 的映射。
4. 循环遍历 map 的键，将属于同一连通分量（同一用户）的所有邮箱放入对应的列表中。
5. 遍历 sets 的键和值，通过 map 可得到对应的 username，而值就是用户的所有邮箱。

由于 JavaScript 不存在并查集，所以需要 diy。整体代码如下：

```javascript
// ac地址：https://leetcode-cn.com/problems/accounts-merge/
// 原文地址：https://xxoo521.com/2020-02-28-redundant-connection/

class UnionFind {
    constructor() {
        this.parent = new Map();
    }

    // 查找元素所在集合
    find(x) {
        while (this.parent.has(x)) {
            x = this.parent.get(x);
        }
        return x;
    }

    // 合并两个集合
    union(p, q) {
        const rootP = this.find(p);
        const rootQ = this.find(q);
        if (rootP !== rootQ) {
            this.parent.set(this.find(p), this.find(q));
        }
    }
}

const cmp = (x, y) => {
    if (x < y) return -1;
    if (x > y) return 1;
    return 0;
};

/**
 * @param {string[][]} accounts
 * @return {string[][]}
 */
var accountsMerge = function(accounts) {
    const uf = new UnionFind();
    const map = {}; // email => name

    // 步骤1:将属于同一集合的email进行“连线”
    for (const account of accounts) {
        for (let i = 1; i < account.length; ++i) {
            map[account[i]] = account[0];
            if (i < account.length - 1) {
                uf.union(account[i], account[i + 1]);
            }
        }
    }
    // 步骤2: 将属于同一连通分量（同一用户）的所有邮箱放入对应的列表中
    const sets = {}; // key: string; value: string[]
    for (const email in map) {
        const root = uf.find(email);
        if (!sets[root]) {
            sets[root] = [];
        }
        sets[root].push(email);
    }

    const res = [];
    for (const root in sets) {
        sets[root].sort(cmp);
        res.push([map[root], ...sets[root]]);
    }
    return res;
};
```

## 更多资料

**若有错误，欢迎指正。若对您有帮助，请给个「关注+点赞」，您的支持是我更新的动力** 👇

-   **📖Blog：[剑指 Offer + Leetcode 题解](https://xxoo521.com/algorithm/)**
-   **🐱Github ：[https://github.com/dongyuanxin/blog](https://github.com/dongyuanxin/blog)**
-   **🌟 公众号：[心谭博客](https://tva1.sinaimg.cn/large/006tNbRwly1g9xhhp50jpj31bi0hcju4.jpg)**