**思路**：假设当前是第n+1次投掷以及该次投掷的结果为1 那么到目前为止合规范的以1结尾的投掷的数量为前n次投掷总共的合规范的投掷的数量-新增的以1结尾的不合规范的投掷的数量 不合规范也就是连续出现的1的数量超过了rollMax[0]<-设为x 那么不合规范的投掷数量就是前n+1-x-1次投掷总共的合规范的投掷的数量(第n+1-x投掷必定为1)
**注意**：本人菜鸡 语死早表述得大概不是很清楚 以下代码仅供参考 还请大家多多指教
```python []
class Solution:
	def dieSimulator(self,n,rollMax):
		dp={0:[0]*6+[1],1:[1]*6+[6]} #0的key-value说实话没什么意义 为了统一处理才加上去的 value的前六个分别对应着当前以1,2,3,4,5,6结尾的投掷有多少个是合规范的
		for i in range(2,n+1): #接上 最后一个表示总共的合规范的投掷有多少个
			tmp=dp[i-1][6]
			dp[i]=[tmp-(dp[i-y-1][6]-dp[i-y-1][x] if i>=y+1 else 0) for x,y in enumerate(rollMax)] #if else表示的新增的不合规范的投掷的数量
			dp[i].append(sum(dp[i]))
		return dp[n][6]%(int(1e9+7))
```
```golang []
func dieSimulator(n int, rollMax []int) int {
	mod:=1000000007
	dp:=make([][]int,n+1) //从map换成二维slice时间和空间都好上不少/(ㄒoㄒ)/~~
	dp[0],dp[1]=[]int{0,0,0,0,0,0,1},[]int{1,1,1,1,1,1,6} //0的key-value说实话没什么意义 为了统一处理才加上去的 value的前六个分别对应着当前以1,2,3,4,5,6结尾的投掷有多少个是合规范的
	for i:=2;i<=n;i++ { //接上 最后一个表示总共的合规范的投掷有多少个
		tmp:=dp[i-1][6]
		n_dp:=make([]int,7)
		for x,y:=range rollMax {
			if t_idx:=i-y-1;t_idx>=0 {
				n_dp[x]=(tmp-(dp[t_idx][6]-dp[t_idx][x])+mod)%mod //新增的不合规范的投掷的数量 注意要保持mod
			} else {
				n_dp[x]=tmp
			}
		}
		n_dp[6]=(n_dp[0]+n_dp[1]+n_dp[2]+n_dp[3]+n_dp[4]+n_dp[5])%mod
		dp[i]=n_dp
	}
	return dp[n][6]
}
```

