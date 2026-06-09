### 解题思路
此处撰写解题思路

### 代码

```javascript
/**
 * @desc 用一个栈+差值法可以节省内存
 **/

class MinStack {
    constructor() {
        this.dataStck = [] // 数据栈
        this.minValue = null // 最小值
    }

    push(x) {
        if (!this.dataStck.length) {
            // 空数组情况
            this.dataStck.push(x)
            this.minValue = x
        } else {
            // 待入栈元素比当前最小值小或者等于情况
            if (x <= this.minValue) {
                this.dataStck.push(x - this.minValue)
                this.minValue = x // 更新最小值
            } else {
                // 存插入值与最小值的差值
                this.dataStck.push(x - this.minValue)
            }
        }
    }

    pop() {
        if (this.dataStck.length) {
            if (this._peek() < 0) {
                // 当出栈元素是负数 说明之前最小值有变化
                const pop = this.minValue - this.dataStck.pop()
                this.minValue = pop
                return pop
            }
            return this.dataStck.pop() + this.minValue
        }
    }

    top() {
        const _top = this._peek()
        // 注意栈顶元素为负数或者栈只有一个元素时候 直接取最小值
        return  _top < 0 || this.dataStck.length <= 1 ? this.minValue : this.minValue + _top
    }

    getMin() {
        return this.minValue
    }

    _peek() {
        return this.dataStck[this.dataStck.length - 1]
    }

}
```