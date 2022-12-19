原文在[语雀博客](https://www.yuque.com/zcue/dev-blog/pyv79e)上

### 解题思路

推荐阅读[背包九讲](https://github.com/tianyicui/pack)，本题用到其中的第一部分，01 背包。因为每两块石头就能粉碎，可以试着把这些石头分为两份，分别为 a 份和 b 份，如果想要剩下的数字尽量小，那就要让 a 份和 b 份尽量相等，如果完全相等，那是最好的，这样答案就为 0，因为 a 份和 b 份总能全部抵消。那如果只看 a 份，就可以转换为：把这些石头放进一个容量为 ![](https://pic.leetcode-cn.com/6bf6aa95718c0986a5b2792af12f584c2e722ef7170784aa4136a50875ee737b-file_1586314411567) 的背包中，尽量放最多，这就让我们想到了什么，是 01 背包：

![image.png](https://pic.leetcode-cn.com/4d902c6a0ea499b587662dcb3aa0ee1f8e12321074026bfc17fd5b8198b6f069-file_1586314411412)

只不过在当前情景下 ![](https://pic.leetcode-cn.com/9d096430fc6f91fdf14c40412c1808591c7318b3ebad82b37b44b5b3e1b33e8e-file_1586314411483) 问题就转换为，有一个容量为 ![](https://pic.leetcode-cn.com/6bf6aa95718c0986a5b2792af12f584c2e722ef7170784aa4136a50875ee737b-file_1586314411567) 的背包，放入第 i 件物品的费用是 ![](https://pic.leetcode-cn.com/89a0dd0937b9fb608e4d1b088db75188dfe1e56bb96fdaf7592ffcecffa648d0-file_1586314411633) 得到的价值还是 ![](https://pic.leetcode-cn.com/89a0dd0937b9fb608e4d1b088db75188dfe1e56bb96fdaf7592ffcecffa648d0-file_1586314411633) 求价值最大，我们可以使用优化后的方式来编写代码：

![image.png](https://pic.leetcode-cn.com/d205c47dd1a08605cf5ee9d6aeab99d99852ee6172c51e2f263c031f721e12e7-file_1586314411641)

时间复杂度是 ![](https://pic.leetcode-cn.com/8317ca110f040438320fe51f540c118fe12ce718b8f0cb2d68f6dada3f6d794f-file_1586314411653)  代码如下：（本代码使用了 Lodash，因为力扣已经默认包含了这个库）

```javascript
var lastStoneWeightII = function(stones) {
  const sSum = _.sum(stones);
  const n = stones.length;
  const volume = Math.floor(sSum / 2);

  const dp = Array(volume + 1).fill(0);

  for (let i = 0; i < n; i++) {
    const tmp = stones[i];
    for (let j = volume; j >= tmp; j--) {
      dp[j] = Math.max(dp[j], dp[j - tmp] + tmp);
    }
  }

  return sSum - dp[volume] * 2;
};
```


![image.png](https://pic.leetcode-cn.com/70db08af9bd9e0c4168631d8d2dbdce8179291fc1171b0823729c4b9a988d59a-file_1586314411655)
