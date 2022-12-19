### 解题思路
剔除重复词尾的思路，通过哈希表降低查询的复杂度(空间换时间)。
对 words 中的每个元素的词尾做切片并比对，如果词尾出现在 words 中，则删除该元素。
![Snipaste_2020-03-28_00-31-20.png](https://pic.leetcode-cn.com/4d86123a86b27c0892858c85a7b908d6c1aaca7d02f3dd6a8c8cb2a4f64a167e-Snipaste_2020-03-28_00-31-20.png)

### 代码

```javascript
/**
 * @param {string[]} words
 * @return {number}
 */
var minimumLengthEncoding = function (words) {
    let hashSet = new Set(words);
    for (let item of hashSet) {
        for (let i = 1; i < item.length; i++) {
            // 切片，看看是否词尾在 hashSet 中，切片从1开始，只看每个单词的词尾
            let target = item.slice(i);
            hashSet.has(target) && hashSet.delete(target);
        }
    }
    let result = 0;
    // 根据 hashSet 中剩余元素计算最终长度
    hashSet.forEach(item => result += item.length + 1)
    return result
};
```
![扫码_搜索联合传播样式-标准色版.png](https://pic.leetcode-cn.com/15d2d982cfbbfbc0948e4541df7beb5af14e3e461e74e30bbd8b73dbe9c692d6-%E6%89%AB%E7%A0%81_%E6%90%9C%E7%B4%A2%E8%81%94%E5%90%88%E4%BC%A0%E6%92%AD%E6%A0%B7%E5%BC%8F-%E6%A0%87%E5%87%86%E8%89%B2%E7%89%88.png)
