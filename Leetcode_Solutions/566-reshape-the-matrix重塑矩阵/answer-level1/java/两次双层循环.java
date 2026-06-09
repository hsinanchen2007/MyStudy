### 解题思路
此处撰写解题思路

### 代码
判断是否能够构建所需结构的数组
```java
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        if(r == 0||c == 0)
            return nums;
        int[][] numss = new int[r][c];
        int[] a = new int[r*c];
        int i,j,coun = 0;
        for(int[] x:nums) {
			for(int y:x) {
				if(coun < r*c) {
					a[coun] = y;
					coun++;
				}else
					break;
			}
			if(coun == r*c)
				break;
		}
		if(coun != r*c)
			return nums;
		else {
			coun = 0;
			for(i = 0;i < r;i++) {
				for(j = 0;j < c;j++) {
					numss[i][j] = a[coun];
					coun++;
				}
			}
			return numss;
		}
		
    }
}
```