先把两个数组去重，然后在大的数组里面查询小的数组是否重合，效率较高
```
class Solution {
    func intersection(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        var n1 = Set(nums1)
        var n2 = Set(nums2)
        var result:[Int] = []
        if n1.count>n2.count {
            for item in n2 {
                if n1.contains(item){
                    result.append(item)
                }
            }
        }else{
            for item in n1 {
                if n2.contains(item){
                    result.append(item)
                }
            }
        }
        return result
    }
}
```
swift自带的api，效率不如第一个快
```
class Solution {
    func intersection(_ nums1: [Int], _ nums2: [Int]) -> [Int] {
        return Array(Set(nums1).intersection(Set(nums2)))
    }
}
```
