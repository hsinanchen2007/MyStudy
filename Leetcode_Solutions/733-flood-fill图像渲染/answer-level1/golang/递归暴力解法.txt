### 解题思路
此处撰写解题思路

### 代码

```golang
func floodFill(image [][]int, sr int, sc int, newColor int) [][]int {
	pre:=image[sr][sc]
	//当new 等于 pre的时候 直接返回 image，不然在 后面的 help方法中会陷入死循环
	if pre==newColor{
		return image
	}
	helpFloodFill(&image,sr,sc,newColor,pre)
	return image
}

func helpFloodFill(image *[][]int,i,j,newColor,pre int){
	if i>=0&&i< len(*image)&&j>=0&&j<len((*image)[0]){
		if (*image)[i][j]==pre&&(*image)[i][j]!=newColor{
			(*image)[i][j]=newColor
			helpFloodFill(image ,i-1,j,newColor,pre )
			helpFloodFill(image ,i+1,j,newColor,pre )
			helpFloodFill(image ,i,j-1,newColor,pre )
			helpFloodFill(image ,i,j+1,newColor,pre )
		}
	}else{
		return
	}

}
```