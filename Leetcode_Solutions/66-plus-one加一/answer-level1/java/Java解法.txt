显然需要考虑的是进位的情况，再细究的话，还有可能出现位数变化的情况，不过，如果位数发生了变化，这种情况更简单，因为只有所有数字全为9的情况，才会出现位数变化，其余情况就考虑是否进位即可，倒序遍历这个数组，满十则将该索引对应的位置置位0后计算前一个数字即可，代码如下：
```
class Solution {
    public int[] plusOne(int[] digits) {
        int index = digits.length;
		
		while(digits[--index] + 1 == 10) {
			if(index == 0) {
				// 数组需要扩容
				int[] res = new int[digits.length + 1];
				res[0] = 1;
				return res;
			}
			digits[index] = 0;
			
		}
		digits[index] = digits[index] + 1;
		return digits;
    }
}
```