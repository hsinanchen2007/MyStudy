### 解题思路
一开始采用HashMap记录出现字符 统计频率 在遍历字符数组 将cnt大于1的key累加 到新的hash位置 
但是会超时 
采用线性探测和路径压缩 时间复杂度 是o(n) 但是 比计数搬运耗时多

### 代码

```java
class Solution {
    int minIncrementForUnique(int[] A){
	    int arr[]=initCountArray(A);
	    return countMoveToSingle(arr);
	}
	
	/**
	 * 将数组中的值作为下标 往大的数组中存放数值出现的频率
	 * A[1,2,2,3] -> arr[0,1,2,1]:索引0位置没有数据 ，索引2位置出现2次 即A数组中数字2重复出现一次
	 * @param A
	 * @return
	 */
	private int[] initCountArray(int[] A){
		int max=0;
		for(int v:A){
			max=Math.max(max, v)+1;
		}
		int cntArr[]=new int[max*2];
	    for(int i=0;i<A.length;i++){
	    	cntArr[A[i]]++;
	    }
	    return cntArr;
	}
	/**
	 * 将arr数组中的i位置大于1的数据，其 后一个位置加上i位置的arr[i] 在减去i位置保留的一个1 即：arr[i+1]+=arr[i]-1;
	 * 移动次数cnt+=arr[i]-1;
	 * 再将arr[i]置为1
	 * 以上逻辑依次循环执行
	 * 其实可以想象成一排砖头 有的格子上有一块甚至多块 有的没有  就是把多于1块砖头的格子
	 * 搬运到后面的格子上（包括空格子）直到所有格子都是小于等于1块 ，一次可以搬运多块 但是搬运块数累计到搬运次数
	 * 即搬运2快相当于搬运2次
	 * @param arr
	 * @return
	 */
	private int countMoveToSingle(int[] arr){
		int cnt=0;
		for(int i=0;i<arr.length;i++){
	        if(arr[i] > 1){
	        	arr[i+1] += arr[i]-1;
	        	cnt += arr[i]-1;
	            arr[i] =1;
	        }
	    }
		return cnt;
	}
}
```