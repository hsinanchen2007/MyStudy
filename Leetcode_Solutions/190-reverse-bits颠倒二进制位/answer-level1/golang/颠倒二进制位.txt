### 解题思路
从左到右取位并累加。

### 代码

```go []
func reverseBits(num uint32) uint32 {
	//	逐个位取值并用于构造结果
	var result uint32 = 0
	var i uint32 = 0
	for i = 0; i < 32; i++ {
		var bit uint32 = 0
		if num&(1<<(31-i)) != 0 {
			bit = 1
		}
		result += bit << i
	}
	return result
}
```
```java []
public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int num) {
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int bit = 0;
            if ((num & (1 << 31 - i)) != 0) {
                bit = 1;
            }
            result += (bit << i);
        }
        return result;
    }
}
```