
![微信截图_20200117140448.png](https://pic.leetcode-cn.com/2376be11d7e02150d3a5a73cdf82db4dfa7e3ac28955110b3734bc0d46471fed-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200117140448.png)

### 解题思路
此处撰写解题思路

### 代码

```golang
func getRow(rowIndex int) []int {
    if rowIndex == 0 {
        return []int{1}
    }  
    ans := make([]int,rowIndex+1)
    ans[0] =1
    for i:=1;i<=rowIndex;i++{
        ans[i] = 1
        for j:=i-1;j>=1;j--{
            ans[j] +=ans[j-1]
        }
    }
    return ans

}
```