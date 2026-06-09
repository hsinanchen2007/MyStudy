### 解题思路
1.本题目隶属动态规划。
2.在考虑情况text1[:m+1]与text2[:n+1]时,如果text1[m+1]==text2[n+1],则将其赋值为text1[:m]与text2[:n]的结果+1;否则,取text1[:m]与text2[:n+1]、text1[:m+1]与text2[:n]二者间较大值。
3.注意边缘初始的赋值。

### 代码
```java
class Solution {
    public static int longestCommonSubsequence(String text1, String text2) {
		int len1 = text1.length(),len2=text2.length();
		// 初始化二维数组
		int[][] array = new int[len1][];
		for(int i=0;i<=len1-1;i++) {
			int[] temp = new int[len2];
			for(int j=0;j<=len2-1;j++) {
				temp[j]=0;
			}
			array[i]=temp;
		}
		//先确定边缘部分
		int index=0;
		while(index<=len1-1) {
			if(text2.charAt(0)==text1.charAt(index)) {
				while(index<=len1-1) {
					array[index][0]=1;
					index++;
				}			
			}else {
				array[index][0]=0;
                index++;
			}
		}
		index = 0;
		while(index<=len2-1) {
			if(text1.charAt(0)==text2.charAt(index)) {
				while(index<=len2-1) {
					array[0][index]=1;
					index++;
				}
			}else {
				array[0][index]=0;
                index++;
			}
		}
		//再开始逐一从左向右、从上到下排查
		for (int i=1;i<=len1-1;i++) {
			for(int j=1;j<=len2-1;j++) {
				if(text1.charAt(i)==text2.charAt(j))
					array[i][j]=array[i-1][j-1]+1;
				else
					array[i][j]=Math.max(array[i-1][j], array[i][j-1]);
			}
		}
		return array[len1-1][len2-1];
    }
}




```python3
class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        steps = []
        for i in range(len(text1)):
            steps.append([])
            for j in range(len(text2)):
                steps[-1].append(0)
        index = 0
        while index < len(text1):
            if text1[index] == text2[0]:
                while index < len(text1):
                    steps[index][0] = 1
                    index += 1
            else:
                index+=1
        index = 0
        while index < len(text2):
            if text2[index] == text1[0]:
                while index < len(text2):
                    steps[0][index] = 1
                    index += 1
            else:
                index+=1
        for i in range(1, len(text1)):
            for j in range(1, len(text2)):
                if text1[i] == text2[j]:
                    steps[i][j] = steps[i - 1][j - 1] + 1
                else:
                    steps[i][j] = max(steps[i - 1][j], steps[i][j - 1])
        return steps[len(text1) - 1][len(text2) - 1]
```