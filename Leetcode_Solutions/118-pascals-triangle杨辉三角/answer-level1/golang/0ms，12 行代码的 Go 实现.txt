
![image.png](https://pic.leetcode-cn.com/594d6dc545c29863e7b3d266b30aab31be8ae7bfec2bcf1bc28ddedf691f9d08-image.png)

代码
```
func generate(numRows int) [][]int {
    result := [][]int{[]int{1}, []int{1,1}}     // 先放进去前两行
    for i:=2; i<numRows; i++ {                  // 从第三行继续生成杨辉三角
        a := []int{1}                           
        for j:=1; j<i; j++ {                    // 计算当前行
            a = append(a, result[i-1][j-1] + result[i-1][j])
        }
        a = append(a, 1)
        result = append(result, a)
    }
    return result[:numRows]
}
```