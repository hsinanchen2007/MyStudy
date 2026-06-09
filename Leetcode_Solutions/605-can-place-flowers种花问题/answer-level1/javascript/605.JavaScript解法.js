// 第一种思路比较麻烦，但也能够理解，耗时：72 ms	占用：38.1 MB
// 思路一：正则取出所有的连续0
// 情况一：只有0，例如0000，则可以种下的数量为：Math.round(n / 2);
// 情况二：首尾的0， 例如00001111000，则可以种下的数量为：Math.round((item.length-1)/2)
// 情况三：其余部位的0，1110000100100011，可以种下的数量为：Math.round(item.length/2 - 1)
```javascript
const canPlaceFlowers = (flowerbed, n) => {
  if(n === 0) return true;      // n等于0，直接返回true
  let strArr = flowerbed.join('').match(/0+/g); // 正则取出所有连续的0
  if(!strArr) return false;     // 没有0，直接返回false
  let isStart = flowerbed[0] == 0,  // 第一个是否为0
       isEnd = flowerbed[flowerbed.length - 1] == 0,    // 最后一个是否为0
       len = strArr.length;
  // 如果全部是0
  if(strArr.length == 1 && isStart && isEnd){
      return n <= Math.round(strArr[0].length / 2);
  }
  // 否则 根据0是否在首尾判断
  let result = strArr.map((item, idx) => {
      return (idx === 0 && isStart) || (idx === len - 1 && isEnd) ? Math.round((item.length-1)/2) : Math.round(item.length/2 - 1);
  }).reduce((a, b) => a + b);
  return n <= result;
}
```

// 思路二，从头开始遍历数组，依次根据左右是否已经种下判断能不能种下，如过可以种植，就把0修改为1，继续遍历下一个，比计数+1
// 耗时：80 ms	占用：36.3 MB
```javascript
const canPlaceFlowers = (flowerbed, n) => {
  let count = 0, len = flowerbed.length;

  for(let i = 0; i < len; i++){
    if(flowerbed[i] === 1) continue;
    if(i === 0 && flowerbed[i+1] !== 1){    // 此处用不等于1而不是等于0，就包含了，只有一个0，两侧均为undefined的情况
      flowerbed[i] = 1;
      count++;
    }else if(i === len-1 && flowerbed[i-1] !== 1){
        flowerbed[i] = 1;
        count++;
    }else if(flowerbed[i+1] === 0 && flowerbed[i-1] !== 1){
        flowerbed[i] = 1;
        count++;
    }
  }
  return n <= count;
}
```