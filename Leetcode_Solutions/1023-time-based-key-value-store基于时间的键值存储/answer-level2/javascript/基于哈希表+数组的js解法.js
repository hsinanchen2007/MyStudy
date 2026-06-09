既然是键值对存储那么肯定要用到哈希表。不用额外的空间存储timestamp，利用数组下标来辅助判断就行。
哈希表中存储的是value的数组。 例：hashmap = {'foo': ['bar1', 'bar2']}
当需要拿出value的时候，只要以timestamp为下标从数组中取值即可，如果取不到就继续往前取。
```
/**
 * Initialize your data structure here.
 */
var TimeMap = function () {
    this.mapping = new Map(); // {'foo': [bar, bar2]}
    this.find = function(index, list) {
        let goal = list[index];
        if(goal !== undefined) {
            return goal;
        } else {
            return index - 1 > -1 ? this.find(index - 1, list) : "";
        }
    }
};

/** 
 * @param {string} key 
 * @param {string} value 
 * @param {number} timestamp
 * @return {void}
 */
TimeMap.prototype.set = function (key, value, timestamp) {
    if (this.mapping.has(key)) {
        let tsArr = this.mapping.get(key);
        tsArr[timestamp] = value;
        this.mapping.set(key, tsArr);
    } else {
        let tsArr = [];
        tsArr[timestamp] = value;
        this.mapping.set(key, tsArr);
    }
};

/** 
 * @param {string} key 
 * @param {number} timestamp
 * @return {string}
 */
TimeMap.prototype.get = function (key, timestamp) {
    if (this.mapping.has(key)) {
        let tsList = this.mapping.get(key);
        return this.find(timestamp, tsList);
    } else {
        return "";
    }
};
```
