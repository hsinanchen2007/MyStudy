class Solution {
       func twoSum(_ nums: [Int], _ target: Int) -> [Int] {

        var dict = Dictionary<Int,Int>()
        var i = 0;
        while i<nums.count {
            let num1 = nums[i];
            let num2 = target - num1;
            if dict[num2] == nil {
                dict[num1] = i;
                i+=1;}
            else {return [dict[num2]!,i];}
        }
        return [0]
    }
}
欢迎补充更优解