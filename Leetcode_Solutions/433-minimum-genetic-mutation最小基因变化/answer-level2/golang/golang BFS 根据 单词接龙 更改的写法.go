很多硬核写法  刚学golang没多久  望大佬指点
![截图_2019-12-07_15-16-17.png](https://pic.leetcode-cn.com/8f27d6080d53b76d5d8b9c9d04b17ed493dfc7ecde61ed8cbeca3fb0d0bdacda-%E6%88%AA%E5%9B%BE_2019-12-07_15-16-17.png)



```
func minMutation(start string, end string, bank []string) int {
	queue := []string{start}
	count := 0
	now := 0
	top := 1
	for len(queue) > 0 {
		count++
		//这里是队列---出队列操作  取值的操作
		for _, ss := range queue{
			//硬核 while循环
			for{
				if top<0 {
					break
				}
				for i := 0; i < len(bank) ; i++ {
					s := bank[i]
					if s == "" {
						continue
					}
					if !compare(ss, s) {
						continue
					} else if s == end {
						return count
					}
					bank[i] = ""
					//队列offer操作
					queue = append(queue,s)
					now++
				}
				top--
			}
			top = now
			now = 0
			//最后实现到  poll()
			queue = append(queue[:0],queue[1:]...)
		}
	}

	return -1
}

func compare (start string, s string) bool {
	count := 0
	for i := 0 ; i < len(start) ; i++ {
		if start[i:i + 1] != s[i:i+1] {
			count++
		}
	}
	return count == 1
}
```
