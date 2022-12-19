思路：
从左到右，依次查找到能一次跳到目的地的位置des最后位置k，然后将目的地位置des更新为k，递归循环到k=0，每地递归一次步数+1，最后返回步数。另外如果全部出现全部为1的情况，添加标签flag，表示到达目的地的位置之前的元素是否全为1，如果全为1，且最后一步k = des - 1，直接返回des-1 +jumps（之前的步数）。
代码如下：
```
var jumps = 0
func jump(_ nums: [Int]) -> Int {
        
    if nums.count < 2 {
        return 0
    }
    return jumpTo(nums.count - 1, nums: nums)
    
}
func jumpTo(_ des:Int,nums:[Int]) -> Int {
        
    var k = 0
    jumps += 1
    var isnoOne = true  ///不是所有的元素都为1
    
    while k < des && nums[k] + k < des {///查找到目的地des的最后一跳的位置
        if nums[k] != 1{///过程中是否存在全为1的元素
            isnoOne = false
        }
        k += 1
    }
    if k == 0 {
        return jumps;
    }else if k == des - 1 && isnoOne{///des之前的元素都为1，且最后一步的位置在des - 1
        return des + jumps - 1
    }else{
        return jumpTo(k, nums: nums)///更新目的地为找到的最后一跳的位置
    }
    
}
```
