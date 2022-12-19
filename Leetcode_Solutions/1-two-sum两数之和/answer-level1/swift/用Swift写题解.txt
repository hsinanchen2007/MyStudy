```objc
func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
      let count = nums.count
        var resoultDictionary:Dictionary<Int, Int> = [Int:Int]();
        for index in 0..<count {
            let res = target - nums[index];
            if(resoultDictionary.keys.contains(res)) {
                return [(resoultDictionary[(res)] ?? 0),index];
            }
            resoultDictionary.updateValue(index, forKey: nums[index])
        }
        return [];
    }
```