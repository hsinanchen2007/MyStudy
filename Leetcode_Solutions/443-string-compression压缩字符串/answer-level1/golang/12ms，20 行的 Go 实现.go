
![image.png](https://pic.leetcode-cn.com/8202f84d429cb4042a6528d53f2e740bf5194e07c15f1f12eb6e3902095ef947-image.png)

累计每个字母出现的次数，然后当和下一个字母不同时就将次数用 append 累加到新数组切片后面

因为新数组切片的容量和原数组一样，所以它们会一直共用一个底层数组，而且新数组长度不会超过原数组，不用担心 append 之后会超出容量从而创建新的底层数组。这样的话就不会开新的空间，新数组切片只记录原数组的一个地址而已。

代码
```
func compress(chars []byte) int {
    j := 1
    newchars := chars[:1]       // 创建新的切片，但是容量不变，所以不会创建新的底层数组，数组地址不变
    for i,cnt:=0,1; i<len(chars); i++ {
        if i==len(chars)-1 || chars[i] != chars[i+1] {      // 和下一个字符不同的时候，加入当前字符出现的次数，然后加入下一个字符
            if cnt != 1 {
                num := []byte(strconv.Itoa(cnt))
                newchars = append(newchars[:j], num...)     // 加入当前字母出现的次数
                j += len(num)
            }
            if i<len(chars)-1 {                             // 不是最后一个字母
                newchars = append(newchars[:j], chars[i+1]) // 加入新字母
                j++
                cnt = 0
            }
        }
        cnt++
    }
    return j
}
```