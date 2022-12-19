### 解题思路
投机取巧：你会发现2的时候【0，1，3，2】那么两两之间的差距值是2的n-1次方。我们利用[0,1]进行递推。速度慢了点

### 代码

```javascript
/**
 * @param {number} n
 * @return {number[]}
 */
var grayCode = function(n) {
    if(n === 0) return [0];
		if(n === 1) return [0, 1];
		let res = [0, 1];//创建默认为1.
		// 有规律 2的时候差距是2  3的时候是[0,1,3,2,6,7,5,4]差距是4 ，4的时候差距是8
		let [low, high] = [0, 0];
		for(let i = 2; i <= n; i++){
            [low, high] = [0, Math.pow(2,i) - 1];
            while(low < high){
                res[high] = res[low] + Math.pow(2,i - 1);
                low++;
                high--;
            }
		}
		return res;
};
```