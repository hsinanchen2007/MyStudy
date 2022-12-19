- 先把products按字典排序这样就找到了结果就是排好序的  直接取前三个
- 然后不断迭代 将按照第一个字母相同这个条件找到的结果作为新的products继续迭代
- 寻找第二个字母相同的结果等等
```
var suggestedProducts = function (products, searchWord) {
  let res = [];
  products.sort();
  for (let i = 0, len = searchWord.length; i < len; ++i) {
    let temp = [];
    products.forEach(product => {
      if (product[i] === searchWord[i]) {
        temp.push(product)
      }
    })
    products = temp;
    res.push(products.length > 3 ? products.slice(0, 3) : products);
  }
  return res;
};
```
