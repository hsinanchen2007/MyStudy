### 解题思路

1. 设有 i个 连续整数 相加得到 target.
2. 那么其中第一个整数为 temp/i,其中 temp = target - ((i-1)*i)/2
3. 一维数组就得到了()
4. 为得到二维数组，需要对 i+1 个连续整数探讨，以此类推，循环处理。
5. 注意最后输出倒序
 
 执行用时 :1 ms, 在所有 Java 提交中击败了96.88%的用户
 内存消耗 :37.5 MB, 在所有 Java 提交中击败了100.00%的用户

### 代码

```java
class Solution {
    public int[][] findContinuousSequence(int target) {

            	
    	ArrayList<int[]> arr=new ArrayList<int[]>();
    	
    	int i=2;//数组最小有两个元素
    	while(true) {
    		int temp =target - ((i-1)*i)/2;
            if(temp<=0)
    			break;
    		if(temp%i==0) {
    			int[] temp_arr = new int[i];
    			for(int j=0;j<i;j++)
    				temp_arr[j]=temp/i+j;
    			arr.add(temp_arr); 			
    		}
    		i++;
    	}
    	Collections.reverse(arr);
    	return arr.toArray(new int[0][]);
    }

    
}
```