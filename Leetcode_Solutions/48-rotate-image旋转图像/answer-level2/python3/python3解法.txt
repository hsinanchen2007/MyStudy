给定一个 n × n 的二维矩阵表示一个图像。

将图像顺时针旋转 90 度。

说明：

你必须在原地旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要使用另一个矩阵来旋转图像。

示例 1:

给定 matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

原地旋转输入矩阵，使其变为:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]

题目要求就是旋转90度，上图：

![WechatIMG4.jpeg](https://pic.leetcode-cn.com/125a1729ca04302c04bf7ee103550e55e8a868a2193ad7c6c8110d50f839e735-WechatIMG4.jpeg)
因为是正方形我们确定好左上和右下的两个点就可以定位到右上和左下的左边，然后我们依次的替换坐标位置的值，完成一轮替换，知道外圈的元素全都替换完成，然后我们把（lr,lc）定位到（lr+1，lc+1）,同理(dr,dc)定位到(dr-1,dc-1)，进入下一层，依次类推即可：
代码：

```
 def rotate(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        lc,lr = 0,0
        dc,dr = len(matrix)-1,len(matrix[0])-1
        while lr <= dr and lc <= dc:
            self.rotateEdge(matrix,lr,lc,dr,dc)
            lr+=1
            lc+=1
            dc-=1
            dr-=1
    def rotateEdge(self,nums,lr,lc,dr,dc):
        times = dc -lc
        for i in range(times):
            nums[lr][lc+i],nums[lr+i][dc],nums[dr][dc-i],nums[dr-i][lc] = nums[dr-i][lc],nums[lr][lc+i],nums[lr+i][dc],nums[dr][dc-i]

``
