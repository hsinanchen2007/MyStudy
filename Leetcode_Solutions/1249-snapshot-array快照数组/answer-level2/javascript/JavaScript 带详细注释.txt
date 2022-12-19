这题解题的关键是优化空间复杂度。


```javascript
var SnapshotArray = function(length) {
    // map[n]表示第n个数的操作记录
    // map[n][0]第n个数最后一次的操作记录
    this.map = new Array(length).fill(0).map(a=>[[0,0]]);
    this.snapId = 0;    
};

SnapshotArray.prototype.set = function(index, val) {
    let records = this.map[index];
    let [lastId,_]=records[0];
    //此时的值被替换为最新的值
    if(lastId===this.snapId){
        records.shift();
    }
    records.unshift([this.snapId,val])
};

SnapshotArray.prototype.snap = function() {
    //快照标识
    return this.snapId++; 
};

SnapshotArray.prototype.get = function(index, snap_id) {
    //首先找到这个数的所有记录
    let records = this.map[index];
    let ans=0;
    //由快照snapId最大的往snapId小的开始找，_id比snap_id小则表示此时对应的value是snap_id之前最后一次更新，即要找的值
    for(let i=0;i<records.length;i++){
        let [_id,value] = records[i];
        if(_id<=snap_id){
            ans=value;
            break;
        }
    }
    return ans;
};
```