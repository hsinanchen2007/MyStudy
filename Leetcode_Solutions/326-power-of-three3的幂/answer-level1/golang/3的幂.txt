### 解题思路

方法一，
逆向操作，判断是不是3的幂，就看跟3的幂是否相等
比较n和3的幂的大小，若n < 1 (3**0) 则返回false，n ==1 返回true
 n > 3 ,进入下次循环，比较 n < 3 (3**1)，依次循环

方法二， 
利用3进制字符串，判断第一位为1，其他为0，符合条件则为3的幂
if  a < 1 {
	fmt.Println("false")
}
	aa := strconv.FormatInt(int64(a),3)
	fmt.Println(aa[0:1] =="1" && strings.Count(aa,"0") == len(aa)-1)
这个思路更简洁

### 代码

```golang
func isPowerOfThree(n int) bool {
    //设计思路，比较n和3的幂的大小，若n < 1 (3**0) 则返回false，n ==1 返回true
    // n > 3 ,进入下次循环，比较 n < 3 (3**1)   
    aa := 1 
    for {
        if n < aa {
            return false
        }
        if n == aa {
            return true
        }
        aa *= 3 
    }
     
}
```