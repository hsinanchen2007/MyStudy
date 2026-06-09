![image.png](https://pic.leetcode-cn.com/1b2f9df4f59efd98e460ca3959dca585362cc44557d1c47425de0fcc61841ead-image.png)

最先想到的是 hash 表记录出现过的数字，然后再扫描一遍找到唯一的那个数字。这个方法时间复杂度为 O(n)，空间复杂度为 O(n)。

然后发现不符合空间复杂度 O(1) 的要求，看了大佬的题解后，发现可以用异或思想：一个数异或两次另外一个数，会还原回去。比如：3^5^5=3。

而根据题目，数组中的除了要找的数字只出现过一次，另外所有数都出现了两次。所以从头将所有数异或一遍，最后的结果就是那个只出现一次的数。

异或思想，时间复杂度 O(n)，空间复杂度 O(1)，巧妙的思路。

方法一：hash 表（28ms）
```
func singleNumber(nums []int) int { // 哈希 map 实现
    hash := make(map[int]bool)      // 记录是否只出现过一次
    for _,x := range nums {
        if _,ok := hash[x]; ok {    // 已经出现过一次
            hash[x] = false
        } else {    // 还没出现过
            hash[x] = true
        }
    }
    for k,v := range hash {         // 找到那个只出现过一次的数
        if v {
            return k
        }
    }
    return 0
}
```

方法二：异或思路（8ms）
```
func singleNumber(nums []int) int { // 异或思想
    result := 0
    for _,x := range nums {
        result = result ^ x
    }
    return result
}
```