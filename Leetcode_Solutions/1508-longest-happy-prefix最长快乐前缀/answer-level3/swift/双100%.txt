TLE到爆炸,暴力解很容易想,毫不意外的TLE了。

这个题目另一种思路是kmp算法，这个算法可以用来高效的求解一个子串是否包含另一个子串这样的题，kmp算法的过程中要求出一个next数组。。而这个next数组(也称前缀表)就是该题的主要思路,网上有很多kmp算法的讲解，这里就不过多阐述

    class Solution {
        func longestPrefix(_ s: String) -> String {
            let array = Array(s)
            var prefixTable: [Int] = [Int](repeating: 0, count: array.count)
            var res = ""
            if (array.count > 0){
                prefix_table(array, &prefixTable, array.count)
                for index in 0..<prefixTable[s.count-1] {
                    res = res + String(array[index])
                }
            }
            return res
        }
        
        func prefix_table(_ array: [Character], _ prefixTable: inout [Int], _ length: Int) -> Void {
            prefixTable[0] = 0
            var i = 0
            var j = 1
            while j < length {
                if (array[i].asciiValue! == array[j].asciiValue!){
                    i = i + 1
                    prefixTable[j] = i
                    j = j + 1
                }else{
                    if (i > 0){
                        i = prefixTable[i-1]
                    }else{
                        prefixTable[j] = i;  //prefixTable[j] = 0
                        j = j + 1
                    }
                }
            }
        }
        
}