# 杨辉三角
既然已经做到了这道题，你肯定对杨辉三角已经有一个基本的了解了。
从数学的角度上来说，杨辉三角的每一项都对应着(a + b)的n次方展开后每一项的系数。
由于这道题需要得出的是第N行的内容，那么第一反应想到通过通项公式来计算得出每一项填充到数组里就是很自然的事情了。
# 1、式算
第n行第k列的值，可以通过通项公式：(n-1)!/(k-1)!(n-k)!计算得到
代码如下：
```
// 主逻辑
let getRow = function(rowIndex) {
	rowIndex++;
	let resultArr = [];
	for (let i = 1; i < rowIndex + 1; i++) {
	    resultArr.push(factorial(rowIndex - 1) / (factorial(i - 1) * factorial(rowIndex - i)));
	}
	return resultArr;
};

// 求阶乘
function factorial(num) {
	if (num < 2) {
		return 1;
	} else {
		return num * factorial(num - 1);
	}
}
```

完成了式算后，我发现最后的结果却并不是很好——64.14%
（这里还有很多可以优化的空间，甚至大神可以0ms，但是更多是针对数学角度的考虑，就不展开聊了）

# 2、图算（动态规划）
式算的结果让我有点失望，那么再试试图算。
图算其实就是《118、杨辉三角I》那道题里的做法，通过上一行推导下一行。
直接修改一下上一题的代码，每次覆盖上一行的内容就好
```
let getRow = function(rowIndex) {
	if (rowIndex === 0) {
		return [1];
	}
	if (rowIndex === 1) {
		return [1,1];
	}
	let resultArr = [1,1];
	for (let i = 2; i < rowIndex + 1; i++) {
		let tempArr = [];
		for (let j = 0; j <= i; j++) {
			tempArr.push((j === 0 ? 0 : resultArr[j - 1]) + (j === i ? 0 : resultArr[j]))
		}
		resultArr = tempArr;
	}
	return resultArr;
};
```
91.37%，但是显然有可以明显优化的空间
这里有一个可以取巧的思路：
**给上一行的第一位插个0**

[1, 1] => [0, 1, 1]

然后在遍历的过程中，把相邻两项相加得到当前项
代码如下：
```
let getRow = function(rowIndex) {
	let resultArr = [1];
	for (let i = 0; i < rowIndex; i++) {
		resultArr.unshift(0);
		for (let j = 0; j < i + 1; j++) {
			resultArr[j] = resultArr[j] + resultArr[j + 1];
		}
	}
	return resultArr;
};
```
值得说明的是[j + 1]由于i被插入了第一个0，所以是一定不会发生数组越界的
代码干净了不少，但是时间仍然是91.37%

# 3、通用优化逻辑
还有没有办法提升时间？
**当然有**

不管是式算还是图算，整个过程中伴随着大量的计算，仔细观察，我们可以发现杨辉三角是左右对称的。
所以可以在**过半**以后，把关于中轴对称的内容直接复制过来
代码如下：
```
let getRow = function(rowIndex) {
	let resultArr = [1];
	for (let i = 0; i < rowIndex; i++) {
		resultArr.unshift(0);
		const midIndex = Math.floor((i + 1) / 2);
		for (let j = 0; j < i + 1; j++) {
			if (j > midIndex) {
				resultArr[j] = resultArr[midIndex + ((i + 1) % 2) - (j - midIndex)];
				continue;
			}
			resultArr[j] = resultArr[j] + resultArr[j + 1];
		}
	}
	return resultArr;
};
```
```
97.2%达成ヽ(￣▽￣)ﾉ


