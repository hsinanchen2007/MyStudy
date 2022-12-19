### 解题思路
1.设置一个标志位 isadd 用来每次遍历元素 判断是否满足筛选条件 满足则设置为1，否则设为0
2.处理筛选完的元素集合 进行自定义规则排序

### 代码

```golang

func filterRestaurants(restaurants [][]int, veganFriendly int, maxPrice int, maxDistance int) []int {
    var isadd int = 1   //标记是否将当前遍历的元素添加到result数组
    var result [][]int
    var re []int
    for _, v := range restaurants{
        isadd = 1
        if veganFriendly == 1{
            if v[2] == 0{
                isadd = 0
            }
        }
        if v[3] > maxPrice || v[4] > maxDistance{
            isadd = 0
        }
        if isadd == 1{
            result = append(result, v)
        }
    }
    sort.Slice(result,func(i, j int) bool { 
        if result[i][1] > result[j][1] ||(
            result[i][1] == result[j][1] && result[i][0]>= result[j][0]){ 
            return true 
        }else{ 
            return false 
            }
        })
    for _,v := range result{
        re = append(re,v[0])
    }
    return re
}
```