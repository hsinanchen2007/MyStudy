把一段连续序列视为一个集合，对n-1和n+1检查合并。

对我来说，理解并查集有一个很重要的点： 不一定要全都合并到一个集合，只要相互串联，拥有可以相连的父集合就可以。

一个可能的优化点： 在合并阶段就统计size，也许可以省一些最后统计的消耗。


```js
/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
  class UnionFind {
    constructor(_nums) {
      this.mapper = {};
    }

    add(num) {
      this.mapper[num] = num;
    }

    contains(num) {
      return this.mapper[num] !== undefined;
    }

    find(num) {
      while (num !== this.mapper[num]) num = this.mapper[num];
      return num;
    }

    union(x, y) {
      const rootX = this.find(x);
      const rootY = this.find(y);
      if (rootX !== rootY) {
        this.mapper[rootX] = rootY;
      }
    }

    getMaxRoot() {
      const sizeMapper = Object.keys(this.mapper).reduce((acc, crr) => {
        const root = this.find(this.mapper[crr]);
        acc[root] = acc[root] ? acc[root] + 1 : 1;
        return acc;
      }, {});
      return Object.keys(sizeMapper).reduce(
        (acc, crr) => {
          const size = sizeMapper[crr];
          return Math.max(acc, size);
        },
        nums.length ? 1 : 0
      );
    }
  }

  const uf = new UnionFind(nums);
  nums.forEach(num => {
    if (uf.contains(num)) return true;
    uf.add(num);
    if (uf.contains(num - 1)) uf.union(num, num - 1);
    if (uf.contains(num + 1)) uf.union(num, num + 1);
  });
  return uf.getMaxRoot();
};
```