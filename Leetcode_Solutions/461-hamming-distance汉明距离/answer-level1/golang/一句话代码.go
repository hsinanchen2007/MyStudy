![111.png](https://pic.leetcode-cn.com/f12a5c492e52e0d85c849dbd5ac682543e95baf46b64f312ee31a48b0dc62624-111.png)

**一句话代码 就是异或之后转2进制  统计1的数量**

func hammingDistance(x int, y int) int {
	return strings.Count(fmt.Sprintf("%b", x ^ y),"1")
}



**//看了官方说leetcode不能用内置函数 
//那就除2算求余来算1的个数吧**
func hammingDistance(x int, y int) int {
		res:=x ^ y
		counts :=0;
		for res>0{
			if(res%2==1){
				counts++
				res=(res-1)>>1;
			}else{
				res>>=1;
			}
		}
		return counts

}