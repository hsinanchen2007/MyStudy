[杨添伦的解释](https://leetcode-cn.com/problems/maximum-equal-frequency/solution/conkao-lu-san-chong-qing-kuang-by-yang-tian-lun/)
算是补充一点点,也记下来防止以后忘记
先上代码
``` java
// 最大相等频率.java
class Solution {
	public int maxEqualFreq(int[] nums) {
		int len = nums.length;
		int []sub = new int[100001];
		int []pre = new int[100001];
		int res = 0;
		int cur = 0;
		for(int i=0;i<len;i++){
			pre[++sub[nums[i]]]++;
			cur = Math.max(sub[nums[i]],cur);
			if(pre[cur]==1 && pre[cur-1] * (cur-1)+1 == (i+1) || (pre[cur]*cur+1==i+1)){
				res=i+1;
			}
		}
		if(cur == 1) return nums.length;
		return res;
	}
}
```
----
****
我们维护两个数组:分别为
sub为每个数字出现的次数 即sub[i] = j ====>数字i出现了j次
pre是频率出现的次数 类似的 pre[i] = j ====>频率为i的出现了j次 
cur为当前出现频率最高的数字
首先,**要想**生成一个  去掉一个数字就可以构成**相等频率的前缀数组**,那么就只有四种情况
1. [1,1,1,2,2,3,3,4,4]类似这样,我们归类为[a,a,a,b,b,c,c]...这类数组的关键是:**出现频率最高的 -1 == 出现频率次高的** ,这里假设A为最高的,B为次高的,即A-1=B 且该数组长度为: (重点)**B的频率*B出现的次数+1**
类似[1,1,1,2,2,3,3,4,4]就是  2(频率为2) * 4(频率为2或以上的出现4次) + 1 = 9
又例如[1,1,1,2,2] 那就是 2 * 2 + 1 = 5
简记为:
```java
    pre[cur]==1&&pre[cur-1] * (cur-1)+1 == (i+1) //频率最高的出现一次 && 公式
```
2. [1,1,1,1,1,1,2] 类似这样的,只有一个单独出现,这样的和上一次个类似,可以推出 
 ```java
	pre[cur]*cur+1==i+1// 加上一位单独出现的数字
```
3. [1,2,3,4,5,6] 形如这种 数字出现的频率均不同 那么就是
   ```java
	 cur = 1 //cur刚刚说是最高的频率,如果最高的就是1,那么就代表整个数组都是不重复的
	```
4.[1,1,1,1,1,1] 想必这种看到这里也该会推理出来
```java
1. pre[cur]*cur+1==i+1 
2. cur = nums.length 
```

至此 四个条件分析结束,如果第i位的数字满足任意一个条件, 那么前缀数组的长度就是i+1
即 `res = i + 1`
最后`reture res` 即可
