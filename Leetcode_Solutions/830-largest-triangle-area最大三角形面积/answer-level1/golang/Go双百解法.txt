在给出所有点坐标的情况下，无疑，采用数学方法是最好的，这里用的是三角形面积的行列式解法
三重循环解行列式即可
行列式解法：S=|(a\*d+b\*e+c\*f-d\*e-c\*d-a\*f)|/2
![微信截图_20200223093754.png](https://pic.leetcode-cn.com/9fef61f8e6e4e1599748986b65068e24c5d4e2e11c329f977d8b31605702af5b-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200223093754.png)

代码如下：

```golang
func largestTriangleArea(points [][]int) float64 {
    res:=0
	for i:=0;i<len(points)-2;i++{
		for j:=i+1;j<len(points)-1;j++{
			for k:=j+1;k<len(points);k++{
				temp:=points[i][0]*points[j][1] + points[j][0]*points[k][1] + points[k][0]*points[i][1] - points[j][1]*points[k][0]-points[i][1]*points[j][0]-points[i][0]*points[k][1]
				if abs(temp)>res {
					res=abs(temp)
				}
			}
		}
	}
	return float64(res)/2
}
func abs(i int) int {
	if i < 0 {
		i = -i
	}
	return i
}
```