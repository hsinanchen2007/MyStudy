
哈希表键为整数，值为罗马数字，**且键从大到小排列**；

```
hashmap = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 100: 'C', 90: 'XC', 50: 'L', 40: 'XL', 10: 'X', 9: 'IX', 5: 'V', 4: 'IV', 1: 'I'}
```


遍历整个哈希表，**判断当前数值是否大于等于此刻的键**：若能，则s加上整除的个数乘以值；若不能，则遍历下一个。


```python
class Solution:
    def intToRoman(self, num: int) -> str:
    	hashmap = {1000: 'M', 900: 'CM', 500: 'D', 400: 'CD', 
    	100: 'C', 90: 'XC', 50: 'L', 40: 'XL', 10: 'X', 
    	9: 'IX', 5: 'V', 4: 'IV', 1: 'I'}
    	s = ""
    	for k in hashmap:
			count = num // k
			num %= k
			s += hashmap[k] * count
    	return s
```
