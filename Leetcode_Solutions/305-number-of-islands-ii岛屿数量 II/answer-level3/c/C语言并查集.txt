————————————————
版权声明：本文为CSDN博主「Monkey&amp;Penguin」的原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/qq_40285768/article/details/104666034

!!!!(我自己是vs2015,通过；leetcode编辑器要报个错的错，所以连着测试用例一起发出来了)！！！！

首先很容易想到的思路是给每个岛屿唯一的编号，当给这个二维数组加入一个岛时，分为以下12种情况：

1.新加入的岛加入的周围全是0，那么岛屿数count+1；

2.一个非0的数，count不变。

3.两个非0的数：
                  （1）两个非0数相同：count不变；
                  （2）两个数不同，统一编号，count-1；

4.三个非0数：
                  （1）三个相同，count不变；
                  （2）两个相同，统一编号，count-1；
                  （3）三个不同，统一编号，count-2；

5.四个非0数：
                   （1）四个相同，count不变；
                   （2）三个相同，统一编号，count-1；
                   （3）两个相同，剩下两个也相同，统一编号，count-1；
                   （4）两个相同，剩下两个不相同，统一编号，count-2；
                   （5）全不同，统一编号，count-3；

以上思路存在两个需要解决的问题。（1）如何处理上面12种这些不同情况。当然我们可以使用if、elseif巴拉巴拉等来实现以上操作，但是，如果所有算法逻辑都靠判断语句来跳转实现，是否会特别复杂？以后遇到三维数组甚至更高更多的情况，判断语句条件是可以几何增长的的。所以我们应该考虑看到这些情况归类的本质，用递归调用之类的方法去实现。（2）统一编号时，该如何统一？难不成编号2的岛归属编号1时，遍历一次整个表？时间复杂度、时间复杂度！下面我们来思考这两个问题。

首先我们解决问题1，我们可以看到，情况分为多种，但是他们本质是什么？无非是插入一个节点，然后查找是否周围有可以让自己加入的岛。任意拟一个标准顺序，上下左右去查找是不是有其他岛。当查到身边（比如上方）有一个岛，和他自己编号不同时，岛数是不变的，因为他直接加入了这个岛屿群1，接着继续查找，当加入上方岛屿群后，发现下方也有个岛屿群，和自己编号不同，那么，让下方岛屿都归属自己加入的岛屿群1，并且岛屿数减一，接着继续查找。

我们就可以看到问题1的本质，遍历身边的点，若自己独立获得一个编号，岛屿数加一，若统一n次身边岛屿数编号，岛屿数便减少n个。岛屿数的本质的本质便是看编号数的增减。

再看问题2，如何统一一个岛屿群的编号，遍历是可以的，但太浪费时间。所以应该设置一个指针，所有岛屿节点应该有个结构成员指针，指向同一个地址，统一编号时，就将这个地址存储的变量进行修改，从而达到修改整个岛屿群的目的。但是这个指向的地址声明该如何声明？因为不会在遇到了要新增岛屿时，再去临时声明一个int型变量。所以在一开始不确定会有多少个岛屿群时，我们应该声明一个岛屿编号数组，类似于我们上学前提前准备好的花名册，当遇到了，就对号入座，需要修改，就在花名册上修改。但是这个花名册长度应该是多长呢？这取决于n个节点的二维数组，最多我们可以拥有多少个岛屿群，答案是（n/2向上取整）,如下:

1    0    0    1

0    1    0    1

1    0    1    0

```
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
 
#define MAX 10
 
int *map[MAX][MAX];       //可接受的地图极大值为MAX*MAX
int s_number[(MAX + 1) / 2];  //待分配的岛屿编号数组牌
int count;                //目前岛屿数量
int *current;             //岛数分配指针
 
 
						  //数据初始化
void init(int m, int n) {
	//将岛屿编号牌初始化，分配指针指向第一个
	for (int k = 0; k < m*n / 2 + 1; k++)
		s_number[k] = k;
	current = &s_number[0];
 
	//岛屿数量归0
	count = 0;
 
	//将实际地图初始化为0，代表水域
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			map[i][j] = current;
	current++;//current = &s_number[1]
}
 
//并查集，二维数组下查root、合并关键操作
int unify(int x, int y, int nx, int ny, int m, int n) {
	//对插入节点周围的（newx,newy）进行探测
	if (nx < 0 || nx >= m || ny < 0 || ny >= n)
		return 0;
	else if (*map[nx][ny] != 0) {
		if (*map[x][y] == 0) {
			map[x][y] = map[nx][ny];
			return 1;
		}
		else {
			if (*map[nx][ny] != *map[x][y]) {
				map[nx][ny] = map[x][y];
				count--;//岛数减一
				return 1;
			}
			else return 1;
		}
	}
	else return 0;
}
 
void join(int *p, int m, int n) {
	//查看是否重复添加
	if (*map[p[0]][p[1]] == 0) {
		//并查集归根
		int u = unify(p[0], p[1], p[0], p[1] - 1, m, n);//左方节点
		int d = unify(p[0], p[1], p[0], p[1] + 1, m, n);//右方节点
		int l = unify(p[0], p[1], p[0] - 1, p[1], m, n);//上方节点
		int r = unify(p[0], p[1], p[0] + 1, p[1], m, n);//下方节点
		if (u + d + l + r == 0) {
			map[p[0]][p[1]] = current;
			count++;
			current++;
		}
	}
}
 
int* numIslands2(int m, int n, int** positions, int positionsSize, int* positionsColSize, int* returnSize) {
	init(m, n);
	int *number = NULL;
	number = (int*)malloc(sizeof(int) * positionsSize);
 
	//依次加入每个位置
	for (int i = 0; i < positionsSize; i++) {
		join((int*)positions + i * 2, m, n);
		number[i] = count;
	}
 
	*returnSize = positionsSize;
	return number;
}
 
int main() {
	int a[4][2] = { { 0,0 },{ 0, 1 },{ 1,2 },{ 2,1 } };
	int m = 3, n = 3, c = 0;
	int ps = 4;
	int *returnSize = &c;
	int *q = numIslands2(m, n, (int**)a, ps, &c, returnSize);
	printf("%d %d %d %d", *q, *(q + 1), *(q + 2), *(q + 3));
	return 0;
}
```
