思路很清晰；就是按圈打印就是了
思路两分钟，编码两小时，这是为什么？
编码遇到的问题：
1、边界问题，行跟列一定分清楚；
2、多打印问题，末尾多打印一次，其实也可以归结为边界问题；//这个问题采用暴力限制不越界的方式，加一个数组越界限制，始终觉得不够优雅；

最后，在提交的时候，多了两条输出语句，速度就明显变慢了

```class Solution {
   public static int[] spiralOrder(int[][] matrix) {
        int left = 0;
        int bottom = matrix.length-1;
        if(bottom==-1){
            return new int[0];
        }
        int right = matrix[0].length-1;
        int top = 0;
        int totalCount = (right+1)*(bottom+1);
        int [] ret = new int[totalCount];
        int index = 0;
        while(top<=bottom||left<=right){ //轮询一圈,判断转圈是否结束；
        //直行
        for(int i = left;i<=right&&index<totalCount;i++){
        	// System.out.print("直"+matrix[top][i]+"\n");
            ret[index] = matrix[top][i];
            index++;
        }
        	 top++;
        //下行
        for(int i = top;i<=bottom&&index<totalCount;i++){
        	// System.out.print("下"+matrix[i][right]+"\n");
            ret[index] = matrix[i][right];
            index++;
        }
        	right--;	
        //逆行
        for(int i = right;i>=left&&index<totalCount;i--){
        	// System.out.print("逆"+matrix[bottom][i]+"\n");
            ret[index] = matrix[bottom][i];
            index++;
        }
        	bottom--;
        //上行
        for(int i = bottom;i>=top&&index<totalCount;i--){
        	// System.out.print("上"+matrix[i][left]+"\n");
            ret[index] = matrix[i][left];
            index++;
        }
        	left++;
        }
        return ret;
    }
}```