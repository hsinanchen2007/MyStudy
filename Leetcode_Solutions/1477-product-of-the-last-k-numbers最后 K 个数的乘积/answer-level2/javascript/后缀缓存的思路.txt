每次add标记为dirty，getProduct的时候计算后缀积并且缓存

```
var ProductOfNumbers = function() {
    this.list = []
    this.values = []
};

ProductOfNumbers.prototype.add = function(num) {
    this.list.push(num)
};

ProductOfNumbers.prototype.getProduct = function(k) {
    if (this.values.length !== this.list.length) {
        const value = []
        for (let i = this.list.length - 1; i >= 0; i--) {
            if (value.length) {
                value.push(value[value.length - 1] * this.list[i])
            } else {
                value.push(this.list[i])
            }
        }
        this.values = value.reverse()
    }
    return this.values[this.values.length - k]
};

```
