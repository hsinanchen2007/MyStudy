- obj[name] = array 每一个人对应一个数组 
- array[i] = [name, time, money, city, isDeleted] 按时间从小到大排序
- isDeleted表示是否被删除过
- array添加元素时用二分法找到该元素应该插入的位置 然后向左右两边找时差少于60的
```
var invalidTransactions = function (transactions) {
  let res = [];
  let obj = {};
  let delOverTime = function (arr, tran) {
    let left = 0;
    let right = arr.length;
    while (left < right) {
      let mid = Math.floor((left + right) / 2);
      if (arr[mid][1] > tran[1]) {
        right = mid;
      } else {
        left = mid + 1
      }
    }
    let del = false;
    arr.splice(left, 0, tran);
    let _right = left + 1
    let _left = left - 1;
    while (arr[_right] && arr[_right][1] - tran[1] <= 60) {
      if (arr[_right][3] !== tran[3]) {
        if (!arr[_right][4]) {
          res.push(arr[_right].join(','));
          arr[_right][4] = true;
        }
        del = true;
      }
      ++_right;
    }
    while (arr[_left] && tran[1] - arr[_left][1] <= 60) {
      if (arr[_left][3] !== tran[3]) {
        if (!arr[_left][4]) {
          res.push(arr[_left].join(','));
          arr[_left][4] = true;
        }
        del = true;
      }
      --_left;
    }
    if (del || tran[2] > 1000) {
      res.push(tran.join(','));
      tran[4] = true;
    }
  }
  transactions.forEach(el => {
    let tran = el.split(',');
    if (!obj[tran[0]]) {
      obj[tran[0]] = [];
    }
    tran[1] = parseInt(tran[1])
    tran[2] = parseInt(tran[2])
    delOverTime(obj[tran[0]], tran);
  })
  return res;
};
```
