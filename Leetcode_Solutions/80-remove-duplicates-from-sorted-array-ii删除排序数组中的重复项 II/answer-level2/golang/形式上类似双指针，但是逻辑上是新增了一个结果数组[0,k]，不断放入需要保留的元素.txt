### 解题思路

定义一个逻辑上的结果数组[0..k],把需要保留的元素不断该结果数组中添加，最好返回结果数组的元素个数k+1。

![image.png](https://pic.leetcode-cn.com/4b910a323486190496c49333020678758ed0c3eef743a774dad31eff578f410d-image.png)



### 代码

```golang
func removeDuplicates(nums []int) int {
    k := 1 // [0,k] 存放需要保留的元素。初始化k=1，因为[0,1]是肯定需要放入数组中的
    for i:=2;i<len(nums);i++{
        if nums[i] != nums[k-1]{
            k++
            nums[k] = nums[i]
        }
    }
    return k+1
}
```