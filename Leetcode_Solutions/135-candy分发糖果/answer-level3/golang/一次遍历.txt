### 解题思路

使用一个数组存储每个位置最少分的糖果，其中有些位置糖果的数量对后续位置的数量有约束。
从左至右遍历ratings。

考虑以下几种情况：
1. ratings[i-1] = ratings[i]   相邻两者同分的话则相互直接没有任何约束，所以后者直接给1颗糖果即可；i位置对后续位置的糖果数有限制，而i-1及之前位置的糖果数已经可以固定下来；记录i位置为begin，在处理后续位置的时候，begin位置的糖果数如有必要可以自由地增加
2. ratings[i-1] < ratings[i]   根据要求i位置的糖果数要求比i-1位置多，所以后者给比i-1位置多一个糖果；同理i-1及之前位置糖果数可以固定下来；记录i位置为begin
3. ratings[i-1] > ratings[i]   根据要求i位置糖果数要比i-1位置少，所以给i位置一个糖果，再考虑调整begin到i-1位置的糖果数（代码中只需要处理begin位置的糖果数，因为其他位置糖果数不会成为对后续位置的限制）；处理的时候再分有必要增加begin位置糖果数和没必要（例如begin位置是10颗糖果，而i=begin+2,那么只需要增加begin+1位置）两种情况

### 代码

```golang
func candy(ratings []int) int {
	candies := make([]int, len(ratings))
	sum := 0
	begin := 0
	for i, rating := range ratings {
		if i == 0 {
			candies[i] = 1
			sum = sum + 1
			continue
		}

		if rating == ratings[i-1] {
			candies[i] = 1
			sum = sum + 1
			begin = i
		} else if rating < ratings[i-1] {
			if candies[i-1] > 1 {
				candies[i] = 1
				sum = sum + 1
			} else {
				candies[i] = 1
				if candies[begin] > i-begin {
					sum = sum + i - begin
				} else {
					candies[begin] = candies[begin] + 1
					sum = sum + i - begin + 1
				}
			}
		} else {
			candies[i] = candies[i-1] + 1
			sum = sum + candies[i]
			begin = i
		}
	}
	return sum
}

```