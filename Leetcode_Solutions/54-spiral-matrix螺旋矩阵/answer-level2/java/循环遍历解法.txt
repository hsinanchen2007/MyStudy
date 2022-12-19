### 解题思路
此处撰写解题思路
顺时针方向循环遍历
### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> ret = new ArrayList<Integer>();
        if (matrix == null || matrix.length == 0) {
			return ret;
		}
        int left = 0, top = 0;
        int down = matrix.length -1;
        int right = matrix[0].length -1;
        while(left <= right && top <= down)
        {
        	// left -> right
        	for (int i = left; i <= right; i++) {
        		ret.add(matrix[top][i]);
			}
        	top++;
        	
        	// top -> down
        	for (int i = top; i <= down; i++) {
        		ret.add(matrix[i][right]);
			}
        	right--;
        	
        	// right -> left
        	for (int i = right; i >= left; i--) {
        		ret.add(matrix[down][i]);
			}
        	down--;
        	
        	// left -> top
        	for (int i = down; i >= top; i--) {
				ret.add(matrix[i][left]);
			}
        	left++;
        }
        return ret.subList(0, matrix.length * matrix[0].length);
    }
}
```