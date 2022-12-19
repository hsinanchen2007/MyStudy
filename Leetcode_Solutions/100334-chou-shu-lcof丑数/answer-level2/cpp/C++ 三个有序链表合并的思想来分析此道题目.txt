### 解题思路
![image.png](https://pic.leetcode-cn.com/84fcceeb52486835b781bea9f151bb3c980b1b6a8878a739df9b0a5b1559f511-image.png)
题目做了很久，看了很多解析都很迷惑，看到一位同学关于此题的评论，感觉很有道理，解释也很清晰，特此和大家分享，我只是个搬运工，大家多感谢原作者。
[sunrise。同学的评论](https://leetcode-cn.com/problems/chou-shu-lcof/comments/250364)
以下均节选自该同学的评论
>丑数的排列肯定是1,2,3,4,5,6,8,10.... 然后有一个特点是，任意一个丑数都是由小于它的某一个丑数*2，*3或者*5得到的，那么如何得到所有丑数呢？ 现在假设有3个数组，分别是： A：{1*2，2*2，3*2，4*2，5*2，6*2，8*2，10*2......}

>B：{1*3，2*3，3*3，4*3，5*3，6*3，8*3，10*3......}

>C：{1*5，2*5，3*5，4*5，5*5，6*5，8*5，10*5......}

>那么所有丑数的排列，必定就是上面ABC3个数组的合并结果然后去重得到的，那么这不就转换成了三个有序数组的无重复元素合并的问题了吗？而这三个数组就刚好是{1,2,3,4,>5,6,8,10....}乘以2,3,5得到的。

>合并有序数组的一个比较好的方法，就是每个数组都对应一个指针，然后比较这些指针所指的数中哪个最小，就将这个数放到结果数组中，然后该指针向后挪一位。
>此外，注意到ABC三个数组实际上就是ugly[]*2，ugly[]*3和ugly[]*5的结果，所以每次只需要比较A[i]=ugly[i]*2，B[j]=ugly[j]*3和C[k]=ugly[k]*5的大小即可。然后谁最小，就把对应的指针往后移动一个，为了去重，如果三个指针所指的元素都是最小的元素，那么这3个指针都要往后移动一个。

### 代码

```cpp
class Solution {
public:
	int nthUglyNumber(int n) {
		if (n <= 0) return 0;
		int count = 1;
		vector<int> saveUUglyNumbers(n);
		saveUUglyNumbers[0] = 1;//基础丑数为1
		int p2, p3, p5;//分别指向三个有序链表（现象）的首元素，A，B，C
		p2 = p3 = p5 = 0;
		//将丑数排序
		while (count < n)
		{
			saveUUglyNumbers[count] = min(min(saveUUglyNumbers[p2] * 2, saveUUglyNumbers[p3] * 3), saveUUglyNumbers[p5] * 5);
            //三个有序链表可能有相同元素，所以只要是最小的，都要移动指针
			if (saveUUglyNumbers[p2] * 2 == saveUUglyNumbers[count]) p2++;
			if (saveUUglyNumbers[p3] * 3 == saveUUglyNumbers[count]) p3++;
			if (saveUUglyNumbers[p5] * 5 == saveUUglyNumbers[count]) p5++;
			count++;
		}
		return saveUUglyNumbers[count-1];
	}
};
```