这题简单，贡献一个js的代码

var CustomStack = function(maxSize) {
    this.max_size=maxSize
    this.nums=[]
};


CustomStack.prototype.push = function(x) {
    if(this.nums.length<this.max_size){
        this.nums.push(x)
    }
};


CustomStack.prototype.pop = function() {
    if(this.nums.length>0){
        let n=this.nums.pop()
        return n
    }else{
        return -1
    }
};


CustomStack.prototype.increment = function(k, val) {
    let n=Math.min(k,this.nums.length)
    for (let i=0; i<n; i++) this.nums[i]=this.nums[i]+val
};

