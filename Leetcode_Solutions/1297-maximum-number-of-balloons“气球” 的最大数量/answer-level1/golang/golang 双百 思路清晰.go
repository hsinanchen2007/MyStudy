![屏幕快照 2020-04-06 下午7.53.50.png](https://pic.leetcode-cn.com/9aba885a32fda0252b5e09e23b0957fdb0f878b063f632e8256b20e3e7c36774-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-04-06%20%E4%B8%8B%E5%8D%887.53.50.png)

### 解题思路

将字母遍历存储到数组中统计字母数量，然后按balloon遍历数组，边遍历边递减字母的数量，遍历一次即代表可以拼成一个balloon，记录次数，当某个字母的数量小于0时，返回总数


### 参考代码

```
func maxNumberOfBalloons(text string) int {
	var list [26]int
	str := "balloon"

	for i:=0;i<len(text);i++ {
		list[text[i]-'a']++
	}

	res := 0
	for true {
		for i:=0;i<7;i++ {
			list[str[i]-'a']--
			if list[str[i]-'a'] < 0 {
				return res
			}
		}
		res++
	}
	return -1
}

func Min(x int ,y int) int {
	if x>y {
		return y
	}
	return x
}

```

**更多题解可以在我的[github](https://github.com/LZH139/leetcode_Go)上看到，每天都在持续更新，觉得还不错的话，记得点个小星星哈，谢谢啦**


