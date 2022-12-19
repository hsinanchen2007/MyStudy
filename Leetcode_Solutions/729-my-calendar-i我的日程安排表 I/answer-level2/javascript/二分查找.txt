### 解题思路
此处撰写解题思路

### 代码

```javascript
var MyCalendar = function () {
  this.booked = [];
};

/** 
 * @param {number} start 
 * @param {number} end
 * @return {boolean}
 */
MyCalendar.prototype.book = function (start, end) {
  if (this.booked.length == 0) {
    this.booked.push({
      start, end
    })
    return true;
  }
  return this.searchAndInsert(start, end, 0, this.booked.length - 1)
};

MyCalendar.prototype.searchAndInsert = function (start, end, left, right) {
  if (end <= this.booked[left].start) {
    this.booked.splice(left, 0, {
      start,
      end
    });
    return true;
  } else if (start >= this.booked[right].end) {
    this.booked.splice(right + 1, 0, {
      start,
      end
    });
    return true;
  }
  else if (left >= right) {
    return false;
  } else {
    let mid = Math.floor((left + right) / 2);
    if (end <= this.booked[mid].start) {
      return this.searchAndInsert(start, end, left, mid - 1);
    } else if (start >= this.booked[mid].end) {
      return this.searchAndInsert(start, end, mid + 1, right)
    } else {
      return false;
    }
  }
}
```

主要思路：将已订时间段顺序存储在数组里，通过二分查找判断下一个订阅时间段是否与已定时间冲突