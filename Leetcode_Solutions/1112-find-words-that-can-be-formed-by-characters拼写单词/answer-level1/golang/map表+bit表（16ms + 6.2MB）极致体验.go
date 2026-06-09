整体思路：
1. 将提供的字符串转化为每个字符对应的数量映射表
2. 遍历每个单词，用中间map记录字符和数量，如果有超过提供的数量就直接返回
3. 最后将所有的使用字符数量加起来就行了

算法整体复杂度是O(n)的。但是map的查找可能会比较耗时。有hash计算在里面，如果改成bit表是不是会好很多，因为本身是定长的，而且数据直接index操作（内存地址+）应该会快。


map
```
func countCharacters(words []string, chars string) int {
    source_map := extracMap(chars)

    target_map := map[rune]int{}
    // count_map := map[rune]int{}
    for _,str:=range words{
        checkWord(str, source_map,target_map)
    }
    count := 0
    for _,v:=range target_map{
        count += v
    }
    return count
}

func extracMap(chars string) map[rune]int{
    source_map := map[rune]int{}
    for _, ch :=range chars {
        source_map[ch]+=1
    }
    return source_map
}

func checkWord(word string, source_map, target_map map[rune]int) {
    // defer func(){
    //     for k,_:=range count_map{
    //         count_map[k]=0
    //     }
    // }()
    count_map := map[rune]int{}
    for _,ch:=range word{
        if v,ok:=source_map[ch];ok{
            count_map[ch]+=1
            if count_map[ch] > v{
                return
            }
        } else {
            return
        }
    }
    for k,v:=range count_map{
        target_map[k]+=v
    }
    return
}
```

bit表
```
type bitMap = [26]int
var a rune = 'a'

func countCharacters(words []string, chars string) int {
    source_map := extracMap(chars)

    target_map := bitMap{}
    count_map := bitMap{}
    count := 0
    for _,str:=range words{
        count += checkWord(str, source_map,target_map, count_map)
    }
    return count
}

func extracMap(chars string) bitMap{
    source_map := bitMap{}
    for _, ch :=range chars {
        source_map[ch-a] +=1
    }
    return source_map
}

func checkWord(word string, source_map, target_map, count_map bitMap) int{
    defer func(){
        for index :=range count_map{
            count_map[index]=0
        }
    }()
    
    for _,ch:=range word{
        if source_map[ch-a] > 0{
            count_map[ch-a]+=1
            if count_map[ch-a] > source_map[ch-a]{
                return 0
            }
        } else {
            return 0
        }
    }
    count := 0
    for _,v:=range count_map{
        count +=v
    }
    return count
}
```