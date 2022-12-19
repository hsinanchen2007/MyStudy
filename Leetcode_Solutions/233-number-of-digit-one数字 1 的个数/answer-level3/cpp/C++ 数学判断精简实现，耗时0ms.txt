![image.png](https://pic.leetcode-cn.com/902cb93e583d89721130bfab0c6722bab5f0862c777ecb430cf85e203ff7fb2c-image.png)
耗时0ms, 内存6.2M
### 解题思路
从个位开始按位处理：
	首先当前位(如个位)假设为第bit_pos位,则该位1代表的大小为10^bit_pos,则所有数中该位1的个数为val*10^(bit_pos-1);
	另外记录已处理完的数为res, 如123456, 处理完百位, 则val = 123, res = 456;
	然后判断末位的大小：
		i. 若大于1, 则需加上10^bit_pos. 如123, 当val = 12时, 加上10(110-119十位上的1)
		ii.若等于1, 只需加上res + 1. 如54123, 当val = 541时, 需要加上24(54100-54123百位上的1)

### 代码

```cpp
class Solution {
public:
	int countDigitOne(int n) {
		int ans = 0;
		int val = n;
		int bit_pos = 0;
		int res = 0;
		while (val > 0){
            ans += val * pow(10, bit_pos - 1); //当前位1的个数
            if(val % 10 != 0) //末位不为0
                ans += val%10 > 1? pow(10, bit_pos) : res + 1;
			res = val % 10 * pow(10, bit_pos) + res;//余数
			val /= 10;
            bit_pos++;
		}
		return ans;
	}
};
```