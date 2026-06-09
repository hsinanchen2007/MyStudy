我的文字表达能力不太好。。。请包涵。。。   
根据题意可以把字符串划分为两块，前半部分为0，后半部分为1，主要是找区分这两部分的界限。
   用count_0和count_1分别记录遇到第一个1以后0和1的个数，在后续每一次遇到1时对它们进行比较，如果count_0>=count_1说明到目前这个1之前都是属于0的那一部分（如果是属于1的话我们将反转count_0次，显然count_0是大于count_1的，所以我们将1之前的数视作0的部分），就将答案加上count_1,再将count_0置为0（此时这个1前面的数都变为了0），count_1置为1.如果count_0一直小于count_1，则说明后面是属于1的那一部分，将答案加上count_0.


举个例子：
000010010110111
我们现在遍历这一串数字，当遇到第一个1之后，就开始记录遇到0与1的个数

**00001001**0110111      当我们遍历到第二个1时，此时count_0=2,count_1=1,count_1<count_0,所以这个1前面的数（100）属于0的那一部分，ans=count_1(有多少个1需要反转)，这个时候将count_0置为0，count_1置为1（因为此时遇到的1并未反转，而是作为一个起始界线）

**0000000101**10111      当遇到第三个时，此时count_0=1,count_1=1,count_1=count_0，如果后面都是1这个时候反转0或者1操作数都相等，但我们不确定后面是什么情况所以我们将这部分数（10）属于0的部分。ans+=count_1，这个时候将count_0置为0，count_1置为1

**00000000011**0111      当遇到第四个1时，此时count_0=0,count_1=1,count_1>count_0,继续遍历

**0000000001101**11      当遇到第五个1时，此时count_0=1,count_1=2,count_1>count_0,继续遍历

**00000000011011**1      当遇到第六个1时，此时count_0=1,count_1=3,count_1>count_0,继续遍历

**000000000110111**      当遇到第七个1时，此时count_0=1,count_1=4,count_1>count_0,结束遍历

后面属于1的部分需要反转count_0个数，所以ans+=count_0。


```
class Solution {
public:
	int minFlipsMonoIncr(string S) {
		if (S.size() <= 1) return 0;
		int count_0 = 0, count_1 = 0, ans = 0;
		int i = 0;
		while (S[i] == '0') i++;
		while (S[i] == '1') count_1++, i++;

		for (; i < S.size(); i++) {

			if (S[i] == '1') {
				if (count_0 >= count_1) ans += count_1, count_0 = 0, count_1 = 1;
				else count_1++;				
			}
			else {
				count_0++;
			}
		}
		if (count_0 > 0) ans += count_0>count_1?count_1:count_0;

		return ans;
	}
};
```
