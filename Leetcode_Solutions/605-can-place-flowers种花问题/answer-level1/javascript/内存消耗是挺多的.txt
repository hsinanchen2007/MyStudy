### 解题思路
首先知道的是 0和undefined取反之后的结果都为true而1的取反结果为false
另外如果对应读取数组对应索引位置的内容没有内容默认返回的是undefined所以遍历时无需注意边界问题
开始循环遍历会检查当前以及相邻的内容如果都是0或者undefined那么必定通过，最终记录次数n-- 跳过下一个i++

### 代码

```javascript
/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function(flowerbed, n) {
      if(!flowerbed[i]
      &&!flowerbed[i-1]
      &&!flowerbed[i+1]){
        n--
        i++
      }
  }
  return n>0?false:true
};
```