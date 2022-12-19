第一种方法：二分查找
```
 func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        var left = 0 , right = nums.count - 1
        while left <= right {
            let mid = (left + right)/2
            if nums[mid] > target{
                right = mid - 1
            }else if nums[mid] < target{
                left = mid + 1
            }else{
                return mid
            }
        }
        
        if left != right{
            return left
        }
        return 0 
    }
```

第二种方法：遍历
```
    func searchInsert(_ nums: [Int], _ target: Int) -> Int {
        
        if nums.count == 0 || nums[0] > target{
            return 0
        }
        
        if nums[nums.count - 1] < target{
            return nums.count
        }
        
        for i in 1..<nums.count
        {
            if nums[i] == target{
                return i
            }else if nums[i] > target && nums[i - 1] < target{
                return i
            }
        }
        return 0
    }
```