### 解题思路
说到底就是要自己实现一个优先队列（自排序队列），因为js没有，这题的js不应该是“简单”难度...

### 代码

```javascript
var KthLargest = function(k, nums) {
    this.kth = k
    this.stack = []
    this.shiftUp = (num) => {
        let len = this.stack.length
        if (len === 0) {
            this.stack.push(num)
        } else if (num >= this.stack[0]) {
            this.stack.unshift(num)
            if (len + 1 > this.kth) {
                this.stack.pop()
            }
        } else if (num <= this.stack[len - 1]) {
            if (len < this.kth) {
                this.stack.push(num)
            }
        } else {
            let lb = 0, rb = len - 1, i = rb, dir = 0
            while (lb !== rb) {
                if (dir === 1 && i === rb) {
                    i = rb - 1
                    rb = i
                    lb = i
                } else if (dir === -1 && i === lb) {
                    i = lb
                    rb = i
                    lb = i
                } else if (num > this.stack[i]) {
                    // 左移
                    rb = i
                    i = Math.floor((lb + rb) / 2)
                    dir = -1
                } else if (num < this.stack[i]) {
                    // 右移
                    lb = i
                    i = Math.ceil((lb + rb) / 2)
                    dir = 1
                } else {
                    lb = i
                    rb = i
                }
            }
            this.stack.splice(i + 1, 0, num)
            if (len + 1 > this.kth) {
                this.stack.pop()
            }
        }
    }
    nums.forEach(this.shiftUp)
};

KthLargest.prototype.insert = function (index, val) {
    this.stack.splice(index, 0, val)
    if (this.stack.length > this.kth) {
        this.stack.pop()
    }
}

KthLargest.prototype.add = function(val) {
    this.shiftUp(val)
    return this.stack[this.kth - 1]
};
```