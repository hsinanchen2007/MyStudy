   执行用时 :228 ms，在所有 Swift 提交中击败了100.00%的用户。内存消耗 :23.6 MB, 在所有 Swift 提交中击败了100.00%的用户。
 
    //快速排序
    func sortArray(_ nums: [Int]) -> [Int] {
        var arr = nums
        quickSort(&arr, 0, arr.count - 1)
        return arr
    }
    
    private func quickSort(_ nums: inout [Int], _ left: Int, _ right: Int) {
        if left >= right {
            return
        }
        
        var i = left;
        var j = right;
        
        let key = nums[i];
        
        while i<j {

            while i<j && nums[j] >= key{
                j -= 1;
            }

            nums[i] = nums[j];

            while i<j && nums[i] <= key{
                i += 1;
            }

            nums[j] = nums[i]
        }

        nums[i] = key;
        self.quickSort(&nums, left, i-1)
        self.quickSort(&nums, i+1, right)
    }