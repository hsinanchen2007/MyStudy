```
func dayOfYear(_ date: String) -> Int {
    var monthMap = [ 0,
                     31, 28, 31,
                     30, 31, 30,
                     31, 31, 30,
                     31, 30]
    
    let dateArray = date.split(separator: "-")
    
    let y = Int(dateArray[0])!
    let m = Int(dateArray[1])!
    let d = Int(dateArray[2])!
    
    let isRun = ((y % 4 == 0) && (y % 100 != 0)) || (y % 400 == 0)
    
    if isRun {
        monthMap[2] = 29
    }
    
    var rs = 0
    
    for i in 0 ..< m {
        rs += monthMap[i]
    }
    
    rs += d
    
    return rs
}
```

![Screen Shot 2019-08-13 at 00.25.39.png](https://pic.leetcode-cn.com/5dbe9dd39860abf1c13213add91f50fdbc5c95a1f9f3d3a79a3d9aa54e66b8f4-Screen%20Shot%202019-08-13%20at%2000.25.39.png)
