### 解题1
先取两个矩形的中间点坐标，
![企业微信截图_15845146108662.png](https://pic.leetcode-cn.com/5b07bd3f59acf646d8c20c914af892670abf5cc3331fdcf57060d044d507a10c-%E4%BC%81%E4%B8%9A%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_15845146108662.png)
如上图所示，最边界情况，两个矩形一个顶点相同
在这种情况下：
两个中心点的横坐标的距离刚好等于两个矩形一半长相加
两个中心点的纵坐标的距离刚好等于两个矩形一半宽相加
并且当有一个距离大于这个的这两个中心点的距离，则矩形不重合

由此可以得到，当这两个距离都小于中心点横纵坐标距离的时候，矩形重合

### 代码

```golang
func isRectangleOverlap(rec1 []int, rec2 []int) bool {
	var c1 = [2]float64 {float64((rec1[2]-rec1[0])/2) + float64(rec1[0]),float64((rec1[3]-rec1[1])/2) + float64(rec1[1])}
	var c2 = [2]float64 {float64((rec2[2]-rec2[0])/2) + float64(rec2[0]),float64((rec2[3]-rec2[1])/2) + float64(rec2[1])}
	var sumY = c1[1]-float64(rec1[1]) +c2[1]-float64(rec2[1])
	var sumX = c1[0]-float64(rec1[0]) +c2[0]-float64(rec2[0])
	if math.Abs(c1[0]-c2[0])< (sumX) &&math.Abs(c1[1]-c2[1])< (sumY){
		return true
	}else{
		return false
	}
}
```
##解法2
投影，将矩形投影至x轴和y轴，当且仅当x轴和y轴上两个**投影线** 都有重合部分的时候，两矩形重合
但是这样可能性有很多，取其差集
在这拿x轴方向上为例：
在这拿x轴方向上的投影为例：
[图片]
![image.png](https://pic.leetcode-cn.com/db6cd3a816901b3b2a7325d521b3da45c79359350258ffd83921f83e55bbdb4e-image.png)
当一条线段的最小值大于等于另一条线段的最大值，或者这条线段的最大值小于另一条线段的最小值的时候，两个线段无交集

y轴同理
最后  两个条件取交集，得到答案

##代码
```golang
func shadow(rec1 []int, rec2 []int) bool {
	return  !(rec1[0]>=rec2[2]||rec1[2]<=rec2[0]) && !(rec1[1]>=rec2[3]||rec1[3]<=rec2[1])
}
```