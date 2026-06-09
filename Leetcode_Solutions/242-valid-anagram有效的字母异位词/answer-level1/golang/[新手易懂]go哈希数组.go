### 1 最直接是用数组  数组 [0-25] 所以 全部 - 'a'
```
func isAnagram(s string, t string) bool {
    if !(len(s) == len(t)) {
		return false
	}
    m := make([]int,26)
    for i:= 0;i< len(s);i++{
        m[s[i] - 'a']++
        m[t[i] - 'a']--
    }
    for _,e := range(m){
        if e != 0{
            return false
        }
    }
    return true
}
```
 

### 2 还有一种是转rune或者用byte,不然麻烦要用uni8
##### go里面有一点很僵硬，字符串里面存的是rune，即int32。而经过for..range之后，取出来的elem，却是一个uint8，也就是一个byte
以后查询可以这样直接查类型，但是还是全部rune大法好。
```
s := "abac"
for i, elem := range s {
  fmt.Println("elem", fmt.Sprintf("%T", elem))  // int32
  fmt.Println("i", fmt.Sprintf("%T", s[i]))    // uint8
}   
```
```
    func isAnagram(s string, t string) bool {
    if len(s) != len(t) {
        return false
    }
    
    sr := []rune(s)   # 或者  sr := []byte(s)
    tr := []rune(t)
    
    rec := make(map[rune]int, len(sr))
    for i := range sr {
        rec[sr[i]]++
        rec[tr[i]]--
    }
    
    for _, n := range rec {
        if n != 0 {
            return false
        }
    }
    
    return true
}
```

