最下面可以使用flat(1),但是现在还不支持
```
var allCellsDistOrder = function(R, C, r0, c0) {
  let obj = {};
  for (let r = 0; r < R; r++) {
    for (let c= 0; c < C; c++) {
      if (obj[(Math.abs(r-r0) + Math.abs(c-c0))]) {
        obj[(Math.abs(r-r0) + Math.abs(c-c0))].push([r, c]);
      }else {
        obj[(Math.abs(r-r0) + Math.abs(c-c0))] = [];
        obj[(Math.abs(r-r0) + Math.abs(c-c0))].push([r, c]);
      }
    }
  }
  let arr = [];
  Object.values(obj).forEach(item => {
    arr.push(...item);
  });
    return arr
};
```
