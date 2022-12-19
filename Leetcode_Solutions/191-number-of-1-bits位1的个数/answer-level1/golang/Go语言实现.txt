```
func hammingWeight(num uint32) int {
    var count int//存储1的个数
    for num !=0{
        if num & 1 == 1{//让num与1进行按位与运算，取得num最低位判断是否位1
            count++
        }
        num >>= 1//num右移一位
    }
    return count   
}
```