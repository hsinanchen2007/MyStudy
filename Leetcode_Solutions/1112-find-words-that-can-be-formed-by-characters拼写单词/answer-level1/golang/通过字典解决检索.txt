### 解题思路
* map能够加快字符检索效率
* 通过json.Marshal和json.Unmarshal来解决字典重复使用

### 代码

```golang
func countCharacters(words []string, chars string) int {
  cnts := 0
  hashStr := charsSerial(chars)

  for _,word := range words {
    cnt := masteWord(word, hashStr)
    cnts += cnt
  }

  return  cnts

}


func charsSerial(chars string)  []byte{
  hash := make(map[byte]int)
  for _, c := range chars{
    ch := byte(c)
    val, ok := hash[ch]
    if ok {
      hash[ch] = val + 1
    }else{
      hash[ch] = 1
    }
  }
  hashStr, _ := json.Marshal(hash)
  return hashStr
}

func masteWord(words string, hashStr []byte) int{
  hash := make(map[byte]int)
  _ = json.Unmarshal(hashStr,&hash)
  cnt := 0
  for _,c  := range words{
    ch := byte(c)
    num,ok := hash[ch]
    if ! ok  || (ok && num == 0){
      return 0
    }else{
      hash[ch] = num - 1
    }
    cnt += 1
  }
  return cnt
}
```