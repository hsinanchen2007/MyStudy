### 解题思路
此处撰写解题思路
先算出总的一圈是不是正数，是正数代表可以跑完一圈 

如果可以跑完一圈，计算从第几个加油站开始计算一直到最后一个加油站是正数的
### 代码

```golang
func canCompleteCircuit(gas []int, cost []int) int {
      currentoil := 0 //车里面目前的油量
	totaloil := 0 //一圈的油量统计，是否为正数
	start := 0 //起始加油站的位置

	for i:=0;i<len(gas);i++ {
		totaloil += gas[i]  - cost[i]
		if currentoil >= 0 {
			currentoil = currentoil + gas[i]  //第i个加油站加油
			currentoil = currentoil - cost[i] //开往第i个加油站消耗掉的汽油
		} else  {
			start = i
			currentoil = gas[i] - cost[i]   //小于0则重新计数
		}
	}

	if totaloil >= 0 {
		return start
	} else {
		return -1
	}
}
```