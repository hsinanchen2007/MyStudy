### 解题思路
![截屏2020-04-06 下午10.51.24.png](https://pic.leetcode-cn.com/5f52ec45c988ffb18a362d91e411e4eb7bd630c9a7985fd78cc94c09deeb18e6-%E6%88%AA%E5%B1%8F2020-04-06%20%E4%B8%8B%E5%8D%8810.51.24.png)
- 先去重words，记录words每个元素的个数，减少了后期循环的次数
- 遍历words的元素，遍历字符串，匹配S中出现的第一个相同元素的索引，存在则截取索引后的S，继续循环，直到遍历完成或者索引不存在
- 累加通过遍历的字符串的个数
### 代码

```javascript
var numMatchingSubseq = function (S, words) {
  let wordsCont = [];
  words.forEach((item) => {
    if (wordsCont[item]) {
      wordsCont[item]++;
    } else {
      wordsCont[item] = 1;
    }
  });
  let ans = 0;
  let set = new Set([...words]);
  words = [...set];
  let initS = S;
  let isContain = true;
  let index = 0;
  for (let i = 0; i < words.length; i++) {
    S = initS;
    isContain = true;
    for (let j = 0; j < words[i].length; j++) {
      index = S.indexOf(words[i][j])
      if (index !== -1) {
        S = S.slice(index + 1)
      } else {
        isContain = false
        break;
      }
    }
    if (isContain) {
      ans += wordsCont[words[i]]
    }
  }
  return ans;
};
```