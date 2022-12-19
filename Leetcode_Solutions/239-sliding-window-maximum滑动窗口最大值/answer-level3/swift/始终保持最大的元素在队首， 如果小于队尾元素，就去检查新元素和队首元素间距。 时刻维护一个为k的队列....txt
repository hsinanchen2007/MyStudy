


     func maxSlidingWindow(_ nums: [Int], _ k: Int) -> [Int] {
        var currentMap = [(Int, Int)]()
        var resultArray = [Int]()
        
        for (index, value) in nums.enumerated() {
            
            if(currentMap.count > 0 && index - currentMap.first!.0 >= k) {
                currentMap.removeFirst()
            }
            if(currentMap.count == 0 || currentMap.last!.1 >= value) {
                currentMap.append((index, value))
            } else {
                //重新排序
                while currentMap.count > 0 && currentMap.last!.1 < value  {
                    currentMap.removeLast()
                }
                currentMap.append((index, value))
            }
            
            if(index+1 >= k){
                resultArray.append(currentMap.first!.1)
            }
        }
        return resultArray
    }