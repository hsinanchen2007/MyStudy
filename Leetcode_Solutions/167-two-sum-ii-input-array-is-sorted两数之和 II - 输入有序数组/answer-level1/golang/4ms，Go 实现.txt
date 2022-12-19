
![image.png](https://pic.leetcode-cn.com/5cfad243984ac55fc27e4bd915c9b749a2718c71fd2d13ce51de41438ff22c7a-image.png)

方法一：hash 表（8ms）
```
func twoSum(numbers []int, target int) []int {  // hash 表
    hash := make(map[int]int)   // 存储该数对应的另一个数的下标，这两个数加起来为 target
    for i,x := range numbers {  
        if v,ok := hash[x]; ok {
            return []int{v+1,i+1}
        } else {
            hash[target-x] = i
        }
    }
    return []int{1,2}
}
```

方法二：双向指针（4ms）

因为是有序列表，所以可以设置双向指针 i，j 分别向中间遍历，规则如下：
1. 如果 target - num[i] < num[j]，那么说明 num[j] 有些大，让 j 指针向前移动一个位置；
2. 如果 target - num[i] > num[j]，那么说明 num[i] 有些小，让 i 指针向后移动一个位置；
3. 如果 target - num[i] == num[j]，说明找到了两数之和等于 target 的位置，返回这两个指针代表的位置；

比起有些耗时的 map 操作，用双向指针速度能快一些，充分利用了有序列表的特性。

代码
```
func twoSum(numbers []int, target int) []int {  // 双向指针
    i,j := 0,len(numbers)-1
    for i<j {
        if target-numbers[i] < numbers[j] {
            j--
        } else if target-numbers[i] > numbers[j] {
            i++
        } else {
            return []int{i+1,j+1}
        }
    }
    return []int{1,2}
}
```