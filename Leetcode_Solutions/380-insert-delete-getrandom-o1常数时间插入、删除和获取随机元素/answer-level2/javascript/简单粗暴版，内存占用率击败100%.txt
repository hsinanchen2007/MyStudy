```

var RandomizedSet = function() {
    this.list= []
};


RandomizedSet.prototype.insert = function(val) {
    let a = this.list.indexOf(val)
    if (a==-1) {
        this.list.push(val)
        return true
    }
    return false
};


RandomizedSet.prototype.remove = function(val) {
    let a = this.list.indexOf(val)
    if (a!=-1) {
        this.list.splice(a,1)
        return true
    }
    return false
};


RandomizedSet.prototype.getRandom = function() {
    let random = Math.floor(Math.random()*this.list.length);
    return this.list[random];
};


```

