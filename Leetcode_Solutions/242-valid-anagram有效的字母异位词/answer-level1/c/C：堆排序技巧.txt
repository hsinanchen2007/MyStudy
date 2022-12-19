### 解题思路
最先想到的也是排序，那就具体讲排序吧。思路由排序到hash。

### 1.python排序与C排序
起初用python，直接两行，直接通过了，且时间还可观。然后用C写冒泡,有点扣脚，超时警告？对，然后直接gua掉。因此我就好奇，python内置排序如此牛逼！(原谅我的无知，冒泡O($n^2$)显然不是timsort对手)。
```python []
class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)
```
```c []
void buble_sort(char *p, int len){  // 不用flag了
	for(int i=0;i<len-1;i++){
		for(int j=0;j<len-i-1;j++){
			if(p[j]>p[j+1]){
				char temp = p[j+1];
				p[j+1] = p[j];
				p[j] = temp;
			}
		}
	}
}

bool isAnagram(char * s, char * t){
	int len_s=strlen(s), len_t=strlen(t);
	if(len_s!=len_t) return false;
	buble_sort(s, len_s);
	buble_sort(t, len_t);
	for(int i=0;i<len_s;i++){
		if(s[i]!=t[i]) return false;
	}
	return true;
}
```
然后换快排，这个排序算法够快，不信这样不能通过测试？
```c []
int paratition(char *s, int low, int high){
    int i = low, j;
    char pivot = s[low], tmp;
    for(j = low + 1; j <= high; j++){
        if(s[j] <= pivot){
            tmp = s[j];
            s[j] = s[++i];  // 先+1
            s[i] = tmp;
        }
    }
    s[low] = s[i];
    s[i] = pivot;
    return i;
}

void qusort(char *s, int low, int high){
    if(low < high){
        int pi = paratition(s, low, high);
        qusort(s, low, pi - 1);
        qusort(s, pi + 1, high);
    }
}

bool isAnagram(char * s, char * t){
	int len_s=strlen(s), len_t=strlen(t);
	if(len_s!=len_t) return false;
	qusort(s, 0, len_s - 1);
	qusort(t, 0, len_t - 1);
	for(int i=0;i<len_s;i++){
		if(s[i]!=t[i]) return false;
	}
	return true;
}
```
果不其然，通过了，但是有点惨。令人感动。快速排序时间复杂度O(nlog(n))~O($n^2$)，所以原地爆炸。
920ms,6.18%
7.2MB,42.24%

### 2.边排序边比较
这个时候我就猜测，是不是sorted(s) == sorted(t)有什么特别策略？通过上面的冒泡，我想到了，其实没必要全部排序完然后再逐个比较，因此每次比较每轮最大值是否相等即可。(本题特殊性，两个字符串长度相等才可能成立。)
因此可以将冒泡算法(只要能得每轮最大值的排序算法都适用本题)改下，改成同步排序，然后比较每轮最值。
```c冒泡 []
bool isAnagram(char * s, char * t){
	int len_s=strlen(s), len_t=strlen(t);
	if(len_s!=len_t) return false;
	int i, j;
	char temp;
	for(i=0;i<len_s-1;i++){
		for(j=0;j<len_s-i-1;j++){
			if(s[j]>s[j+1]){
				temp = s[j+1];
				s[j+1] = s[j];
				s[j] = temp;
			}
			if(t[j]>t[j+1]){
				temp = t[j+1];
				t[j+1] = t[j];
				t[j] = temp;
			}
		}
		if(s[j]!=t[j]) return false;  // 注意循环后j++了
	}
	return s[0]==t[0];  // 防止'a','b'
}
```
```c堆排序  []
void swap(char *str, int i, int j) {
	char tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

void heapify(char *str, int len, int i) {
	/* 
	* len表示长度
	* i表示当前结点用于交换
	* c1:左子节点
	* c2:右子节点
	* 递归结束就是i >= len
	*/
	if (i >= len) return;
	int max = i;  // 用max记录i位置
	int c1 = 2 * i + 1, c2 = 2 * i + 2;
	max = c1 < len && str[c1] > str[max] ? c1 : max;
	max = c2 < len && str[c2] > str[max] ? c2 : max;
	if (max != i) { /* 递归找下去 */
		swap(str, max, i);
		heapify(str, len, max);  // 最大顶位置
	}
}

bool heapsort(char *s, char *t, int len) {
	int i = (len - 1) >> 1;  // parent结点
	for (; i >= 0; i--) {  // 建立两个堆
		heapify(s, len, i);
		heapify(t, len, i);
	}
	for (i = len - 1; i >= 0; i--) {
		if (s[0] != t[0]) return false;
		swap(s, i, 0);
		heapify(s, i, 0);
		swap(t, i, 0);
		heapify(t, i, 0);
	}
	return true;
}

bool isAnagram(char * s, char * t){
	int len_s=strlen(s), len_t=strlen(t);
	if(len_s!=len_t) return false;
	return heapsort(s, t, len_s);  // 任意长度;
}
```
都知道冒泡时间复杂度是O($n^2$),最后依然超时，那么就换一个时间复杂度低的同时还可以得到每轮最值得排序算法，就选堆排序。
![image.png](https://pic.leetcode-cn.com/ef1454d5654431e318d8dca636fa3c0cec260b32888df2004bfa52fb0f2f7474-image.png)
堆排序通过，但是另一个排序算法浮现眼前，这不正好固定范围，26字母，桶排序可以了解下。

### 3.桶排序->桶计数
虽然后面知道桶排序有点多余，但是思想还是从排序转过去的，逐步优化到空间复杂度为O(1)。

```c桶排序 []
char *bucketsort(char *s){
	int i, j, bucket[26] = {0};  // initiative
	for(i = 0; s[i] != '\0'; i++){
		j = s[i] - 97;  // 小写
		bucket[j]++;  // 桶中出现次数值++
	}
	char *res = (char *)malloc((i + 1) * sizeof(char));
    res[i--] = '\0';
	j = i;  // i就是长度真实索引:len-1
	for(i = 0; i < 26 && j >= 0; i++){
		while(bucket[i] > 0){
			res[j--] = i + 97;  // 还原成数字
			bucket[i]--;  // 次数减少
		}
	}
	return res;
}

bool isAnagram(char * s, char * t){
	int len_s=strlen(s), len_t=strlen(t);
	if(len_s!=len_t) return false;
	s = bucketsort(s);
	t = bucketsort(t);
	for(--len_s;len_s >= 0;len_s--){
		if(s[len_s]!=t[len_s]) return false;
	}
	return true;
}
```
```c []
bool isAnagram(char * s, char * t){
	int len_s=strlen(s), len_t=strlen(t);
	if(len_s!=len_t) return false;
	int counter[26]={0},i=0;
	for(;i<len_s;i++){
		counter[*(s+i)-97]++;  // 增加s出现次数
		counter[*(t+i)-97]--;  // 相应减少
	}
	for(i=0;i<26;i++) if(counter[i]) return false;
	return true;
}
```

### 总结

最后了解下，python的排序方式是[timsort](https://www.infopulse.com/blog/timsort-sorting-algorithm/)，排序中的战斗机。当然在其他语言也实现了。
菜狗看不懂。总之，本题特殊，可边排序边比较，虽然不是最优，想法还是可以有的。✊
|排序|最好|最坏|平均|空间|稳定|
|:-:|:-:|:-:|:-:|:-:|:-:|
|timsort|O(n)|O(nlog(n))|O(nlog(n))|O(n)|稳定|
|快排|O(nlog(n))|O($n^2$)|O(log(n))|O(log(n))|不稳|
|堆排序|O(nlog(n))|O(nlog(n))|O(nlog(n))|O(1)|不稳|
其他Google....
