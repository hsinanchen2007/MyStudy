```js
class Trie {
    insert(g) { [...g].reduce((p, w) => p[w] || (p[w] = {}), this).$ = true }
    search(g, o = this) {
        for (const w of g) if (!(o = o[w])) return false
        return !!o.$
    }
    startsWith(g, o = this) {
        for (const w of g) if (!(o = o[w])) return false
        return true
    }
}
```
其实还可以更短，现在战胜94%，要更快的话把一些语句展开就行