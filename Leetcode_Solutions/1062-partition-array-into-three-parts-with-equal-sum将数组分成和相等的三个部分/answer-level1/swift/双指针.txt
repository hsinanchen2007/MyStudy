
func canThreePartsEqualSum(_ A: [Int]) -> Bool {
 
    if A.count < 3 {
        return false
    }
    
    var sum = 0
    for i in A {
        sum = sum + i
    }

    if sum % 3 != 0 {
        return false
    }
    
    var blockSum = sum / 3
    var firstSum = 0
    var secondSum = 0
    for i in 0...A.count - 3 {
        firstSum = firstSum + A[i]
        if firstSum == blockSum {
            for j in i+1 ... A.count - 2 {
                secondSum = secondSum + A[j]
                if secondSum == blockSum {
                    return true
                }
            }
        }
    }
    return false
}