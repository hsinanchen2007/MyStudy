暴力实现：
func romanToInt(_ s: String) -> Int {
        var x = 0
        let dic:[String:Int] = ["I":1,"V":5,"X":10,"L":50,"C":100,"D":500,"M":1000]
        let letters = s.map(String.init)
        var lastLetter:String = ""
        for c in letters {
            let keys = dic.keys
            if !keys.contains(c){
                return 0
            }
            if ((c == "V" || c == "X") && lastLetter == "I")||((c == "L" || c == "C") && lastLetter == "X")||((c == "D" || c == "M") && lastLetter == "C"){
                
                x += (dic[c]! - (dic[lastLetter] ?? 0) - (dic[lastLetter] ?? 0))
                lastLetter = ""
                
            } else {
                x += (dic[c]!)
                lastLetter = c
            }
        }
        return x
    }
