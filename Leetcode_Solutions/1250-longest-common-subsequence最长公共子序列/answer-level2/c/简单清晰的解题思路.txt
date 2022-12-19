### 解题思路
解题思路：
本题是较为经典的动态规划问题，先求解该动态规划表的过程，如果str1的长度为M，str2的长度为N，生成大小为M*N的矩阵DP，行为M，列为N，DP[i][j]的含义为str1[0…i] 与str2[0…j]的最长公共子序列的长度，从左到右，从上到下计算矩阵DP
关于矩阵第一列和第一行的计算，也就是边界值设定：
边界的状态转移方程：
DP[i][0] = Max(DP[i-1][0], (str1[i] == str2[0] ? 1 : 0))
矩阵第一列DP[0…M-1][0]，DP[i][0]的含义就是str1[0…i]与str2[0]的最长公共子序列长度。因为str2[0]，只有一个字符，所以DP[i][0]的最大值为1，如果str[x]( 0<x<i)  == str2[0],令DP[i][0] = 1,一旦DP[i][0]为1，则后续的DP[i+1…M-1][0]也都为1.
DP[0][j]= MAX(DP[0][j-1], (str1[0] == str2[j] ? 1: 0))
同理矩阵第一行DP[0][0…N-1]，也是存在str1[0]==str2[j]，则令DP[0][j] =1,一旦DP[0][j] = 1，则后续的DP[0][j+1..N-1]也都为1.

通用的动态规划的状态转移方程：
DP[i][j] = MAX(DP[i-1][j], DP[i][j-1], (str1[i] == str[j] ? 0 : 1) + DP[i-1][j-1])
DP[i][j]的值只能来自以下三种情况：
(1) DP[i-1][j]
代表str1[0…i-1]和str2[0…j]的最长公共子列长度。比如str1=“A1BC2”,Str2="AB34C"。Str1[0…3]（“A1BC"）与Str2[0..4]("AB34C")的最长公共子序列长度为3（“ABC”），即DP[3][4 ] =3 ,而str1[0…4]（“A1BC2”）与Str2[0..4]]("AB34C")的最长公共子序列也为3,即DP[4][4] = 3
(2) DP[i][j-1]
代表str1[0…i]和str2[0…j-1]的最长公共子列长度。基本逻辑同DP[i-1][j]是一样的

(3) DP[i-1][j-1] + 1  ，前提条件str1[i] == str2[j]
特别需要注意这个特殊状态
比如str1="ABCD",str2="ABCD"。
Str1[0..2] = "ABC",Str2[0..2] = "ABC" ，DP[2][2] = 3 ，
Str1[0..3] = "ABCD",Str2[0..2] = "ABC" ，DP[3][2] = 3，
Str1[0..2] = "ABC",Str2[0..3] = "ABCD" ，DP[2][3] = 3
但是：Str1[0..3] = "ABCD",Str2[0..3] = "ABCD" ，DP[3][3] = 4 = DP[2][2] + 1


### 代码

```c

#define MAX(x,y) ((x)>(y)? (x):(y))
int longestCommonSubsequence(char * text1, char * text2){
	int len1;
	int len2;
	int i;
	int j;
	int tmp;
	len1 = strlen(text1); // 行
	len2 = strlen(text2); // 列
	// 构建DP矩阵
    int DP[1000][1000] = {0};
	// int** DP = (int**)malloc(sizeof(int*) * len1);
	// for (i = 0; i < len2; i++) {
	// 	DP[i] = (int*)malloc(sizeof(int) * len2);
	// 	memset(DP[i], 0, sizeof(int) * len2);
	// }
	// 处理边界条件值
	if (text1[0] == text2[0]) {
		DP[0][0] = 1;
	}
	// 处理第一列
	for (i = 1; i < len1; i++) {
		tmp = (text1[i] == text2[0] ? 1 : 0);
		DP[i][0] = MAX(DP[i-1][0],tmp);
	}
	//处理第一行
	for (j = 1; j < len2; j++) {
		tmp = (text2[j] == text1[0] ? 1 : 0);
		DP[0][j] = MAX(DP[0][j-1], tmp);
	}
	// 循环遍历处理通用DP矩阵节点
	for (i = 1; i < len1; i++) {
		for (j = 1; j < len2; j++) {
			tmp = (text1[i] == text2[j] ? 1 : 0) + DP[i - 1][j - 1];
			DP[i][j] = MAX(DP[i - 1][j], DP[i][j - 1]);
			DP[i][j] = MAX(DP[i][j], tmp);
		}
	}
	return DP[len1 - 1][len2 - 1];
}
```