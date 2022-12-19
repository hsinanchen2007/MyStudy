### 解题思路

1. 确认当前位置的另外一位
2. 找到情侣另外一个人，交换次数+1
3. 复杂度 O(n^2)，数据量大的话可以使用hash来存储情侣号码和座位号 复杂度降为O(n)

### 代码

```swift
class Solution {
    func minSwapsCouples(_ row: [Int]) -> Int {
        var rowMut = row
	
	if row.count < 4  || row.count > 60	{
		return -1
	}
	let mid = row.count/2
	var exCount = 0;
	for i in 0..<mid{
		let l = rowMut[i*2];
		let r = rowMut[i*2+1]
		var l_wife = 0
		if l%2 == 0 {
			l_wife = l + 1
		}else{
			l_wife = l - 1
		}
		if l_wife == r {
			continue
		}
		exCount += 1;
		
		var index_wife = -1
		for j in 0..<rowMut.count{
			if rowMut[j] == l_wife {
				index_wife = j
				break
			}
		}
		if index_wife != -1 {
			let swap = rowMut[i*2+1]
			rowMut[i*2+1] = rowMut[index_wife]
			rowMut[index_wife] = swap
		}
	}
	return exCount;
    }
}
```
<br>
![sf (1).png](https://pic.leetcode-cn.com/9cdd986d3a7b712c6267600049a70e81c5eca53ddffaf4318e8621d560dd3081-sf%20\(1\).png)
# [更多题解见github 关注我 带你领略更多解法 欢迎start](https://github.com/ifgyong/SF#765-%E6%83%85%E4%BE%A3%E7%89%B5%E6%89%8B)
# [更多题解见github 关注我 带你领略更多解法 欢迎start](https://github.com/ifgyong/SF)
# [更多题解见github 关注我 带你领略更多解法 欢迎start](https://github.com/ifgyong/SF)