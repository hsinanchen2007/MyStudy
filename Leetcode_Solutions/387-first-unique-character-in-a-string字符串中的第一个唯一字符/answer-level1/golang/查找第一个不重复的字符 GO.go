### 解题思路
1. 要找到第一个不重复的字符，那么就需要把整个字符串进行遍历
2. 第一次遍历字符串，使用一个26位的mark数组记录每个字符出现的次数，下标使用s[i]-'a'
3. 第二次遍历字符串，返回字符在mark中标记次数为1的下标，否则返回-1

时间复杂度：  O(n) 
空间复杂度:   O(1)

### 代码

```golang
func firstUniqChar(s string) int {
        mark := [26]int{0}
        
        for _,v := range s {	
            mark[v-'a']++
            //fmt.Println(string(v),mark)
        }
        for k,v := range s {
            if mark[v-'a'] == 1 {
                return k
            }
        }
        // fmt.Println(mark)
        return -1
}
```