```
func lengthOfLongestSubstring(s string) int {
    var (
        mmap = make(map[int]int)
        length = 0
        start = 0
        str = []rune(s)
    )
    for i := 0; i < len(str); i++ {
        val := int(str[i])
        
        v, ok := mmap[val]
        // 键值不存在 字符首次出现
        if !ok {
            if i-start + 1 > length {
                length = i - start + 1
            }
            mmap[val] = i
            continue
        } else {
             // 字符非首次出现,将左侧游标start移动到首次出现位置v下一个位置，并将之前已加入mmap中的键全部删除
            for j := start; j < v + 1; j++ {
                delete(mmap, int(str[j]))
            }
            start = v + 1
            mmap[val] = i
            if i-start + 1 > length {
                length = i - start + 1
            } 
        }  
    }
    return length    
}
```
解题思路：使用一个滑动窗口记录当前最长的不重复子串，start是窗口左侧角标，v是窗口右侧角标，初始start v从0开始，左侧start不动，右侧v向右递增，当遇到前面出现过的字符时，右侧v不动，左侧start向右滑动，并且删除mmap记录的已出现的字符及其左侧的全部键值对。