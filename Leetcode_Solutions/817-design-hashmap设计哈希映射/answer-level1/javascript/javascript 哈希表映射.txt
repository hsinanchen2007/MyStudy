```
var MyHashMap = function() {
    this.arr = new Array(93);
    for(let i=0;i<this.arr.length;++i){
        this.arr[i] = new Array();
    }
};


MyHashMap.prototype.put = function(key, value) {
    let index = hash(key);
    let list = this.arr[index];
    if(this.get(key)==-1) list.push(new node(key,value));
    else {
        for(let node of list){
            if(node.key==key) node.value = value;
        }
    }
};


MyHashMap.prototype.get = function(key) {
        let index = hash(key);
    let list = this.arr[index];
    for(let node of list){
        if(node.key ==key) return node.value;
    }
    return -1;
};

MyHashMap.prototype.remove = function(key) {
     let index = hash(key);
    let list = this.arr[index];
    for(let i=0;i<list.length;++i){
        if(list[i].key==key) list.splice(i,1);
    }
};

    //hash函数
var hash = function(key){
    return key%93;
};
    //存储的node
var node = function(key,value){
    this.key = key;
    this.value = value;
}
```
