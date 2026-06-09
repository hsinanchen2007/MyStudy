### 解题思路
![image.png](https://pic.leetcode-cn.com/d79fe91cc9ac3d2e87b00ef80389fb2e72de4f76a356c32639f9a2822ca426f6-image.png)

1.动态规划
设NUM_k为移除k位后最小数字，NUM_(k-1)为移除（k-1）位后最小数字，则有：
        NUM_k = NUM(k-1) 移除1位数字
此即为DP的状态转移方程。接下来，就到第二步，如何在NUM（k-1）中确定移除哪一位能使得剩余数字最小。
2.移除1位剩余数字最小算法
（1）左边为高位，高位数字的移除能带来整体数量的大面减少，优先从左侧开始考虑数字移除。例如“1432219”，优先从1、4、3...开始考虑移除。
（2）经观察可以发现，是否移除最左侧一位的数字，取决于次左侧的数字是否比最左侧的大，加入最左侧数字大于次左侧，那么移除最左侧数字所带来的减小量最大，即剩余数最小：
        if（num[k] > num[k+1]) 找到本次最小数移除位。
         
（3）如果是词左侧数字大于最左侧数字，那么依次继续往右寻找，直到找到左侧数大于次左侧数为止。
        if(num[k] < num[k+1]) 继续往下比较num[k+1] vs num[k=2]......直到num[k+i] > num[k+i+1]为止，此时第k+i位即为本次最小数移除位。
3.以上是主算法，对于所有位置都移除、高位有零等特殊情况，单独处理。

原来尝试将字符串转换为数字来比较，数量量小时倒是可以，数量大了之后，超过long long int大小就没法操作了。

总的来说，这个题思路比较有意思。mark一下。

### 代码

```c
char * removeKdigits(char * num, int k){
    int len = 0;
	int i = 0;
	int j = 0;
	char *x = NULL;

	len = (int)strlen(num);

	if(len == k) {
	    num[0] = '0';
		num[1] = '\0';
		return num;
	}

	for(i = 0; i < k; i++)
	{
		for(j = 0; j < len; j ++)
	    if(num[j] > num[j + 1])
		{
			x = (char *)malloc((len - (j + 1)) * sizeof(char));
			memset(x, 0x00, (len - (j + 1)) * sizeof(char));
			memcpy(x, num + j + 1, (len - (j + 1)) * sizeof(char));
			memcpy(num + j, x, (len - (j + 1)) * sizeof(char));
			num[len -1] = '\0';
			len = len - 1;
			free(x);
			break;
		}
		else {
		    continue;
		}
	}

	for(i = 0; i < len; i++)
	{
		if(num[i] == '0') {
		    continue;
		}
		else {
            x = (char *)malloc((len - i) * sizeof(char));
			memset(x, 0x00, (len - i) * sizeof(char));
			memcpy(x, num + i, (len - i) * sizeof(char));
		    memcpy(num, x, len - i);
			free(x);
			memset(num + len -i, '\0', i);
			break;
		}
	}

	if(i == len) {
	    num[0] = '0';
		num[1] = '\0';	
	}

	return num;
}
```