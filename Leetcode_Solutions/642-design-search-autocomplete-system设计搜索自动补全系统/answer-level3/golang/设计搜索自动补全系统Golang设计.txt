### 解题思路
不说了，字符串比对浪费我80%的时间
1、trie树
2、字符串ASCII排序
还有一个坑，因为用了全局变量，所以在初始化的时候要记得赋为空。

### 代码

```golang
import (
    "sort"
)

var WordIdMapper map[string]uint8
var IdWordMapper map[uint8]string
var IdTimesMapper map[uint8]int

var MaxId uint8

type wordTimesSorter []uint8
func (s wordTimesSorter) Len() int {return len(s)}
func (s wordTimesSorter) Swap(i, j int){ s[i], s[j] = s[j], s[i] }
func (s wordTimesSorter) Less(i, j int) bool { 
    if (IdTimesMapper[s[i]] == IdTimesMapper[s[j]]) {
        return cStrings(IdWordMapper[s[i]], IdWordMapper[s[j]])
    }
    return IdTimesMapper[s[i]] > IdTimesMapper[s[j]]
}

func cStrings(i, j string) (ok bool) {
    m := len(i)
    if len(i) > len(j) {
        m = len(j)
    }
    _i := []byte(i)
    _j := []byte(j)
    for n:=0 ; n<m;n++ {
        if _i[n] > _j[n] {
            return false
        } else if _i[n] < _j[n] {
            return true
        }
    }
    return len(i) < len(j)
}


type trieTree struct {
    Mapper map[byte]*trieTree
    Recommends []uint8
}
func (m *trieTree) SetRecommend(_id uint8) {
    if len(m.Recommends) == 0 {
        m.Recommends = append(m.Recommends, _id)
        return
    }
    var exist bool
    for i := range m.Recommends {
        if m.Recommends[i] == _id {
            exist = true
        }
    }
    if !exist {
        if len(m.Recommends) < 4 {
            m.Recommends = append(m.Recommends, _id)
        } else {
            m.Recommends[3] = _id
        }
    }
    sort.Sort(wordTimesSorter(m.Recommends))
}

func (m *trieTree) GetRecommends() []string {
    var res = make([]string, 0, 3)
    for i := range m.Recommends {
        if i == 3 {
            break
        }
        res = append(res, IdWordMapper[m.Recommends[i]])
    }
    return res
}

func (m *trieTree) Push(input []byte, _id uint8) {
    m.SetRecommend(_id)
    if len(input) == 0 {
        return
    }
    var t *trieTree
    var ok bool
    if t, ok = m.Mapper[input[0]]; !ok {
        t = ConstructorNewTrieTree()
        m.Mapper[input[0]] = t
    }
    t.Push(input[1:], _id)
    
}


type AutocompleteSystem struct {
    tTree *trieTree
    searchString []byte
    curTree *trieTree
}

func (this *AutocompleteSystem) Push(c []byte, times int) {
    s := string(c)
    _id ,ok := WordIdMapper[s]
    if !ok {
        _id = MaxId
        IdTimesMapper[_id] = 0
        WordIdMapper[s] = _id
        IdWordMapper[_id] = s
        MaxId++
    }
    if times == 0 {
        IdTimesMapper[_id] = IdTimesMapper[_id] + 1
    } else {
        IdTimesMapper[_id] = times
    }
    this.tTree.Push(c, _id)
}

func ConstructorNewTrieTree() *trieTree {
    return &trieTree{make(map[byte]*trieTree), make([]uint8, 0, 4)}
}


func Constructor(sentences []string, times []int) AutocompleteSystem {

    WordIdMapper = make(map[string]uint8, 128)
    IdWordMapper = make(map[uint8]string, 128)
    IdTimesMapper = make(map[uint8]int, 128)

    MaxId = 1
    o := AutocompleteSystem{ConstructorNewTrieTree(), []byte{}, nil}
    for i := range sentences{
        o.Push([]byte(sentences[i]), times[i])
    }
    return o
}


func (this *AutocompleteSystem) Input(c byte) []string {
    if string([]byte{c}) == "#" {
        this.Push(this.searchString, 0)
        this.searchString = []byte{}
        this.curTree = nil
        return []string{}
    } else {
        if this.curTree == nil && len(this.searchString) == 0 {
            this.curTree = this.tTree
        }
        this.searchString = append(this.searchString, c)
        if this.curTree == nil {
            return []string{}
        }
        var ok bool
        this.curTree, ok = this.curTree.Mapper[c]
        if !ok {
            return []string{}
        }
        return this.curTree.GetRecommends();
    }
    
}


/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * obj := Constructor(sentences, times);
 * param_1 := obj.Input(c);
 */
```