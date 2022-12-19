
![image.png](https://pic.leetcode-cn.com/6ccedd25fc56bef95d20641436de46c5e45a3e73f797ca342224f51fab6eb033-image.png)

方法一：笨办法，三重循环（1916 ms）
```
func dist(i,j []int) int {      // 两点间的距离
    return (i[0]-j[0])*(i[0]-j[0]) + (i[1]-j[1])*(i[1]-j[1])
}

func judge(i,j,k []int) int {   // 计算这三个点能构成几个“回旋镖”
    cnt := 0
    if dist(i,j) == dist(i,k) {
        cnt+=2
    }
    if dist(j,i) == dist(j,k) {
        cnt+=2
    }
    if dist(k,i) == dist(k,j) {
        cnt+=2
    }
    return cnt
}

func numberOfBoomerangs(points [][]int) int {   // 三层循环遍历每个三元组
    ans := 0
    for i:=0; i<len(points)-2; i++ {
        for j:=i+1; j<len(points)-1; j++ {
            for k:=j+1; k<len(points); k++ {
                ans += judge(points[i],points[j],points[k])
            }
        }
    }
    return ans
}
```

方法二：两重循环，用 hash 表记录出现过的距离（228ms）

遍历每个点和它所有点的距离，用 hash 表记录，如果出现重复的，说明可以形成“回旋镖”，累计个数
```
func dist(i,j []int) int {      // 两点间的距离
    return (i[0]-j[0])*(i[0]-j[0]) + (i[1]-j[1])*(i[1]-j[1])
}

func numberOfBoomerangs(points [][]int) int {   // 两重循环，hash 表
    ans := 0
    hash := map[int]int{}
    for i:=0; i<len(points); i++ {
        for j:=0; j<len(points); j++ {
            if i!=j {
                d := dist(points[i],points[j])
                if hash[d] > 0 {    // 这个距离出现过，累计回旋镖个数
                    ans += hash[d]*2
                }
                hash[d]++
            }
        }
        hash = map[int]int{}        // 算新的起点时，清空 hash 表
    }
    return ans
}
```