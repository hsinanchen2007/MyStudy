
### 代码

```javascript
/**
 * @param {number} cap
 */
var StackOfPlates = function(cap) {
  this.stack = []
  this.cap = cap
};

/** 
 * @param {number} val
 * @return {void}
 */
StackOfPlates.prototype.push = function(val) {
  if(this.cap <= 0) return
  if(this.stack.length === 0){
     this.stack[0] = new Array(this.cap).fill(1)
     this.stack[0][1] = val
  }else{
     if(this.stack[this.stack.length - 1][0] < this.cap){
       this.stack[this.stack.length - 1][0]++
       this.stack[this.stack.length - 1][this.stack[this.stack.length - 1][0]] = val
     }else{
       this.stack.push(new Array(this.cap).fill(1))
       this.stack[this.stack.length - 1][1] = val
     }
  }
};

/**
 * @return {number}
 */
StackOfPlates.prototype.pop = function() {
  return this.popAt(this.stack.length - 1)
};

/** 
 * @param {number} index
 * @return {number}
 */
StackOfPlates.prototype.popAt = function(index) {
  if(this.cap <= 0 || index < 0) return -1
  if(index < this.stack.length){
    // console.log(this.stack[index])
    // console.log(index, this.stack[index][this.stack[index][0]])
    let tmp = this.stack[index][this.stack[index][0]--]
    if(!this.stack[index][0]){
      this.stack.splice(index, 1)
    }
    return tmp
  }
  return -1
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * var obj = new StackOfPlates(cap)
 * obj.push(val)
 * var param_2 = obj.pop()
 * var param_3 = obj.popAt(index)
 */
```