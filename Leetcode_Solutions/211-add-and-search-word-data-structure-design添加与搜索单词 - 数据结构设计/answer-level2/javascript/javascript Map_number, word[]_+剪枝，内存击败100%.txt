执行用时 :184 ms, 在所有 JavaScript 提交中击败了97.87%的用户
内存消耗 :56.1 MB, 在所有 JavaScript 提交中击败了100.00%的用户


```js
class WordDictionary {
  map: Map<number, string[]>;
  constructor() {
    this.map = new Map();
  }

  addWord(word: string): void {
    const len = word.length;
    if (this.map.has(len)) {
      (this.map.get(len) as string[]).push(word);
    } else {
      this.map.set(len, [word]);
    }
  }

  search(word: string): boolean {
    const len = word.length;
    if (!this.map.has(len)) {
      return false;
    }
    const arr = this.map.get(len) as string[];
    const invalid: boolean[] = Array(arr.length).fill(false);
    // 按字母逐个进行比较
    for (let i = 0; i < word.length; i++) {
        // 通配符
      if (word[i] === ".") {
        continue;
      }
      let hasMatch = false;
      for (let j = 0; i < arr.length; j++) {
        if (invalid[j] === false) {
          continue;
        }
        if (arr[j][i] === word[i]) {
          hasMatch = true;
        } else {
            //此单词被淘汰，后面不用比较
          invalid[j] = false;
        }
      }
      // 说明这一轮没有一个匹配
      if (hasMatch === false) {
        return false;
      }
    }
    return true;
  }
}
```

时间复杂度是O(mn)，m是add加入的单词数量，n是搜索的目标单词的长度。
空间复杂度O(m)

附上编译后的js：
```js
class WordDictionary {
    constructor() {
        this.map = new Map();
    }
    addWord(word) {
        const len = word.length;
        if (this.map.has(len)) {
            this.map.get(len).push(word);
        }
        else {
            this.map.set(len, [word]);
        }
    }
    search(word) {
        const len = word.length;
        if (!this.map.has(len)) {
            return false;
        }
        const arr = this.map.get(len);
        const invalid = Array(arr.length).fill(true);
        for (let i = 0; i < word.length; i++) {
            if (word[i] === ".") {
                continue;
            }
            let hasMatch = false;
            for (let j = 0; j < arr.length; j++) {
                if (invalid[j] === false) {
                    continue;
                }
                if (arr[j][i] === word[i]) {
                    hasMatch = true;
                }
                else {
                    invalid[j] = false;
                }
            }
            if (hasMatch === false) {
                return false;
            }
        }
        return true;
    }
}
```
