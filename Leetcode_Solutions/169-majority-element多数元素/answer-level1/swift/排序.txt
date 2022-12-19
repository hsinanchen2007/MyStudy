func majorityElement(_ nums: [Int]) -> Int {
    var newNums = nums
    newNums.sort()
    let index = newNums.count/2// + newNums.count%2
    return newNums[index]
}