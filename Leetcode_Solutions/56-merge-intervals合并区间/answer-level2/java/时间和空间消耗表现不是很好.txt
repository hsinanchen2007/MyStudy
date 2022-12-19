![2020040901.PNG](https://pic.leetcode-cn.com/ad86cea0db76a24bc125b82413d22acdc40238e3ab0865eecdfbd6c125240d19-2020040901.PNG)

### 解题思路
****
****
****
### 代码

```java
class Solution {
    public int[][] merge(int[][] intervals) {
        int len = intervals.length;
        int[][] out = new int[len][2];
        if(len==0) {
        	return out;
        }
        //##############
        //将intervals按照intervals[i][0]从小到大排序, 即Intervals数组按照第一列的值的大小进行升序排序
		for (int i = 1; i < len; i++) {
			int j = i;
			int[] temp = intervals[i];
			while (j - 1 >= 0 && temp[0] <= intervals[j - 1][0]) {
				intervals[j] = intervals[j - 1];
				j--;
			}
            intervals[j] = temp;
		}
		//##############
        //遍历排序后的intervals二维数组, 将可以整合的区间进行合并
		out[0][0] = intervals[0][0];
		out[0][1] = intervals[0][1];
        int index = 0;
        for(int i=1;i<len;i++) {
        	if(intervals[i][0] <=out[index][1]) {
        		if(intervals[i][1]>out[index][1]) {
        			out[index][1] = intervals[i][1];
        		}
        	}else {
        		index++;
        		out[index][0] = intervals[i][0];
        		out[index][1] = intervals[i][1];
        	}
        }
        //############
        //将合并后的结果放置在二维数组res中, 
        //将结果res返回
		int[][] res = new int[index+1][2];
		for(int i=0;i<=index;i++) {
			res[i] = out[i];
		}
        return res;
    }
}
```