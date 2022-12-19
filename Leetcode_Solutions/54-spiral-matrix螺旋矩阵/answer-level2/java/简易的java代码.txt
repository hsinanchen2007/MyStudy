### 代码

```java
class Solution {
    public List<Integer> spiralOrder(int[][] matrix){
		List<Integer> res = new ArrayList<>();
		if(matrix.length == 0){
			return res;
		}
		int top = 0;
		int bottom = matrix.length - 1;
		int left = 0;
		int right = matrix[0].length - 1;
		int i = 0;
		int j = 0;
		while(true){
			for(;j<=right;j++){
				res.add(matrix[i][j]);
			}
			j--;
			top = ++i;
			if(top > bottom){
				break;
			}
			for(;i<=bottom;i++){
				res.add(matrix[i][j]);
			}
			i--;
			right = --j;
			if(left > right){
				break;
			}
			for(;j>=left;j--){
				res.add(matrix[i][j]);
			}
			j++;
			bottom = --i;
			if(top > bottom){
				break;
			}
			for(;i>=top;i--){
				res.add(matrix[i][j]);
			}
			i++;
			left = ++j;
			if(left > right){
				break;
			}
		}
		return res;
	}
}
```

### 性能表现

![1.png](https://pic.leetcode-cn.com/19d1b3b8fb94e06b01132c0510d49cb9cc9f183358e6f6249cc2288bd3b3c534-1.png)
