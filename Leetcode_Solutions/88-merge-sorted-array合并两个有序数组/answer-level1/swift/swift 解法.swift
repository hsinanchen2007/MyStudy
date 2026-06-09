```swift []
class Solution {
    func merge(_ nums1: inout [Int], _ m: Int, _ nums2: [Int], _ n: Int) {
        var len1 = m - 1
        var len2 = n - 1
        var len = m + n - 1;
        while len1 >= 0 && len2 >= 0 {
            if nums1[len1] > nums2[len2] {
                nums1[len] = nums1[len1]
                len1 -= 1
            } else {
                nums1[len] = nums2[len2]
                len2 -= 1
            }
            len -= 1
        }
        while len2 >= 0 {
            nums1[len] = nums2[len2]
            len -= 1
            len2 -= 1
        }
    }
}
```


