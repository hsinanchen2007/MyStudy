欢迎关注[muyids的leetcode题解](https://github.com/muyids/leetcode)

基于[**ES6 Map中keys的有序性** ](https://developer.mozilla.org/zh-CN/docs/Web/JavaScript/Reference/Global_Objects/Map/keys)来实现

一个Map对象在迭代时会根据对象中元素的插入顺序来进行 

- get操作

    如果元素存在，先delete再set, 元素便会置为最新使用；如果不存在，返回-1

- put操作
    
    如果元素存在，先delete再set, 元素便会置为最新使用；
    如果容器超限，进行删除末尾元素操作，使用 Map{}.keys().next()得到迭代器的第一个元素，为使用时间最远的元素，进行删除

```javascript
var LRUCache = class {

    constructor(capacity) {
        this.cache = new Map();
        this.capacity = capacity;
    }

    /**
     * @param {number} key
     * @return {number}
     */
    get(key) {
        let cache = this.cache;
        if (cache.has(key)) {
            let temp = cache.get(key)
            cache.delete(key);
            cache.set(key, temp);
            return temp;
        } else {
            return -1;
        }
    };

    /**
     * @param {number} key
     * @param {number} value
     * @return {void}
     */
    put(key, value) {
        let cache = this.cache;
        if (cache.has(key)) {
            cache.delete(key);
        } else if (cache.size >= this.capacity) {
            cache.delete(cache.keys().next().value);
        }
        cache.set(key, value);
    };
};
```