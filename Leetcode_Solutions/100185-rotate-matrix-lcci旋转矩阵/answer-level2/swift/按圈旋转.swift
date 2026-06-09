### 解题思路
// 将二维数组的四周分为四个小数组，无限拆分；
// 行列为奇数，中心点不变，其余和偶数时一致；
// 再将四个数组最后一个放到首位，依次拼接到新的二维数组上
### 代码

```swift
class Solution {
    func rotate(_ matrix: inout [[Int]]) {
        let row = matrix.count
        // 将二维数组的四周分为四个小数组，无限拆分
        // 行列为奇数，中心点不变，其余和偶数时一致
        // 再将四个数组最后一个放到首位，一次拼接到新的二维数组上
        var n = row
        var newMatrix = matrix
        while n/2 >= 1 {
            // 剩余二维数组上右下左的数字排列
            let smallIndex = (row-n)/2
            let bigIndex = row - smallIndex - 1
            let a1 = Array(matrix[smallIndex][smallIndex...bigIndex])
            var a2 = [Int]()
            let a3 = Array(matrix[bigIndex][smallIndex...bigIndex])
            var a4 = [Int]()
            for i in smallIndex...bigIndex {
                a2.append(matrix[i][bigIndex])
                a4.append(matrix[i][smallIndex])
            }
            
            // 旋转后放入新数组
            for i in 0..<a4.count {
                newMatrix[smallIndex][smallIndex+i] = a4.reversed()[i]
            }
            for i in 0..<a1.count {
                newMatrix[smallIndex+i][bigIndex] = a1[i]
            }
            for i in 0..<a2.count {
                newMatrix[bigIndex][smallIndex+i] = a2.reversed()[i]
            }
            for i in 0..<a3.count {
                newMatrix[smallIndex+i][smallIndex] = a3[i]
            }

            n -= 2
        }
        
        matrix = newMatrix
    }
}
```