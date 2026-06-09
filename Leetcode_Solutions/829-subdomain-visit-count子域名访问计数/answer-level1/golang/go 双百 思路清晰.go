![屏幕快照 2020-04-03 下午8.45.24.png](https://pic.leetcode-cn.com/6fc810759898caf8b1cda36e6c25b1d481da34a6a0a5c9ccb33e181ece6972ff-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-03%20%E4%B8%8B%E5%8D%888.45.24.png)


#### 解题思路

思路如注释所示



#### 参考代码

```go
func subdomainVisits(cpdomains []string) []string {
	mp := make(map[string]int)
	for _,value := range cpdomains {
		num,domin := spilt(value)

		//遍历域名放入哈希表，如果存在则在原来的基础上加上新访问数，如果不存在则创建并赋初始值为当前访问数
		for _,k := range getdomin(domin){
			if value,ok := mp[k];ok{
				mp[k] = value + num
			}else {
				mp[k] = num
			}
		}
	}

	//遍历哈希表并结果返回
	var res []string
	for key,value := range mp {
		res = append(res, strconv.Itoa(value)+" "+key)
	}
	return res
}

//遍历字符串，遇到空格则将空格前转换为int类型，空格后直接截取返回
func spilt(str string) (num int,domin string){
	length:=len(str)
	for i:=0;i<length;i++ {
		if str[i] == ' ' {
			num,_ := strconv.Atoi(str[:i])
			return num,str[i+1:]
		}
	}
	return 0,"0"
}

//反向遍历域名字符串，遇到点分隔符或者到尽头则分割字符串加到数组里，最后返回
func getdomin(name string) []string {
	var res []string
	for i:=len(name)-1;i>=0;i-- {
		if name[i] == '.'{
			res = append(res,name[i+1:])
		}else if i == 0 {
			res = append(res,name)
		}
	}
	return res
}

```

**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**


