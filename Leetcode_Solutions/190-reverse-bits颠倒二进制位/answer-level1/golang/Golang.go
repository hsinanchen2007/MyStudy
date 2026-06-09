### 解题思路

* runtime: 0ms
* ram: 2.5MB

[花花酱的视频讲解](https://www.youtube.com/watch?v=K0EHvvbUdEg&list=PLLuMmzMTgVK7t8spH-USywHZLtt2aM5Ue&index=1)


反转位操作在汇编语言学习里面是一个常见的题目。

使用位操作符来做这道题。


一个变量 `ans` 储存结果，Golang自动把 `ans` 初始化为`0`, 也就是 `0b0`。

我们对`num`和`ans`就行如下位操作：
* 从`num`取出最后一位bit， 使用 `&1`
* 将`num`除以二 （右移）, 使用 `>> 1`
* 将取得的bit放在`ans`最后一位, 使用 `|`
* 将`ans`乘以二 (左移)， 使用 `<<1`

    `01001 & 00001` 得到 `00001`
    `00001 << 1`    得到 `00010`
    `00010 | 10001` 得到 `10011`

#### 例子 

    以长度为5的bit为例

|i|num|ans|
|-|-|-|
|-|11010|00000|
|0|1101|00000|
|1|110|00001|
|2|11|00010|
|3|1|00101|
|4||01011|


### 代码

```golang
func reverseBits(num uint32) uint32 {
	var res uint32
	for i := 0; i < 32; i++ {
		// num & 1 ：get the last bit form num.
		// eg: 00101 & 1
		res = (res << 1) | (num & 1)
		num = num >> 1
	}
	return res
}

```