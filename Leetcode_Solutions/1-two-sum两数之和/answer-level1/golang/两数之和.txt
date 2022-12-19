1、建立一个map[int]int来存储遍历的值和计算的结果（map[value]position）
2、遍历nums，用target减去当前遍历的值，存储到一个变量中
3、用这一个计算结果，在第一步建立的map中找key，如果找到了这个key，则直接返回当前的position和map[key]即可
4、如果没有找到key，则把计算结果作为key存入map中，value存position
...进入下一次循环

测试结果：
![微信截图_20190731131604.png](https://pic.leetcode-cn.com/f0a6a525837bbe24255080765c5f4b07b7b8745ce9f7799c0c6d1bdbc0cb20ef-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20190731131604.png)



```
func twoSum(nums []int, target int) []int {
    numMap := make(map[int]int)
    for i, value := range nums {
        n := target - value
        _, ok := numMap[n]; if ok {
            return []int{i, numMap[n]}
        }
        numMap[value] = i
    }
    return []int{1,1}
}
```
