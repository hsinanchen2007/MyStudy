
![javascript.jpg](https://pic.leetcode-cn.com/4ebeae6d9886343826895f48dc0344d39b3bca748392006121b4d48835757240-javascript.jpg)

<br />

> 这道题没啥, 就是找规律

<br />

```
当 m=3, n=3 时
(0, 0)  m+n=0  正序

(0, 1)  m+n=1  倒叙
(1, 0)

(2, 0)  m+n=2  正序
(1, 1)
(0, 2)

(1, 2)  m+n=3  倒叙
(2, 1)

(2, 2)  m+n=4  正序
```

<br />

```js
const findDiagonalOrder = arr => {
  if (arr.length === 0) return []
  const newArr = []
  let xlength = arr[0].length, ylength = arr.length
  for (let i = 1; i < xlength + ylength; i++) {
    let xMax = i % 2 === 0 ? ylength : xlength
    let yMax = i % 2 === 0 ? xlength : ylength
    for (let x = 0; x < i; x++) {
      let y = i - x - 1
      if (x >= xMax || y >= yMax) continue
      newArr.push(i % 2 === 0 ? arr[x][y] : arr[y][x])
    }
  }
  return newArr
}
```