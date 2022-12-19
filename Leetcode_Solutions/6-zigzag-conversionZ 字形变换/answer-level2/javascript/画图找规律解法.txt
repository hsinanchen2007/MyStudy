![微信图片_20200322221901.png](https://pic.leetcode-cn.com/bbee2b6d4f0a728787f32b99da050e7a60f0ae10d4321b135fb65bf7339d0289-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200322221901.png)

### 解题思路
小弟才疏学浅，算法一类的不太懂，只能用最简单的思维来解题，大神勿喷，让各位见笑了；
按照题意，先在纸上画出转化为Z型后的图
![微信图片_20200322222517.jpg](https://pic.leetcode-cn.com/d43907907ec344e111c3bca2d6b1bf67b8032365ef519aadbcecfed59bfe2feb-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20200322222517.jpg)
容易看出，不管分解成多少行，第一行与最后一行始终保持着一样的规律，即两者下标相差2n-2（n为行数numRows）；
剩下的中间部分，为方便描述，取第一列数据，设当前行数的下标为i（即i=行数-1），观察下标，发现有2种情况：
顺着Z字的延续方向，第一种情况，下标跨度从下往上看（1 ~ 7），得出跨度为：(总行数-当前行数下标)*2 - 重复计算次数2，即2(n-i)-2，减2是因为算跨度的时候重复加了2次;
![微信截图_20200322224220.png](https://pic.leetcode-cn.com/c5a4be805ffb246654192c3765acf1f736b8bb3c0e8ca2f9ca4edb3769f45612-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200322224220.png)
第二种情况，下标跨度从上往下看（7 ~ 9），跨度为(当前行数下标i + 1)*2 - 重复计算次数，即2(i+1)-2，减2同理；
![微信截图_20200322224243.png](https://pic.leetcode-cn.com/2ace628521bb9cdd0b358ed84a7ed3a74e7b95ff7cab64d5b2ac1dba5c991cf7-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200322224243.png)

至此，理清规律，编写代码：

### 代码

```javascript
var convert = function(s, numRows) {
  if (numRows <= 1) {
    return s || "";
  }
  let resultArr = [];
  let result = "";
  let tmpStr;
  for (let i = 0; i < numRows; i++) {
    tmpStr = "";
    let index = i == 0 ? 0 : numRows - 1;
    // 第一行 或 最后一行
    if (i == 0 || i == numRows - 1) {
      for (let i = index; i < s.length; i = i + 2 * numRows - 2) {
        tmpStr += s[i];
      }
      resultArr.push(tmpStr);
    } else {
      let j = i;
      let num = 1;
      while (j < s.length) {
        tmpStr += s[j];
        if (num % 2 == 0) {
          j += 2 * (i + 1) - 2;
        } else {
          j += 2 * numRows - (i + 1) * 2;
        }
        num++;
      }
      resultArr.push(tmpStr);
    }
  }
  result = resultArr.join("");
  return result;
};
```
第一行与最后一行的生成规律相同，故合并在一起。