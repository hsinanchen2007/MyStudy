### 解题思路
正常算法呢就是初中的排列组合算法A(n, m),但是呢我们就是从10个数字里面计算所以就是 A(10, m).
然后呢我们位数大于等于10位后结果就是一样的,话句话说,根据输入参数的不同,结果只有0-10+ 共11种答案,所以可以说是一个常量查询,不需要计算

### 代码

```golang
func countNumbersWithUniqueDigits(n int) int {
    switch n{
        case 0:
        return 1
        case 1:
        return 10
        case 2:
        return 91
        case 3:
        return 739
        case 4:
        return 5275
        case 5:
        return 32491
        case 6:
        return 168571
        case 7:
        return 712891
        case 8:
        return 2345851
        case 9:
        return 5611771
        default:
        return 8877691
    }    
}
```