查到重复直接返回即可
```
class Solution {
    func repeatedNTimes(_ A: [Int]) -> Int {
        var set:[Int] = []
        for (_,v) in A.enumerated(){
            if set.contains(v){
                return v
            }else{
                set.append(v)
            }
        }
        return 0
    }
}
```