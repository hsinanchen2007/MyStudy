### 解题思路
去重集合没必要2000，因为长度最大1000(甚至强迫症自己去试最小多少)，都小，可直接申请，不会爆炸，后来发现hash申请为char也可以通过。
`hash[i] > 0 && set[hash[i]] > 0`:意思是hash表中出现次数大于0且set集合中出现次数也大于0，证明字数出现次数重复，立马返回false，否者就给set[出现次数]赋值1。
即使if条件不满足，要么是hash[i]<=0,要么set[出现次数]<=0，两种情况都可向set[hash[i]]赋值1，0一直被重复赋值也没有影响

### 代码

```c
bool uniqueOccurrences(int* arr, int arrSize){
	char hash[2000] = {0}, set[1000] = {0};
	for (short i = 0; i < arrSize; i++) hash[arr[i]+1000]++;
	for (short i = 0; i < 2000; i++) {
		if (hash[i] > 0 && set[hash[i]] > 0) return false;
		else set[hash[i]] = 1;
	}
	return true;
}
```