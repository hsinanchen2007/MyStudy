### 解题思路
* 字典树的实现就不说了，本题的难点在'.'通配符，通过变量子节点来解决

### 代码

```golang
type WordDictionary struct {
  children map[rune]*WordDictionary
  value rune
  isEnd bool
}


/** Initialize your data structure here. */
func Constructor() WordDictionary {
  return WordDictionary{children: make(map[rune]*WordDictionary)}
}


/** Adds a word into the data structure. */
func (this *WordDictionary) AddWord(word string)  {
  cur := this
  for _,w := range word{
    if _,ok := cur.children[w];!ok{
      cur.children[w] = & WordDictionary{children: make(map[rune]*WordDictionary),value:w,isEnd:false}
    }
    cur = cur.children[w]
  }
  cur.isEnd = true
}


/** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
func (this *WordDictionary) Search(word string) bool {
  if len(word) == 1{
    if word[0] == '.' {
      for _,v := range this.children{
        if v.isEnd == true{
          return true
        }
      }
      return false
    }else{
      if  _,ok := this.children[rune(word[0])]; ok && this.children[rune(word[0])].isEnd {
        return  true
      }else{
        return false
      }
    }
  }
  if word[0] == '.'{
    for _,v  := range this.children {
      if v.Search(word[1:]){
        return  true
      }
    }
    return false
  }else{
    if next,ok:=this.children[rune(word[0])]; ok {
      return next.Search(word[1:])
    }else{
      return false
    }
  }
}


/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */
```