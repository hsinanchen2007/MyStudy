利用回溯法列出了所有可能
```
class Solution {
    func splitIntoFibonacci(_ S: String) -> [Int] {
        var arr:[Int] = []
        var arrStr:[String] = []
        var usedNumCount = 0
        helper842(S,answer: &arr,useCount: &usedNumCount, strArr: &arrStr)
        return arr
    }
  func helper842(_ S:String, answer asArr: inout [Int], useCount uc: inout Int, strArr strs: inout [String]) {
        for i in 1...S.count {
            if i+uc > S.count {
                break
            }
            let idx1 = S.index(S.startIndex, offsetBy: i+uc)
            let idx2 = S.index(idx1, offsetBy: -i)
            let str = S[idx2..<idx1]
            if let strValue = Int(String(str)) {
              if Double(strValue) > pow(2, 31)-1 {
                    break
                }
                if i > 1 && strValue > 0 && Int(String(S[idx2..<S.index(idx1, offsetBy: -i+1)])) == 0 {
                    break
                }
                uc = uc+i
                asArr.append(strValue)
                strs.append(String(str))
            } else {
                break
            }
            
            if asArr.count >= 3 {
                if asArr[asArr.count-1] - asArr[asArr.count-2] == asArr[asArr.count-3] {
                    helper842(S, answer: &asArr, useCount: &uc, strArr: &strs)
                    if uc == S.count {
                        break
                    } else {
                        asArr.removeLast()
                        uc = uc - numBits(strs.removeLast())
                    }
                } else if asArr[asArr.count-1] - asArr[asArr.count-2] > asArr[asArr.count-3]  {
                    asArr.removeLast()
                    uc = uc - numBits(strs.removeLast())
                    break
                } else {
                    asArr.removeLast()
                    uc = uc - numBits(strs.removeLast())
                }
            } else {
                helper842(S, answer: &asArr, useCount: &uc, strArr: &strs)
                if uc == S.count {
                    if (asArr.count < 3) {
                        asArr.removeLast()
                        uc = uc - numBits(strs.removeLast())
                    }
                    break
                } else {
                    asArr.removeLast()
                    uc = uc - numBits(strs.removeLast())
                }
            }
        }
    }
    private func numBits(_ num:String) -> Int {
        
        return num.count
    }

}
```
