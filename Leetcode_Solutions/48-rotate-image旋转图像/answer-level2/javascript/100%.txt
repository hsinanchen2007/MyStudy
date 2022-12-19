![1.png](https://pic.leetcode-cn.com/2e86b59c097ff64babae7619e582ff3a20986eb9155910fea273d4483bee5924-1.png)
![2.png](https://pic.leetcode-cn.com/016e5a3cc89569d7655c102d3c4977797cce5969e84b422cb0de8d45984f9340-2.png)

```javascript []
var rotate = function(nums) {
	//huan代表矩阵的环数
	for (var i = 0, huan = (nums.length + 1) >> 1; i < huan; i++) {
		for (var j = i, bian = nums.length - 1 - i; j < bian; j++) {
			//存储环的左上角数字
			var temp = nums[i][j];
			//左上角的数等于左下角的数
			nums[i][j] = nums[nums.length - j - 1][i];
			//左下角的数等于右下角的数
			nums[nums.length - j - 1][i] = nums[nums.length - i - 1][nums.length - j - 1];
			//右下角的数等于右上角的数
			nums[nums.length - i - 1][nums.length - j - 1] = nums[j][nums.length - i - 1];
			//右上角的数等于左上角的数
			nums[j][nums.length - i - 1] = temp; 
		}
	}
}
```
```java []
public void rotate(int[][] nums) {
	//huan代表矩阵的环数
	for (int i = 0, huan = (nums.length + 1) >> 1; i < huan; i++) {
		for (int j = i, bian = nums.length - 1 - i; j < bian; j++) {
			//存储环的左上角数字
			int temp = nums[i][j];
			//左上角的数等于左下角的数
			nums[i][j] = nums[nums.length - j - 1][i];
			//左下角的数等于右下角的数
			nums[nums.length - j - 1][i] = nums[nums.length - i - 1][nums.length - j - 1];
			//右下角的数等于右上角的数
			nums[nums.length - i - 1][nums.length - j - 1] = nums[j][nums.length - i - 1];
			//右上角的数等于左上角的数
			nums[j][nums.length - i - 1] = temp; 
		}
	}
}
```
