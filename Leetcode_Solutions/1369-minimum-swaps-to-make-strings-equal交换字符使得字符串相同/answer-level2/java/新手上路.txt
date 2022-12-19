![图片.png](https://pic.leetcode-cn.com/c75f6c354c3e8c551f72b2920cc6954729dc4f92418fdc99d7fd4c93f8bf314a-%E5%9B%BE%E7%89%87.png)

1.因为题目描述的是两条长度相同的字符串，因此不考虑长度不同的情况。
2.如果要得出交换最小的次数，当`s1`和`s2`相同位置的字符相同的话，则不用考虑，只需考虑相同位置字符不相同的情况。
3.若要有解，则s1和s2相同位置不同字符的个数必为偶数。
4.找出相同位置上s1为x，s2为y的个数num[0]，s1为y，s2为x的个数num[1],如果它们为偶数，它们的一半之和就为所需交换的次数，因为当`s1 = "xx", s2 = "yy"`时，只需交换一次。
5.如果两个num为奇数，则加一的一半为交换的次数，因为`s1 = "xy", s2 = "yx"`时，需交换两次。
6.利用int强制舍为整数的特性，将两个公式合并。
PS：希望我回头看的时候能知道自己在说些什么。
```
class Solution {
    public int minimumSwap(String s1, String s2) {
        int count;
		int[] num=new int [2];
		char[] ch =s1.toCharArray();
		char[] sh =s2.toCharArray();
		for(int i=0;i<ch.length;i++)
		{
			if(ch[i]=='x'&&sh[i]=='y') num[0]++;
			if(ch[i]=='y'&&sh[i]=='x') num[1]++;
		}
		if((num[0]+num[1])%2!=0) 
			count=-1;
		else
			count=(num[0]+1)/2+(num[1]+1)/2;
		return count;
    }
}
```
