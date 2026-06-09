### 解题思路
使用map计数

### 代码

```golang
type WordsFrequency struct {
    m map[string]int
}


func Constructor(book []string) WordsFrequency {
    w := WordsFrequency {
        m : make(map[string]int),
    }

    for _, v := range book {
        w.m[v]++
    }

    return w
}


func (this *WordsFrequency) Get(word string) int {
    return this.m[word]
}


/**
 * Your WordsFrequency object will be instantiated and called as such:
 * obj := Constructor(book);
 * param_1 := obj.Get(word);
 */
```