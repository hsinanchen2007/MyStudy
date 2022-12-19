### 解题思路
暴力一时爽，一直暴力一直爽。。。
题目中给定 1 <= n,m <= 100   0 <= k <= 20.  这说明啥？ 
这个数量级的题目，不要想什么复杂的算法，暴力就好。

暴力的过程中考虑好边界值的情况，有一个要求，每次只能移动一步。
所以每个方格先检查它的左边或者上边有没有符合条件的，有的话，说明本格可以从现有的1步到达

![image.png](https://pic.leetcode-cn.com/2ebc108ca5a27888c389e288902ed18eb20420a7cc34583d6d599f93875c3529-image.png)



### 代码

```golang
func movingCount(m int, n int, k int) int {
    res := 1
    flag := make([][]int, m)
    for i := 0; i < m; i++ {
        flag[i] = make([]int, n)
    }

    flag[0][0] = 1

    for i := 0; i < m; i++ {
        for j := 0; j < n; j++ {
            if (i - 1 >= 0 && flag[i-1][j] == 1) || (j - 1 >= 0 && flag[i][j-1] == 1) {
                tmp := getStep(i, j)
                if tmp <= k {
                    res++
                    flag[i][j] = 1
                }  
            }
        }
    }
    return res
}

func getStep(a, b int) int {
    res := 0

    for a > 0 {
        res += a % 10
        a /= 10
    }

    for b > 0 {
        res += b % 10
        b /= 10 
    }

    return res
}
```