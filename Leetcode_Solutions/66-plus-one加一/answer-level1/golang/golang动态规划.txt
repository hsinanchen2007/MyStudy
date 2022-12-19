![image.png](https://pic.leetcode-cn.com/40fa5a540b2da816315e56e6422d364574163932ed2b9c2ed44a463b04850ad8-image.png)

### 解题思路
digits[k]]=(digits[k]+jinwei[k+1])%10,jinwei[k]=(digits[k]+jinwei[k+1])/10
### 代码

```golang
func plusOne(digits []int) []int {
//应该可以用动态规划做，假设f(k)表示当前值，则
/*
  digits[k]]=(digits[k]+jinwei[k+1])%10,jinwei[k]=(digits[k]+jinwei[k+1])/10
 */
	
	jinwei:=make([]int,len(digits)+1)
	jinwei[len(jinwei)-1]=1
	//jinwei[len(jinwei)-1]=(digits[len(digits)-1]+1)/10
	for i:=len(digits)-1; i>=0;i-- {
		jinwei[i]=(digits[i]+jinwei[i+1])/10
		digits[i]=(digits[i]+jinwei[i+1])%10
	}
    //再判断最高位是否需要进位
    if jinwei[0]==1{
        return append([]int{1},make([]int,len(digits))...)
    }
	return digits
}

```