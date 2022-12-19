需要用到 [反转字符串-1](https://leetcode-cn.com/problems/reverse-string/submissions/)的内容.

说是啰嗦是因为感觉不用 if..else 嵌套也是可以的, 也不用强转成 Array , 但对语法不太熟悉, 思路正确就好了. 😁

主要的方法在于"反转区间"的判断,
条件有:
1. (长度 < k) => 全部反转
2. (k < 长度 < 2*k) => 反转前 k 个
3. (长度 > 2*k) => 反转前 k 个, 剩余的重复进行 1~3 的条件判断.

贴个解决代码, 区分了字符串长度少于 k 或 2*k 的场景:(132 ms, 21.2 MB)

	func reverseStr(_ s: String, _ k: Int) -> String {
	
		let dk = k * 2
		
		var arr:[Character] = Array(s)
		
		if arr.count>=k && arr.count<dk {
			reverse(&arr, 0, k-1)
		}else if arr.count<k {
			reverse(&arr, 0, s.count-1)
		}else {
			for i in stride(from: 0, to: s.count, by: dk) {
				if (i+dk) < s.count || (i+k) < s.count {
					reverse(&arr, i, i+k-1)
				}else {
					reverse(&arr, i, s.count-1)
				}
			}
		}
	
		return String(arr)
	}

	func reverse(_ s: inout [Character], _ l:Int, _ r:Int)
	{
		var left = l
		var right = r
		
		while left < right {
			let temp = s[left]
			s[left] = s[right]
			s[right] = temp
				
			left = left + 1
			right = right - 1
		}
	}
` 

 
