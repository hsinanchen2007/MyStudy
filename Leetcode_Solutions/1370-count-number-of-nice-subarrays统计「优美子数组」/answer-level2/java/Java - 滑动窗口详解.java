### 1. 题目分析
- 第一步：普遍规律
    由于**只需要关注奇数的个数**，故：
	- 找到每种情况下，最短的符合要求子数组（此时子数组的左右边界一定都是奇数）
	- 向左向右延展，直至碰到奇数停止

	**[例子]**
		假设原始数组如下所示，要求$k=3$，很容易得出有以下两种最短的子数组$(a)$,$(b)$：	
		$(a)$如下所示。向左向右延展，可以延展到红线标定的位置。此时向左延展有$2$种可能(不延展，延展1位)，向右有$3$种可能，故总共有$2 \times 3=6$种可能；
		$(b)$如下所示。只能向右延展，可以延展到红线标定的位置。此时向左延展有$1$种可能(不延展)，向右有$2$种可能，故总共有$1 \times 2=2$种可能；
![image.png](https://pic.leetcode-cn.com/c07fdee6a57f189e1ccd7aa1487f2ff76f2f392bfdbece516d4cc9e29df6a0b4-image.png)
		综上所述，总共有$6+2=8$种子数组。
		<br>将奇数的下标用数组储存，其中**橘色部分为奇数出现的位置，蓝色部分标定数组的边界**。则：
		$(a)$如下所示，有$[1-(-1)]*(7-4)=6$种可能，即$(arr[1] - arr[0]) * (arr[4] - arr[3])$；
		$(b)$如下所示，有$(2-1)*(9-7)=2$种可能，即$(arr[2] - arr[1]) * (arr[5] - arr[4])$；
![image.png](https://pic.leetcode-cn.com/79dc19a1f3c570ce92717213e208cc134143f7b537d7f1995365459214bb44b5-image.png)

- 第二步：得出结论
	对于每种子情形，其可能数为：
	$$(arr[i] - arr[i - 1]) * (arr[i + k] - arr[i + k - 1])$$	
	其中，左边界为$-1$，右边界为$arr.length$。
### 2. Coding
```java
public int numberOfSubarrays(int[] nums, int k) {
    int len = nums.length, res = 0, feed = 0, arr[] = new int[len + 2];
    for(int i = 0; i < len; i ++) {
        // if it is odd
        if((nums[i] & 1) == 1) {
            arr[++feed] = i;
        }
    }
    // left border
    arr[0] = -1;
    // right border
    arr[feed + 1] = len;
    for(int i = 1; i + k < feed + 2; i ++) {
        res += (arr[i] - arr[i - 1]) * (arr[i + k] - arr[i + k - 1]);
    }
    return res;
}
```
时间复杂度：$O(n)$，空间复杂度：$O(n)$
<br>注：代码中判断是否为奇数的方法经常会用到，也可以将其抽取为一个方法进行调用：
```
private boolean isOdd(int t) {
    return (t & 1) == 1;
}
```
### 3. 执行结果
![image.png](https://pic.leetcode-cn.com/17f6594ddbe3f2b4ee6301a7e4cb59d38ffa7e1201a03e93c5b60f8a48d51cc5-image.png)

