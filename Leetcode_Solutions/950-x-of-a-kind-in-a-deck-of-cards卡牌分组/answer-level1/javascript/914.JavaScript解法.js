// 解题结果：执行用时72ms，内存消耗36M
// 解题思路：
// 1、把所有数据遍历，生成一数据值为key，数量为value的对象
// 2、生成以value为值的数组，并去重，因为重复的数据结果是一样的
// 3、数组相邻数据两两求最大公约数
```javascript
const hasGroupsSizeX = (deck) => {
  if(deck.length <= 1) return false;
  let obj = {}, result = 1;
  deck.forEach(item => {
    if(obj[item] != undefined) {
      obj[item]++;
    }else {
      obj[item] = 1;
    }
  })
  let temp = [...new Set(Object.values(obj))];      // 去重，减少重复运算

  if(temp.length <= 1){     // 如果所有数据数量都是一样的，直接返回true
    return true;
  }

  while(temp.length > 1){
    let num1 = temp[0],
        num2 = temp[1];

    result = gcd(num1, num2);
    console.log(result)
    if(result == 1){        // 如果最大公约数已经是1了，跳出循环，减少遍历
      return false;
    }else{
      temp.splice(0, 2, result);    // 迭代，继续求最大公约数
    }
  }

  return result != 1;

}

// 求最大公约数
const gcd = (x, y) => {
  return x == 0 ? y : gcd(y%x, x);
}
```