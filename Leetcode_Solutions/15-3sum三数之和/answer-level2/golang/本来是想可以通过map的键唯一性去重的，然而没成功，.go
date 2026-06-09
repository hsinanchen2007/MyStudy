### 解题思路
此处撰写解题思路

### 代码

```golang
//threeSum1错误的，会遗漏值
func threeSum1(nums []int) [][]int {
	numsLen := len(nums)		//获取到长度
	if numsLen < 3 {		//不符合基本条件直接返回
		return [][]int{}
	}
	var res [][]int		//这个是用来返回的
	var pot =make(map[int]string)	//创建一个map
	sort.Ints(nums)		// 对nums升序重排
	fmt.Println(nums)
	for a:=0; a<numsLen-2; a++ {
		if nums[a] > 0 {		// a+b+c 如果a>0 则无需在判断
			return res
		}
		//if a > 0 && nums[a] == nums[a-1] {	// 跳过重复项
		//	continue
		//}

		for j := a + 1; j < numsLen; j++ {
			for x,value:=range nums{
				if x!=a&&x!=j&&nums[a] + nums[j] + value==0{
					fmt.Println(nums[a],nums[j],nums[x])
					_,ok1:=pot[nums[a]]		//判断该值是否在map中存在了，去重
					_,ok2:=pot[nums[j]]
					_,ok3:=pot[nums[x]]
					if ok1&&ok2&&ok3 {		//存在就跳过
						continue
					}
					pot[nums[a]]=""		//利用map的键唯一性做判断
					pot[nums[j]]=""
					pot[nums[x]]=""
					//下面是把合理的值存放在切片里
					elementValue:=make([]int,0)
					elementValue=append(elementValue,nums[a])
					elementValue=append(elementValue,nums[j])
					elementValue=append(elementValue,value)
					res=append(res,elementValue)
				}
			}

		}

	}

	return res
}

//这是ctrl+v的
func threeSum(nums []int) [][]int {

	// 1. 特殊情况
	l := len(nums)
	if l < 3 {return [][]int{}}

	// 2. 一般情况下
	var res [][]int
	var sum int

	sort.Ints(nums)		// 对nums升序重排

	for a:=0; a<l-2; a++ {
		if nums[a] > 0 {
			return res
		} // a+b+c a>0 => a+b+c > 0
		if a > 0 && nums[a] == nums[a-1] {
			continue
		} // 跳过重复项，不跳过的话遍历只可能得到之前找到过的组合

		b, c := l-1, a+1 // a为左指针，b为右指针，c在左指针后一位到右指针前一位中间移动
		for c < b { // 圈定c的可能活动范围
			sum = nums[a] + nums[b] + nums[c]
			switch {
			case sum < 0: // sum<0，所以c必须右移才可能找到sum=0
				c++
				for c < b && nums[c] == nums[c-1] {
					c++
				} // 跳过重复项
			case sum > 0:
				b--
				for c < b && nums[b] == nums[b+1] {
					b--
				} // 跳过重复项
			default:
				// 找到目标
				res = append(res, []int{nums[a], nums[c], nums[b]})
				c++ // c右移
				b-- // b左移
				for c < b && nums[c] == nums[c-1] {
					c++
				}   // 跳过重复项
				for c < b && nums[b] == nums[b+1] {
					b--
				}   // 跳过重复项
			}
		}
	}
	return res
}
```