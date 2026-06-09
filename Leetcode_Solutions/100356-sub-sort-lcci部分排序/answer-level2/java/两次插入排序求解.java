class Solution {
    public int[] subSort(int[] array) {
        if(array==null||array.length==0||array.length==1) return new int[]{-1,-1};
        int[] copy = null;
        copy = Arrays.copyOf(array,array.length);
        int min = array.length;
        int max = 0;
        for(int i=0;i<array.length;i++){//从左往右插入排序
            int tmp = array[i];
            int j = i - 1;
            boolean moveFlag = false;//记录是否有元素交换
            while(j>=0){
                if(array[j]<=tmp){
                    break;
                }
                moveFlag = true;
                j--;
            }
            array[i] = array[j+1];
            array[j+1] = tmp;
            if(moveFlag&&j+1<min)min = j+1;//如果有元素交换,记录最左边交换过的元素索引
        }
        if(min == array.length) return new int[]{-1,-1};//如果没有元素交换说明不需要排序
        for(int i=copy.length-1;i>=0;i--){//从右向左插入排序
            int tmp = copy[i];
            int j = i + 1;
            boolean moveFlag = false;
            while(j < copy.length){
                if(copy[j]>=tmp){
                    break;
                }
                moveFlag = true;
                j++;
            }
            copy[i] = copy[j-1];
            copy[j-1] = tmp;
            if(moveFlag && j-1 > max) max = j-1;//如果有元素交换,记录最右边交换过的元素索引
        }
        return new int[]{min,max};
    }
}