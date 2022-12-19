
![WeChat07846fdc473a3775e64156ab8c9cc52b.png](https://pic.leetcode-cn.com/456175b292639be137797ecd4ad275d414252656a48bf925141b9adb2370d196-WeChat07846fdc473a3775e64156ab8c9cc52b.png)

```
func plusOne(digits []int) []int {
    copy := digits
    if len(digits) == 0{
        return digits
    }

    var jinwei = 0
    for index := len(digits)-1;index>=0;index--{
        var currSum = digits[index]
        if index == len(digits) -1{
            currSum = digits[index] + 1
        }

        if jinwei == 1{
            currSum += jinwei
            jinwei = 0
        }
        if currSum >= 10{
            jinwei = 1
            currSum %= 10
        }
        copy[index] = currSum
    }

	if jinwei == 1{
		return append([]int{1},copy...)
	}

	return copy
}
```


