
### 代码

```javascript
/**
 * @param {number} stackSize
 */
var TripleInOne = function(stackSize) {
  this.Stacks = new Array(3)
  for(let i = 0; i < 3; i++){
    this.Stacks[i] = new Array(stackSize + 1).fill(0)
  }
  this.stackSize = stackSize
};

/** 
 * @param {number} stackNum 
 * @param {number} value
 * @return {void}
 */
TripleInOne.prototype.push = function(stackNum, value) {
  if(this.Stacks[stackNum][0] < this.stackSize){
    this.Stacks[stackNum][++this.Stacks[stackNum][0]] = value
  }
};

/** 
 * @param {number} stackNum
 * @return {number}
 */
TripleInOne.prototype.pop = function(stackNum) {
  if(this.Stacks[stackNum][0] != 0){
    return this.Stacks[stackNum][this.Stacks[stackNum][0]--]
  }else{
    return -1
  }
};

/** 
 * @param {number} stackNum
 * @return {number}
 */
TripleInOne.prototype.peek = function(stackNum) {
    if(this.Stacks[stackNum][0] != 0){
    return this.Stacks[stackNum][this.Stacks[stackNum][0]]
  }else{
    return -1
  }
};

/** 
 * @param {number} stackNum
 * @return {boolean}
 */
TripleInOne.prototype.isEmpty = function(stackNum) {
  if(this.Stacks[stackNum][0] == 0){
    return true
  }else{
    return false
  }
};

/**
 * Your TripleInOne object will be instantiated and called as such:
 * var obj = new TripleInOne(stackSize)
 * obj.push(stackNum,value)
 * var param_2 = obj.pop(stackNum)
 * var param_3 = obj.peek(stackNum)
 * var param_4 = obj.isEmpty(stackNum)
 */
```