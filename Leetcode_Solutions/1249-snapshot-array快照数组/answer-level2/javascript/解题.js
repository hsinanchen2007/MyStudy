### 解题思路

1. 暴力处理

全量的备份数组到一个新的snapshot，当数据量过大时候，内存回溢出。

2. 增量备份

构建数组的数据结构为:

```
{
    [snap_id_0] : value,
    [snap_id_1] : value,
    [snap_id_n] : value,
    max_snap_id: cur_snap_id
}
```

在set的时候更新一下当前数组下的最大snap_id, get的时候，找到最后一次修改的snap_id就行了


### 代码

```javascript
var SnapshotArray = function (length) {
    this.snap_id = 0;
    this.data = [];

    while (length--) {
        this.data.push({
            [this.snap_id]: 0,
            max_snap_id: this.snap_id
        });
    }
};

/** 
 * @param {number} index 
 * @param {number} val
 * @return {void}
 */
SnapshotArray.prototype.set = function (index, val) {
    const snap_id = this.snap_id;

    if (this.data.length < index - 1) {
        let n = index - this.data.length + 1;

        while (n--) {
            this.data.push({
                [snap_id]: 0,
                max_snap_id: snap_id
            });
        }
    }

    const data = this.data[index];

    data[snap_id] = val;
    data.max_snap_id = snap_id;
};

/**
 * @return {number}
 */
SnapshotArray.prototype.snap = function () {
    return this.snap_id++;
};

/** 
 * @param {number} index 
 * @param {number} snap_id
 * @return {number}
 */
SnapshotArray.prototype.get = function (index, snap_id) {
    if (this.snap_id < snap_id || index >= this.data.length) {
        return null;
    }

    const data = this.data[index];
    let calc_snap_id = Math.min(snap_id, data.max_snap_id);
    let result = null;

    while (calc_snap_id>=0) {
        if (data.hasOwnProperty(calc_snap_id)) {
            result = data[calc_snap_id];

            break;
        }
        calc_snap_id--;
    }

    return result;
};
```