### 解题思路

建一个大小为26的哈希表，将字母出现的次数放在对应的位置，再按字符串字母顺序遍历哈希表，找出第一个值为1的元素的位置即可。

### 代码

```golang
func firstUniqChar(s string) int {
    hash := make([]int,26);
    for _, j := range s {
        hash[j - 'a']++
    }
    for i , j := range s {
        if hash[j - 'a'] == 1 {
            return i
        }
    }
    return -1
}
```