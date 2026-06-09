### 解题思路

常规二分法思路

小技巧：将1->n的数x映射到0->n-1，只需要x%n即可


### 参考代码

```
func nextGreatestLetter(letters []byte, target byte) byte {
    left := 0
    right := len(letters)
    min := 0
    for left < right {
        min = left + (right -left)/2
        if letters[min] <= target {
            left = min+1
        }else {
            right = min
        }
    }
    return letters[left%len(letters)]
}
```
**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**



