```
func canWinNim(n int) bool {
	switch n {
	case 0:
		return false
	case 1:
		return true
	case 2:
		return true
	case 3:
		return true
	default:
		dp := make([]bool, 4)
		dp[0] = false
		dp[1] = true
		dp[2] = true
		dp[3] = true
		// for i := 4; i <= n; i++ {
		// 	dp[i % 4] = !dp[(i - 1) % 4] || !dp[(i - 2) % 4 ] || !dp[(i - 3) % 4]
		// }
		return dp[n % 4]
	}
}
```
1. 使用i % 4 解决内存问题。
2. 去掉循环，解决超时问题
- dp[0] 始终都是false
- dp[1] 始终都是true
- dp[2] 始终都是true
- dp[3] 始终都是true
 
执行结果：
runtime: out of memory: cannot allocate 1348820992-byte block (66879488 in use)
fatal error: out of memory
runtime stack:
runtime.throw(0x4f7ebd, 0xd)
panic.go, line 774
runtime.largeAlloc(0x50655e85, 0x4d0101, 0x7fd97f900190)
malloc.go, line 1140
runtime.mallocgc.func1()
malloc.go, line 1033
runtime.systemstack(0x452cb4)
	/usr/local/go/src/runtime/asm_amd64.s:370 +0x66
runtime.mstart()
proc.go, line 1146
runtime.systemstack_switch()
	/usr/local/go/src/runtime/asm_amd64.s:330 fp=0xc000060c50 sp=0xc000060c48 pc=0x452db0
runtime.mallocgc(0x50655e85, 0x4cd0e0, 0xc000022501, 0xa)
malloc.go, line 1032
runtime.makeslice(0x4cd0e0, 0x50655e85, 0x50655e85, 0xc0000225d0)
slice.go, line 49
main.canWinNim(0x50655e84, 0xc0000225c0)
solution.go, line 12
main.__helper__(...)
solution.go, line 27
main.main()
solution.go, line 55
runtime.main()
proc.go, line 203
runtime.goexit()
	/usr/local/go/src/runtime/asm_amd64.s:1357 +0x1 fp=0xc000060fe8 sp=0xc000060fe0 pc=0x454d01
最后执行的输入：
1348820612