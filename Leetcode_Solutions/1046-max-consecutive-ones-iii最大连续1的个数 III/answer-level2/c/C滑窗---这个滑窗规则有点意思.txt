### 解题思路
很直观可想到滑窗做法，滑窗问题最关键点额是确定滑窗的规则。此题目移动左窗口 跳过 1  很关键，其他参考注释
参考了 yao-xian-zhi 题解

### 代码

```c
int max(int a, int b) {
	return a>b?a:b;
}

int longestOnes(int* A, int ASize, int K){
	if(ASize==0) return 0;

	int l =0, r=0, ZeroSum=0, maxLen = 0;
	while(r < ASize) {
		if(A[r++]==0) ZeroSum++;   /* 统计0的个数*/

		while(ZeroSum > K) { /* 达到更新Len的条件了 */
            if(A[l]==0) ZeroSum -= 1;			
			l++;  /* 左窗口移动, 因为要跳过1 用while */
		}
        maxLen = max(maxLen, r-l);
	}

	return maxLen;
}


```