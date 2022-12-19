```
var canPlaceFlowers = function(flowerbed, n) {
  let temporaryArr = flowerbed.join('').split('1')
  let resnum = 0
  if (temporaryArr.length === 1) {
    resnum = (temporaryArr[0].length % 2 === 0 ? temporaryArr[0].length / 2 : (temporaryArr[0].length + 1) / 2)
    return resnum >= n
  }
  for (let i = 0; i < temporaryArr.length; i++) {
    if (temporaryArr[i].length) {
      if (i === 0 || i === temporaryArr.length - 1) {
        resnum = resnum + (temporaryArr[i].length % 2 === 0 ? temporaryArr[i].length / 2 : (temporaryArr[i].length - 1) / 2)
      } else {
        resnum = resnum + (temporaryArr[i].length % 2 === 0 ? (temporaryArr[i].length - 2) / 2 : (temporaryArr[i].length - 1) / 2)
      }
    }
  }
  return resnum >= n
};
```
