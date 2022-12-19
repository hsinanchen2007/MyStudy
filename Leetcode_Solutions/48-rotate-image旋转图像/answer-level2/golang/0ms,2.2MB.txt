![image.png](https://pic.leetcode-cn.com/5b53a0d7c2701616b9e4a639bc1ae80429edfc057779ca5bc2ccd93cb0c385da-image.png)

### 解题思路
要在原来的矩阵上旋转，那么一次需要旋转4个值。
然后在想，能否因此旋转一排，从外向内，一次旋转最外圈，再转内圈，直到中心停止旋转。
难点就是这4个位置的坐标比较难绕，找出来之后编码也简单，前一个赋值给后一个转一圈就可以了
### 代码

```golang
func rotate(matrix [][]int)  {
    trans(matrix,0)
}

func trans(matrix [][]int,idx int){
    length:=len(matrix)
    if idx>len(matrix)/2{
        return
    }
    //lt:matrix[idx][i]
    //rt:matrix[i][len(matrix)-1-idx]
    //lb:matrix[len(matrix)-1-idx][len(matrix)-1- i]
    //rb:matrix[len(matrix)-1-i][idx]
    for i:=idx;i<len(matrix)-1-idx;i++{
        matrix[idx][i],
        matrix[i][len(matrix)-1-idx],
        matrix[len(matrix)-1-idx][len(matrix)-1- i],
        matrix[len(matrix)-1-i][idx] = 
        matrix[len(matrix)-1-i][idx],
        matrix[idx][i],
        matrix[i][len(matrix)-1-idx],
        matrix[len(matrix)-1-idx][len(matrix)-1- i]
    }
    trans(matrix,idx+1)
}
```