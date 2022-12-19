本质还是**滑动窗口**。
因为不想再写个循环找重复点。所以第一次用了hashmap存index。

后来想到所有字符不超过ascii码。所以干脆找了个128数组存index。空间更省速度更快。


第一次写hashmap还是脑子抽了找到重复点后还是写了个小循环把重复点前的index都置零。
再想想就想通了，有begin存开始点。如果index不超过begin都可以当做无效。就不用置零了。


```
func lengthOfLongestSubstring(s string) int {
    if len(s) <= 1{                 //too short to calculate
        return len(s)
    }
    maxLen := 0                     //store the max Length of non-repeat string
    var haveWord [128]int           //use array to replace the hashmap, cause only 128 ascii byte to store.
                                    //The array stores the index of charactors in non-repeat string. 
    begin := 1                      // Use 1 to initiate the begin curb to be different with the default value 0 in array.
    for i,c := range s{
        n := int(c)                 //change rune to int in ascii
        if haveWord[n] >= begin{    // Only if index is bigger than begin curb, slide the window.
            begin = haveWord[n] + 1
            haveWord[n] = i + 1     // refresh begin curb and index info.
        } else {                    //no repeat charactor behind the curb.
            maxLen = max(i-begin + 2, maxLen)       // compare the Max value and refresh
            haveWord[n] = i + 1     //refresh the index info.
        }
    }
    
    return maxLen
}

func max(a, b int) int{    // max function
    if a>b{
        return a
    } else {
        return b
    }
}
```
