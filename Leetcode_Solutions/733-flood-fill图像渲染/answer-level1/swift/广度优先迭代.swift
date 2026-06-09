### 解题思路
利用队列迭代，思想上很像遍历二叉树的问题

### 代码

```swift
class Solution {
    func floodFill(_ image: [[Int]], _ sr: Int, _ sc: Int, _ newColor: Int) -> [[Int]] {
        
        //初始化返回数组
        var result = image
        
        //记录初始坐标像素值
        let taget = result[sr][sc]
        
        //用数组模拟一个queue，用于临时存放待渲染的像素点
        var queue:[(Int,Int)] = [(sr,sc)]
        //空间换时间，定义一个数组用来存储已经渲染完成的像素点
        var done = [[Int]]()
        
        //遍历stack，将符合要求的当前像素点的上下左右四个方向的像素点坐标都插入到stack内，同时对当前坐标的像素点渲染
        while !queue.isEmpty {
            
            let top = queue.removeFirst()

            result[top.0][top.1] = newColor
            done.append([top.0, top.1])
            
            //上
            if top.0 - 1 >= 0, result[top.0 - 1][top.1] == taget, !done.contains([top.0 - 1, top.1]) {
                queue.append((top.0 - 1, top.1))
            }
            //下
            if top.0 + 1 < result.count, result[top.0 + 1][top.1] == taget, !done.contains([top.0 + 1, top.1]){
                queue.append((top.0 + 1, top.1))
            }
            //左
            if top.1 - 1 >= 0, result[top.0][top.1 - 1] == taget, !done.contains([top.0, top.1 - 1]) {
                queue.append((top.0, top.1 - 1))
            }
            //右
            if top.1 + 1 < result[0].count, result[top.0][top.1 + 1] == taget, !done.contains([top.0, top.1 + 1]) {
                queue.append((top.0, top.1 + 1))
            }
        }
        
        return  result

    }
}
```