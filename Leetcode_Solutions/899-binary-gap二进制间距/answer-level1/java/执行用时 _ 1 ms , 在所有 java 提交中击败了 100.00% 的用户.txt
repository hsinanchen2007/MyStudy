```
class Solution {
    public int binaryGap(int N) {
		int count = 0, max = 0, tem = 0, count1 = 0;
		while (N != 0) {
			if (N % 2 == 1) {
				if (count1 > 0)//因为count++操作是位于max的比较操作之后，所以就会造成第一个余为1进入if语句时tem=0，即初值，如N=12时,此时如果得出的max值比较大，那么后面就会出错，所以必须保证tem保存的是上一个1的位置
					max = Math.max(max, count - tem);//max是上一个俩连续1的距离最大值，和当前俩连续1进行比较
				tem = count;//tem保存上一个1的位置
				count1++;//计算二进制中1的个数
			}
			count++;
			N /= 2;
		}
		max = count1 > 1 ? max : 0;//如果count1=1或者count1=0时直接返回0
		return max;
	}
}
```
