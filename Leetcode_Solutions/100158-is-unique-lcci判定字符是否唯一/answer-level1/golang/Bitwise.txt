### 解题思路
```
variable mark : 0000 0000 0000 0000 0000 0000 0000 0000
mark as       :        zy xwvu tsrq ponm lkji hgfe dcba  
``` 

replace map with uint32 as mark which character appeared.     
- satisfy the condition of not use additional data structures.              

### 代码

```golang
func isUnique(astr string) bool {
    var mark uint32 = 0
    for _, ch := range astr {
        move_bit := ch - 'a'
        if mark & (1 << move_bit) != 0 {
            return false
        } else {
            mark |= (1 << move_bit)
        }
    }
    return true
}
```