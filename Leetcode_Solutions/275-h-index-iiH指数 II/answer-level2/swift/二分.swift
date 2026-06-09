```
class Solution {
     func hIndex(_ citations: [Int]) -> Int {
        let length = citations.count;
        var left = 0;
        var right = length - 1;
        while left <= right {
            let middle = (left + right) / 2;
            if (citations[middle] == length - middle ) {
                return length - middle;
            } else if (citations[middle] > length - middle) {
                right = middle - 1;
            } else {
                left = middle  + 1;
            }
        }
        return length - left;
    }
}
```
