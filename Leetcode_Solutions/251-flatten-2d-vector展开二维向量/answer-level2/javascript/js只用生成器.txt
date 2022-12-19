用生成器代替递归，理论上可以节约内存空间

```
var Vector2D = function(v) {
  function *iter(list) {
    for (let item of list) {
      if (typeof item !== 'number') {
        yield *iter(item)
      } else {
        yield item
      }
    }
  }
  
  this.it = iter(v)
  this.state = this.it.next()
};

Vector2D.prototype.next = function() {
  let value = this.state
  this.state = this.it.next()
  return value.value
};

Vector2D.prototype.hasNext = function() {
  return !this.state.done
};
```
