### 解题思路
此处撰写解题思路
思路很简单 DP[i][j] 表示 A中0-i个元素组成得数组和B0-j元素组成得数组最大得连线数量。得到下面递归公司
DP[i][j] = MAX(DP[i-1][j], DP[i][j-1], (str1[i] == str[j] ? 0 : 1) + DP[i-1][j-1])
首先证明下这个公式：
**先讨论A[i]!=B[j]**。因为加一个元素最多只加1根线 DP[i][j] =< DP[i][j] <=DP[i][j-1] + 1 

DP[i][j-1] 和D[i-1][j] 有三种情况 ：1 DP[i][j-1] = DP[i-1][j]   2 DP[i][j-1] = DP[i-1][j] +1 3 DP[i][j-1] +1 = DP[i-1][j] 
第1种情况 只有两种情况 DP[i][j-1] = DP[i-1][j] = DP[i][j] -1 ; 表示缺A[i]B[j]任一元素都少一跟线，表示A[i]B[j]相互连线 即A[i]=B[j]矛盾
就只剩 DP[i][j-1] = DP[i-1][j] = DP[i][j] 以终情况
第2种情况 DP[i-1][j] =< DP[i][j] <=DP[i-1][j] + 1  DP[i][j-1] =< DP[i][j] <=DP[i][j-1] + 1  得到DP[i][j] =DP[i][j-1]
同理第3种 DP[i][j] =DP[i-1][j]
1，2，3种情况可以表示 ：DP[i][j] = MAX(DP[i-1][j], DP[i][j-1]）

**再讨论A[i]==B[j]**,就是A[i]跟B[j]连线 DP[i][j] =1 + DP[i-1][j-1];A和B 不连线DP[i][j] = MAX(DP[i-1][j], DP[i][j-1]）
综合起来：DP[i][j] = MAX(DP[i-1][j], DP[i][j-1],  1 + DP[i-1][j-1])


综合起来就是:DP[i][j] = MAX(DP[i-1][j], DP[i][j-1], (str1[i] == str[j] ? 0 : 1) + DP[i-1][j-1])


### 代码

```c
#define MAX(x,y) ((x)>(y)? (x):(y))

int maxUncrossedLines(int* A, int ASize, int* B, int BSize){
    int DP[200][200] = {0};
    int tmp = 0;
    //1计算包含A[0] B[0]所有值，用于动态规划出所有值
    if (A[0] == B[0]) {
		DP[0][0] = 1;
	}
	for (int i = 1; i < ASize; i++) {
		tmp = (A[i] == B[0] ? 1 : 0);
		DP[i][0] = MAX(DP[i-1][0],tmp);
	}
	for (int j = 1; j < BSize; j++) {
		tmp = (B[j] == A[0] ? 1 : 0);
		DP[0][j] = MAX(DP[0][j-1],tmp);
	}
    //2 用动态规划公式 得到DP[ASize-1][BSize-1]
    //如果 DP[i][j] = MAX(DP[i-1][j], DP[i][j-1], (str1[i] == str[j] ? 0 : 1) + DP[i-1][j-1])
    for (int i = 1; i < ASize; i++) {
		for (int j = 1; j < BSize; j++) {
			tmp = (A[i] == B[j] ? 1 : 0) + DP[i - 1][j - 1];
			DP[i][j] = MAX(DP[i - 1][j], DP[i][j - 1]);
			DP[i][j] = MAX(DP[i][j], tmp);
		}
	}
	return DP[ASize - 1][BSize - 1];

}


```