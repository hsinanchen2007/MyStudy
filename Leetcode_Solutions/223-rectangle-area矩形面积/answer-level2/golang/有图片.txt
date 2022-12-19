### 解题思路
![3333.png](https://pic.leetcode-cn.com/dbd378caa12e3f0e75b8b764828ea810f4f2ddd93f06b2505b072043ea3e966c-3333.png)

有用的话点个赞 让我知道
### 代码

```golang
func computeArea(zuo1 int, xia1 int, you1 int, shang1 int, zuo2 int, xia2 int, you2 int, shang2 int) int {
    mianji1:=(you1-zuo1)*(shang1-xia1)
    mianji2:=(you2-zuo2)*(shang2-xia2)
    if you1<=zuo2||shang1<=xia2||zuo1>=you2||xia1>=shang2{
        return mianji1+mianji2
    }
    
	zuo := max(zuo1, zuo2)
	xia := max(xia1, xia2)
	you := min(you1, you2)
	shang := min(shang1, shang2)
	return mianji1+mianji2- (you - zuo) * (shang - xia)
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}
```