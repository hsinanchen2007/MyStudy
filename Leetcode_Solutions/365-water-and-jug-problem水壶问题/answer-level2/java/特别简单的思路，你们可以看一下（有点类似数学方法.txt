### 解题思路
我看到这道题，我完全没看出要用图，所以我就用自己的思路了进行解题了。（后面提交完后，看了一下题解，发现我的过程其实有点类似贝祖定理的那个方法）
大致思路：我们给定一个数组array，数组array的长度是x+y+1的值，且数组初始化值都是0。因为x的桶和y的桶能装到的最大容量是x+y。所以array[i]=0表示这两个桶是否能装到水量为i的情况，1表示可以，0表示不可以。然后后面将可能的情况全遍历一遍，最后判断array[z]是不是1就完事了。

算法设计：首先排除一些可能的情况：
①z=0，这个肯定不用桶就能完成。
②z>x+y，这个用了也装不到.
③x==y，这个情况明显就三种水量可以装到:0,x,2*x。
④z<=x+y&&x!=y，这里我们不妨假设x是较小量，y是较大量，当前两个桶总和的装水量是temp(初值为0)。
然后我们循环把x装满，再倒进y里面，每一步结束后都会改变里面array[temp]。直到后面y满了，x还有水为止，也就是temp>y的时候，我们要做两件事，第一件事：改变array[temp]值，第二件事：将y的水全倒了，再将x残留的水倒进y里面，再进行上述的循环。这个时候，执行循环的动力是：装水量没有出现重复的情况，因为如果出现重复的情况，那么肯定是已经遍历完了所有可能的情况，程序再次从初始状态重新开始了。

时间复杂度:O(x+y+1)；因为只是对x+y+1的数组进行填充，最多填充x+y+1次；
空间复杂度:O(x+y+1)。
### 代码

```java
class Solution {
    public boolean canMeasureWater(int x, int y, int z) {
        if(z==0) return true;
		if(z>x+y) return false;
		if(x==y) {
			if(z!=x&&z!=x+y) return false;
			else return true;
		}
		int[] array = new int[x+y+1];
		int max = x>y?x:y;
		int min = x<y?x:y;
		int water = min;
		while(array[water]!=1) {
			array[water] = 1;
			water+=min;
			if(water<=max) {
				continue;
			}else {
				array[water] = 1;
				water = water - max;
			}
		}
		if(array[z] == 1) return true;
		else return false;
    }
}
```