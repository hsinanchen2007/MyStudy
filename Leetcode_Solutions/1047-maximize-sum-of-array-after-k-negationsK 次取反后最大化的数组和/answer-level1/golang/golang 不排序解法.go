### 解题思路

将A中的每个数映射到s数组里，这样无形中就相当进行了一次排序，然后遍历该数组的过程中进行反转计算，这里的遍历的方式有两种：

* 一个数字一个数字的依次反转，K依次减1
* 另一种是，将相同的数字一次性反转，K减去反转的相同数字的个数

为了尽可能提升速度，以下采用了第二种解法

由于题目已说明不能对数组进行修改，所以不考虑排序的方法


### 参考代码

```go
func largestSumAfterKNegations(A []int, K int) int {
    var s = [201]int{}
    sum:=0
    for _,value := range A {
        s[value+100]++
    }
    temp := 0
    for key,value := range s {
        if value > 0 {
            if K > 0 && key < 100 {
                if K >= value {
                    sum = sum-(key-100) * value
                    K-=value
                }else {
                    sum = sum-(key-100) * K + (key-100) * (value- K)
                    K=0
                }

            }else if K > 0 && key >= 100 {
                if K & 1 == 0 {
                    sum+= (key-100) * value

                }else {
                    if -(temp-100) < key-100 {
                        sum = sum + (temp-100)*2 + (key-100)*value
                    }else {
                        sum = sum - (key-100) * 1 + (key-100) * (value-1)
                    }
                }
                K = 0
            }else {
                sum+=(key-100) * value
            }
            temp = key
        }

    }
    return sum

}

```
**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**


