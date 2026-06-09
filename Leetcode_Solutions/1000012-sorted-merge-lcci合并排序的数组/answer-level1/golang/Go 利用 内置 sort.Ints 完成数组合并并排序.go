### 解题思路
1.先合并B到A中
2.利用sort.Ints() 进行再次排序

![截屏2020-03-0321.24.09.png](https://pic.leetcode-cn.com/590cba22c377fc8925f2a04b7f9c3ddddd839db9bb5c3f23e4d8e62dddcc9a47-%E6%88%AA%E5%B1%8F2020-03-0321.24.09.png)


### 代码

```golang
func merge(A []int, m int, B []int, n int)  {
    for i := 0; i < n; i++ {
        A[m+i] = B[i]
    }

    sort.Ints(A)
    return
}
```