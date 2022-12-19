![屏幕快照 2020-04-02 上午11.06.04.png](https://pic.leetcode-cn.com/a10ebdf2a532610e44989db1348601124b193e19658a56ef016968b2ddc90ab3-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-02%20%E4%B8%8A%E5%8D%8811.06.04.png)

```
func findRestaurant(list1 []string, list2 []string) []string {
	mp := make(map[string]int)
	var min = int(^uint(0) >> 1)
	var res []string

	//遍历将list1的元素存入映射中
	for i,v := range list1 {
		mp[v]=i
	}

	//遍历list2
	for i,v := range list2 {

		//将映射的值和list2的索引相加再和最小值比较
		if value,ok := mp[v];ok {

			//如果比min小则清空res列表，将当前更小的加进去
			if value+i<min {
				min = value+i
				res = res[0:0]
				res = append(res,v)

			//如果相等的话则在原来的基础上继续添加
			}else if value+i==min {
				res = append(res,v)
			}
		}
	}

	return res
}

```
