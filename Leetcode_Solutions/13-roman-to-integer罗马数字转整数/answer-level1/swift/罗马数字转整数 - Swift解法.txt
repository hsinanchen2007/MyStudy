解题思路：将所有的罗马数字相加，如果有前一个罗马数<后一个罗马数的情况，则将数字转为负数相加，否则会出现加两次的情况，而且这样也不需要执行i++操作，且swift中没有i++ 
                  注意越界问题
  
    func romanToInt(_ str: String) -> Int {
        
        var result = 0;
        
        let count = str.count;
        
        for (index, value) in str.enumerated() {
            
            var endIndex:String.Index;
            
            // 防止越界
            if (index < count - 1) {
                
                endIndex = str.index(str.startIndex, offsetBy: index + 1);
                
            } else {
                
                endIndex = str.index(str.startIndex, offsetBy: index);
            }
            
            switch value {
                
            case "I" :
                
                if (str[endIndex] == "V") {
                    result += -1;
                } else if (str[endIndex] == "X") {
                    result += -1;
                } else {
                    result += 1;
                }
                
            case "V" :
                
                result += 5;
                
            case "X" :
                
                if (str[endIndex] == "L") {
                    result += -10;
                } else if (str[endIndex] == "C") {
                    result += -10;
                } else {
                    result += 10;
                }
                
            case "L" :
                
                result += 50;
                
            case "C" :
                if (str[endIndex] == "D") {
                    result += -100;
                } else if (str[endIndex] == "M") {
                    result += -100;
                } else {
                    result += 100;
                }
                
            case "D" :
                
                result += 500;
                
            case "M" :
                
                result += 1000;
                
            default :
                print("");
            }
            
        }
        
        return result;
    }

![image.png](https://pic.leetcode-cn.com/034599c872418132474a5055de89ed05e275037492f8ddbc4690baad9959ed60-image.png)
