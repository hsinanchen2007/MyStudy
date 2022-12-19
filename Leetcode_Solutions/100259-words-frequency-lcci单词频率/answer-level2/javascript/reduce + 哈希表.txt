利用ES6中数组的reduce方法，先在构造函数WordsFrequency里统计好book中各单词出现的频率，然后存入哈希表并挂在this上面，prototype属性的get方法，直接从哈希表找到word对应单词出现的频率，未出现过的单词直接返回0。


```javascript []
/**
 * @param {string[]} book
 */
var WordsFrequency = function (book) {
    this.book = book.reduce((pre, item) => {
        pre[item] = !pre[item] ? 1 : pre[item] + 1;

        return pre;
    }, {})
};

/** 
 * @param {string} word
 * @return {number}
 */
WordsFrequency.prototype.get = function (word) {
    return this.book[word] || 0;
};

/**
 * Your WordsFrequency object will be instantiated and called as such:
 * var obj = new WordsFrequency(book)
 * var param_1 = obj.get(word)
 */
```
