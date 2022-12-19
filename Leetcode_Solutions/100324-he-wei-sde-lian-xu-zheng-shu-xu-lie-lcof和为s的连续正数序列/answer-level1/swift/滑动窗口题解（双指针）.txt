    func findContinuousSequence(_ target: Int) -> [[Int]] {
        if target == 1 {
            return []
        }
        var arr = [[Int]]()
        var min = 1
        var max = 2
        var sum = min + max
        while max <= target/2 + 1 {
            sum = (min + max) * (max - min + 1) / 2;
            if sum < target {
                max = max + 1
            } else if (sum == target) {
                var innerArr = [Int]()
                for i in min...max {
                    innerArr.append(i);
                }
                arr.append(innerArr);
                max = max + 1
            } else {
                if min + 1 < max {
                    min = min + 1
                } else {
                    break
                }
            }
        }
        
        return arr
    }