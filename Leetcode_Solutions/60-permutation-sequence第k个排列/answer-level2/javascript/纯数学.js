```javascript []
var getPermutation = function(n, k) {
    var text = '', list = [];
	for (var i = 1; i <= n; i++) list.push(i);
	var length = n, ni = 1, t;
	while (text.length < length) {
		ni = 1;
		t = n;
		while (t > 1) { t--; ni *= t; }
		var num = (k - 1 - (k - 1) % ni) / ni + 1;
		k -= (num - 1) * ni;
		text += list[num - 1];
		list.splice(num - 1, 1);
		n--;
	}
	return text;
};
```
```java []
public String getPermutation(int n, int k) {
	String text = "";
	List<Integer> list = new ArrayList<>();
	for (int i = 1; i <= n; i++) list.add(i);
	int length = n, ni = 1, t;
	while (text.length() < length) {
		ni = 1;
		t = n;
		while (t > 1) { t--; ni *= t; }
		int num = (k - 1) / ni + 1;
		k -= (num - 1) * ni;
		text += list.get(num - 1);
		list.remove(num - 1);
		n--;
	}
	return text;
}
```
1、知道了n就知道了总排序数为n的阶乘，把第1位数从1至n平均分成n份，就可以算出第k个落在哪一份，即所求的第一位数是几；
2、移除1个数后，k也要减去k-1份之前的排序总和，然后n减去1，下一步计算的数按照索引从剩余未选的数中抽取，直至结束；

![1.png](https://pic.leetcode-cn.com/910a2e786ede237b1f0450cfb485537dc2d4c8354de3af6e1816529b5059e13f-1.png)
