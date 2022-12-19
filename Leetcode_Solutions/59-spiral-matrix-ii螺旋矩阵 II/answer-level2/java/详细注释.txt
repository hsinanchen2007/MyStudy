```
    public int[][] generateMatrix(int n) {
        if(n==0) return null;
        int[][] arr=new int[n][n];

        int up=0;
        int bottom=n-1;
        int left=0;
        int right=n-1;

        int value=1;
        /**
         *  while循环体一次只处理4个边界：
         *  上右下左(按顺时针顺序)
         *
         *  循环体的结束条件：未处理的数组为0行或者0列。
         *  因为在缩小边界的时候，只需要保证数组为0行或者0列就可以保证未处理的数组大小为0
         *
         */
        while(true){
            //处理上边界
            for(int i=left;i<=right;i++){
                arr[up][i]=value;
                value++;
            }
            //上边界处理完成后缩小上边界,并判断行数是否为O，即判断up是否大于bottom
            up++;
            if(up>bottom)break;

            //处理右边界
            for(int i=up;i<=bottom;i++){
                arr[i][right]=value;
                value++;
            }
            //右边界处理完成后缩小右边界，并判断列数是否为0，即判断right是否小于left
            right--;
            if(right<left)break;

            //处理下边界
            for(int i=right;i>=left;i--){
                arr[bottom][i]=value;
                value++;
            }
            //下边界处理完成后缩小下边界，并判断行数是否为0，即判断bottom是否小于up
            bottom--;
            if(bottom<up)break;

            //处理左边界
            for(int i=bottom;i>=up;i--){
                arr[i][left]=value;
                value++;
            }
            //左边界处理完成后缩小左边界，并判断列数是否为0，即判断left是否大于right
            left++;
            if(left>right)break;
        }
        return arr;
    }
```
