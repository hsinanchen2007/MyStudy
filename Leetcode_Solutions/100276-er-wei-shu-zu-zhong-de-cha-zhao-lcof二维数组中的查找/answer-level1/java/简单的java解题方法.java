### 执行结果
执行用时 :0 ms, 在所有 Java 提交中击败了100%的用户
内存消耗 :47.3 MB, 在所有 Java 提交中击败了100.00%的用户
### 解题思路
从左下角元素开始
1. 如果数字等于target，查找过程结束；
2. 如果target小于该元素,剔除所在列；
3. 如果target大于该元素，提出所在行；
![image.png](https://pic.leetcode-cn.com/568be60eb70f34522cd442170be91c502d101c08684c2443332bbbe668f332a3-image.png)

### 代码

```java
class Solution {
    public boolean findNumberIn2DArray(int[][] matrix, int target) {
        if(matrix==null || matrix.length==0 ||matrix[0].length==0) {
			return false;
		}
		int n=matrix.length-1,m=0;
		boolean flag=false;
		while(m<matrix[0].length && n>=0) {
			int temp=matrix[n][m];
			if(temp==target) {
				flag=true;
				break;
			}else if(target<temp){
				n--;
			}else if(target>temp) {
				m++;
			}
		}
		return flag;
    }
}
```