```
func isLongPressedName(name string, typed string) bool {
        i, j := 0, 0
        for i < len(name) && j < len(typed){
            if name[i] == typed[j]{
                i++
                j++
            }else{
                if i == 0{
                    return false
                }
                if typed[j] == name[i-1]{
                    j++
                }else{
                    return false
                }
            }
        }
    if i < len(name){
        return false
    }
    return true
    
}
```

![image.png](https://pic.leetcode-cn.com/1b37742f4ec6eaf624f470570bd9fbe39bf5e349830e2c1b37f7d1c02240b182-image.png)