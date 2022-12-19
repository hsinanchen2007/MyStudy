# [排序]378. 有序矩阵中第K小的元素
### 归并解法
```java
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
        //k值永远有效, 所以就不做判空操作了
    	int[]indexs=new int[matrix.length]; //各行起始下标为0
    	int curMin=matrix[0][0];
    	for(int i=0;i!=k;i++) {
    		// 遍历各行,找出最小的那个元素
    		curMin=Integer.MAX_VALUE;int index=0;
    		for(int j=0;j!=matrix.length;j++) {
                // 已经不合法的indexs[j], 说明第j行已经遍历完了
    			if(indexs[j]<matrix[0].length&&curMin>=matrix[j][indexs[j]]) {
    				index=j;curMin=matrix[j][indexs[j]];
    			}
    		}
    		indexs[index]++;
    	}
    	return curMin;
    }
}
```
### 结合堆得归并解法
```java
class Solution {
	private class Tuple {
		int val;int row; int col;
		public Tuple(int val, int row, int col) {
			this.val = val;
			this.row = row;
			this.col = col;
		}
	}
    public int kthSmallest(int[][] matrix, int k) {
    	//k值永远有效, 所以不判空
    	// 使用tuple记录最小元素, 存在堆中(减少每次找n行中最小元素的时间)
    	PriorityQueue<Tuple> heap = new PriorityQueue<Tuple>((i,j)->i.val-j.val);
    	for(int i=0;i!=matrix.length;i++) { // 堆初始化
    		heap.add(new Tuple(matrix[i][0],i, 0));
    	}
    	for(int i=0;i!=k-1;i++) { //处理k-1次
    		Tuple poll = heap.poll();
    		//如果下标出界了 置为最大值
    		int val=poll.col+1<matrix.length?matrix[poll.row][poll.col+1]:Integer.MAX_VALUE;
    		// 压入当前行的下一个元素
    		heap.add(new Tuple(val, poll.row, poll.col+1));
    	}
    	return heap.poll().val;
    }
}
```
## 范围型二分查找
```java
class Solution {
    public int kthSmallest(int[][] matrix, int k) {
    	//[lo, hi) 左闭右开的范围型二分查找
        int lo = matrix[0][0], hi = matrix[matrix.length - 1][matrix[0].length - 1] + 1;
        while(lo < hi) {
            int mid = lo + (hi - lo) / 2; //避免两个加起来溢出
            // 记录有多少个元素小于等于mid
            int count = 0,  j = matrix[0].length - 1; 
            for(int i = 0; i < matrix.length; i++) {
            	// 逐行遍历,梯形减少(因为矩阵竖向递增,当前不符了,下一行更不可能符合了)
                while(j >= 0 && mid < matrix[i][j]) j--;
                count += (j + 1);
            }
            if(count < k) lo = mid + 1; // 比mid小于等于的不到k个,说明第k小的再更大处
            else hi = mid;// 比mid小于等于的大于等于k个(等于k个了也可能这个mid不在矩阵里,所以要去小处找,并且带上mid)
        }
        return lo;//循环结束时lo==hi
    }
}
```