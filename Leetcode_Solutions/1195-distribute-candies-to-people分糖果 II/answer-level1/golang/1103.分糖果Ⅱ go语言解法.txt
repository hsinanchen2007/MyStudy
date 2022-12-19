### 解题思路

简单题，直接上代码

### 代码

```golang
func distributeCandies(candies int, num_people int) []int {
	res := make([]int,num_people)
	p := 0				//指向当前该发糖果的孩子
	num := 1			//当前孩子该发的糖果数
	for candies != 0 {
		if candies >= num {
			candies -= num
			res[p] += num
		}else {			//若最后剩余糖果不够发给下一个孩子，则全部给他，candies置为0，循环结束
			res[p] += candies
			candies = 0
		}
		num++			//每次发完，下次发的糖果数+1
		p++				//指向下一个孩子
		if p == num_people {	//最后一个孩子发完，接着从第一个孩子开始发
			p = 0
		}
	}
	return res
}
```