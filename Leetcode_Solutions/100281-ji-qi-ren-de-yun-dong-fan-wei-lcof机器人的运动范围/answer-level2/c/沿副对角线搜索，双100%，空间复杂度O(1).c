**解题思路：利用副对角线特点，巧解题目，几乎没有额外空间开销，结果：双100%**

  仔细观察“数位和”矩阵的副对角线，发现绝大多数都是相同的，这是因为“原始”矩阵的副对角线上col+row为定值，在大多数情况下（例如：[12,35]的左下和右上分别为[13,34]和[11,36]），他们的“数位和”都是一样的。在少数情况下（例如：[10,37]的右上为[9,38]）发生突变。

  如果我们把“数位和”刚好等于k+1的数看成一堵墙的话，这堵墙将从右上拉到左下，当然，有的地方会“漏风”（当“数位和”突变的时候），这就是第二个关键点：

  如果把m和n看做是无限的，那么我们把“原始”矩阵按照10*10的规格划分成无数个分块矩阵（称为“中等矩阵”），如果把每一个“中等矩阵”看成“原始”矩阵的一个元素，那么“原始”矩阵的每个副对角线上的“中等矩阵”都是一模一样的。来个图感受一下：
![题解配图.png](https://pic.leetcode-cn.com/03be45c74ab27f2086ce70562e44ed2cdaed066bdddc9e091b3dd0161132a8e2-%E9%A2%98%E8%A7%A3%E9%85%8D%E5%9B%BE.png)
  同种颜色的框都是一模一样的“中等矩阵”
  这导致的结果就是：如果某条副对角线上的某一个“中等矩阵”构成的那堵墙“漏风”，那么这条对角线上的所有“中等矩阵”都漏风（例如：一个蓝色框对k=12“漏风”，所有的蓝色框都对k=12“漏风”）

  这样带来的结果是：
  1、只用不断移动副对角线（代码中的sum代表“原始”矩阵副对角线行列和），对所有符合条件的“数位和”计数，就可以得到结果（某一个“中等矩阵”被“墙”完全挡住就意味着整体结束；某一个“中等矩阵”“漏”了过去意味着所有的都能“漏过去”），这就是本题解题思路，代码见下：
```
int get_digit_sum(int a,int b){
	int sum=0;
	while(a!=0){
		sum+=a%10;
		a/=10;
	}
	while(b!=0){
		sum+=b%10;
		b/=10;
	}
	return sum;
}
int movingCount(int m, int n, int k){
	//maximum of row+col
	int MAX=m+n-2;
//	//smaller one of m&n
//	int SMALL;
	int count=0;
	//if this diag accessible
	int flag=1;
	int sum=0;
	if(m>n){
		int row,startRow=0;
//		SMALL=n; 
		//diag move
		while(flag==1&&sum<=MAX){
			flag=0;
			row=startRow;
			//move along the diag
			while(row<m&&row<=sum){
				if(get_digit_sum(row,sum-row)<=k){
					flag=1;
					count++;
				}
				row++;
			}
//			if(++sum>=SMALL)startRow++;
			if(++sum>=n)startRow++;
		}
	} 
	else{
		int col,startCol=0;
//		SMALL=n; 
		//diag move
		while(flag==1&&sum<=MAX){
			flag=0;
			col=startCol;
			//move along the diag
			while(col<n&&col<=sum){
				if(get_digit_sum(col,sum-col)<=k){
					flag=1;
					count++;
				}
				col++;
			}
//			if(++sum>=SMALL)startRow++;
			if(++sum>=m)startCol++;
		}
	}
	return count;
}
```

  2、根据“中等矩阵”在“原始”矩阵中的重复性，只要满足m=n并且m%10==0，算法还可以进一步简化为只计算一行一列的“中等矩阵”，利用题目特殊性大大压缩算法复杂度。但问题是这道题里面m!=n，我就不知道怎么用上这个思路来改进了，先写在这里，权当为大佬抛砖引玉。