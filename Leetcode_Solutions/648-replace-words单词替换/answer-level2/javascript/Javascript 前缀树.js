### 解题思路
1. 构造一个前缀树存储前缀字符串
2. 用句子中的单词逐一搜索，如果能够找到前缀则替换单词

### 代码

```javascript
/**
 * 使用前缀树
 * 
 * @param {string[]} dict
 * @param {string} sentence
 * @return {string}
 */
var replaceWords = function (dict, sentence) {
    let roots = new Root();
    dict.forEach(d => roots.add(d));
    let words = sentence.split(' ');
    words = words.map(word => {
        let root = roots.get(word);

        return root ? root : word;
    });

    return words.join(' ');
};

/**
 * 构造前缀树存储前缀
 */
function Root() {
    this.children = new Map();
    this.root = false;
}

Root.prototype.add = function (root) {
    let n = this;

    for (let i = 0; i < root.length; ++i) {
        if (n.children.has(root[i])) {
            n = n.children.get(root[i]);
        }
        else {
            let newN = new Root();
            n.children.set(root[i], newN);
            n = newN;
        }
    }

    n.root = root;
}

Root.prototype.get = function (word) {
    let n = this;

    for (let i = 0; i < word.length; ++i) {
        if (n.children.has(word[i])) {
            root += word[i];
            n = n.children.get(word[i]);

            if (n.root) {
                return n.root;
            }
        }
        else {
            return false;
        }
    }

}
```