### 解题思路
![截屏2020-02-11下午11.09.54.png](https://pic.leetcode-cn.com/5f4dae6ff35866a9c40648d88b5e57d63b4ebccff33ccb407927121a5211d735-%E6%88%AA%E5%B1%8F2020-02-11%E4%B8%8B%E5%8D%8811.09.54.png)

对10以内的num进行简单的特殊处理，小于0的数字是一种特殊情况直接返回false
num大于10的条件下num对4取余如果最后余数不为0那么就不是4的幂

### 代码

```golang
func isPowerOfFour(num int) bool {
    if num < 0 {
        return false
    }
    for num > 10 {
        flag := num % 4
        num /= 4
        if flag != 0 {
            return false 
        }
    }
    if num == 1 || num == 4 {
        return true
    }
    return false
}
```