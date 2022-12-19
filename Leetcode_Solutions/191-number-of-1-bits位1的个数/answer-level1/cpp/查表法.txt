比较流行的做法：
```
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int k=0;
		for(k=0; n; n=n&(n-1), ++k);
		return k;
	}
};
```
但是这个算法不太稳定，时间O(k)，k是1的个数。回归原始，每次右移1位，看看最后一位是不是1，可能移动32次。假如按4位分割，每次移动4位，对4位进行建表：
0x0(0000), 0x1(0001), 0x2(0010), ...查表法计算1的个数：
```
class Solution {
public:
	int hammingWeight(uint32_t n) {
		int k=0, bits[]={0,1,1,2,1,2,2,3,1,2,2,3,2,3,3,4};
		for(k=0; n; k+=bits[n&0xF], n>>=4);
		return k;
	}
};
```
上面算法最多移动8次。如果对空间不太要求，可以每8位做一个单位，最多移动4次，空间只需要256。

