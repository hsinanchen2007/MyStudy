### 解题思路
（1）选出一个最小的字符串作为基准串
（2）判断这个基准串是否是字符串数组中所有其他字符串的前缀
（3）如果是，则此基准串为该字符串数组的最大前缀字串
（4）如果不是，基准串尾部砍去一个字符，重新执行（2）

### 代码

```golang
func longestCommonPrefix(strs []string) string {
    if strs == nil || len(strs) == 0{
        return ""
    }
    minLength := len(strs[0])
    minIndex := 0
    //获取最小字符串 作为基准串
    for k, str := range strs{
        if minLength > len(str){
         minLength = len(str)
         minIndex = k
        }   
    }
    baseStr :=  strs[minIndex]
    //判断基准串是否是所有字符串的公共字串，如果不是基准串缩短一个字符
    for{
        if !judgeMentPublicStr(strs, baseStr){
            if len(baseStr) > 0{
            //基准串缩短，重复判断, 注意前开后闭
            baseStr = baseStr[:len(baseStr)-1]
            }else{
                break
            }
        }else{
            break
        }
    }
        return baseStr
}
//判断字符串数组中是否包含基准串
func judgeMentPublicStr(strs []string, strBase string)bool{
    var res bool
    for _, str := range strs{
        if !strings.HasPrefix(str, strBase){
            res = false
             break
        }else{
             res = true
        }
    }
    return res
}

```