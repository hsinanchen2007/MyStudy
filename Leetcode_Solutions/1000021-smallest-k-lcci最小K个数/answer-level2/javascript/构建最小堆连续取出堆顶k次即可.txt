### 解题思路
针对一般数据量不大的list，使用排序手段或者求K次最小(大)值即可。
如果是遇到数据量非常的list，可以考虑使用小(大)堆，时间复杂度为O(K*logN)，不过经过验证，使用语言自带`sort`方法效率也不错。
这里以针对大数据量的场景(显得专业，嘿嘿- -)，构建大小堆来解决：

1. 将数组构建为最小堆
2. 取出堆顶数，将堆底赋给堆顶，堆的长度减1
3. 从堆顶开始重新构建堆
4. 回到第2步，重复k次即可
### 代码

```javascript
/**
 * @param {number[]} arr
 * @param {number} k
 * @return {number[]}
 */
var smallestK = function(arr, k) {
  function Heap(data, type) {
    /**
     * 最大堆|最小堆
     * TYPE = ['max', 'min'];
     **/
    this.data = data;
    this.type = type;

    this._adjustDown = function(start, length) {
      if(length <= 0) return;
      const data = this.data;
      const type = this.type;
      let next = start * 2 + 1;
      let temp = data[start];
      while(next < length) {
        if(type === 'min') {
          if(data[next] > data[next + 1]) next++; // 构建最小堆
          if(temp < data[next]) break; // 构建最小堆
        } else {
          if(data[next] < data[next + 1]) next++; // 构建最大堆
          if(temp > data[next]) break; // 构建最大堆
        }
        const parent = parseInt((next - 1) / 2);
        data[parent] = data[next];
        next = next * 2 + 1;
      }
      data[parseInt((next - 1) / 2)] = temp;
    }
  }

  Heap.prototype.size = function() {
    return this.data.length;
  };

  Heap.prototype.createHeap = function() {
    const length = this.size();
    const top = length >= 2 ? parseInt((length - 2) / 2) : 0;
    for(let i = top; i > -1; i--) {
      this._adjustDown(i, length);
    }
    return this.data;
  };

  Heap.prototype.shift = function() {
    if(this.size() <= 1) return this.data.shift();
    const result = this.data[0];
    this.data[0] = this.data[this.size() - 1];
    this.data.length--;
    this._adjustDown(0, this.size());
    return result;
  };

  const result = [];
  const heap = new Heap(arr, 'min');
  heap.createHeap();
  for(let i = 0;i < k;i++) {
    result.push(heap.shift());
  }
  return result;
};
```