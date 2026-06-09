好像没人这么写，分享一下：java速度0ms，内存35mb
循环遍历数组，只考虑当前位置的元素，不考虑其他位置是否错乱：
当前元素值matrix[i][j] = matrix[length-1-j][i]
然后进行交换，最后会有length个元素不需要交换，在里循环条件中把他们剔除掉就好了。
代码如下，欢迎指正：

```matlab
public void rotate(int[][] matrix) {
        int length = matrix.length;
	    for(int i = 0;i<length;i++) {
	        for(int j = 0;i<length/2?j<length-i-1:j<i+1;j++) {
	        	int a = matrix[i][j];
	        	matrix[i][j] = matrix[length-1-j][i];
	        	matrix[length-1-j][i] = a;
	        }
	    }
    }
```