- 欢迎大家留言讨论
- 本题可以由第n-1天的情况推出第n天的情况
- 先直接列出第一天的情况
- P = 1; // 不含A以P结尾的数量
- L = 1; // 不含A以L结尾不以LL结尾的数量 
- LL = 0;// 不含A以LL结尾的数量 LL天数至少是2
- A = 1; // 含有A并且以A结尾的数量
- AP = 0; // 含有A并且以P结尾的数量 AP天数至少是2
- AL = 0; // 含有A并且以L结尾不以LL结尾的数量 AL天数至少是2
- ALL = 0;// 含有A并且以LL结尾的数量 ALL天数至少是3
- 每种情况的状态转移方程 day代表天数
- dp[day].P = dp[day-1].P + dp[day-1].L + dp[day-1].LL
- dp[day].L = dp[day-1].P
- dp[day].LL = dp[day-1].L
- dp[day].A = dp[day-1].P + dp[day-1].L + dp[day-1].LL
- 因为A只能含有一个 所以A必须是从无到有的 

- dp[day].AP = dp[day-1].A + dp[day-1].AP + dp[day-1].AL + dp[day-1].ALL
- dp[day].AL = dp[day-1].A + dp[day-1].AP
- dp[day].ALL = dp[day-1].AL
```
var checkRecord = function (n) {
  let P = 1; // 不含A以P结尾的数量
  let L = 1; // 不含A以L结尾不以LL结尾的数量 
  let LL = 0;// 不含A以LL结尾的数量 
  let A = 1; // 含有A并且以A结尾的数量 
  let AP = 0; // 含有A并且以P结尾的数量 
  let AL = 0; // 含有A并且以L结尾不以LL结尾的数量 
  let ALL = 0;// 含有A并且以LL结尾的数量 
  for (let i = 1; i < n; ++i) {
    [P, L, LL, A, AP, AL, ALL] = [
      (P + L + LL) % 1000000007,
      P,
      L,
      (P + L + LL) % 1000000007,
      (A + AP + AL + ALL) % 1000000007,
      (A + AP) % 1000000007,
      AL
    ]
  }
  return (P + L + LL + A + AP + AL + ALL) % 1000000007
};
```
