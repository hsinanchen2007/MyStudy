![屏幕快照 2020-02-13 下午3.53.12.png](https://pic.leetcode-cn.com/22832b4d595d34c2fffd65faf37465a9a2d1165c3db61f7de068aaf0cc3ce429-%E5%B1%8F%E5%B9%95%E5%BF%AB%E7%85%A7%202020-02-13%20%E4%B8%8B%E5%8D%883.53.12.png)
应该没有比这个更简单了吧
简单来说就是对比一下每个字符出现的次数做一下差值后, 把结果的绝对值加起来就行

由于改了一个位置目标值会加一, 原本的值会跟着减一, 所以结果要除以二
```
class Solution {
	func minSteps(_ s: String, _ t: String) -> Int {
		var cArr = Array(repeating: 0, count: 26)
		for c in s {
			cArr[Int(c.asciiValue!)-97] += 1
		}
		for c in t {
			cArr[Int(c.asciiValue!)-97] -= 1
		}
		var result = 0
		for c in cArr {
			result += abs(c)
		}
		return result/2
	}
}
```
