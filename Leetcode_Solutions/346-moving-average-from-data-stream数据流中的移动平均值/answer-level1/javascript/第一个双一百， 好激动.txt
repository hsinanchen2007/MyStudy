

![image.png](https://pic.leetcode-cn.com/158062e4f984c4a92cb2435702b9636658c8f7fdc7e5fa171df952620f76705b-image.png)


### 代码

```javascript
var MovingAverage = function (size) {
    this.list = []
    this.size = size
    this.sum =0
};

/** 
 * @param {number} val
 * @return {number}
 */
MovingAverage.prototype.next = function (val) {
    this.list.push(val)
    this.sum +=val
    if (this.list.length > this.size) {
        const v =this.list.shift()
        this.sum -= v
    }
    return this.sum / this.list.length
};
```