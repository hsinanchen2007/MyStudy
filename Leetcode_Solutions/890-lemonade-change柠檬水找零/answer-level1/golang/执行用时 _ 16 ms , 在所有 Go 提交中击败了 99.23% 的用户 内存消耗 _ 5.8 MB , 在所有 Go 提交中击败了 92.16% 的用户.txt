最开始我以为可以把所有的钱收到一块儿，然后看能不能找开，后来发现就是收钱然后找钱，找不开就GG，那反而简单了，每进来一个顾客我们就把顾客给的钱找掉，如果能处理掉，就继续下一个顾客，不能就结束。
处理原则其实是贪心的思路：主要是20美元的处理上，如果我们有10美元，那就把10美元找出去，再附加5美元，没有的话，就找3个五美元回去。
代码如下：
```
func lemonadeChange(bills []int) bool {
	if len(bills)==0{
		return true
	}
	m5,m10:=0,0
	for i:=0;i<len(bills);i++ {
		if bills[i]==5 {
			m5++
		}else if bills[i]==10 {
			if m5>0 {
				m5--
				m10++
			}else{
				return false
			}
		}else {
			if m10>0&&m5>0 {
				m10--
				m5--
			}else if m5>=3 {
				m5=m5-3
			}else{
				return false
			}
		}
	}
	return true
}
```
