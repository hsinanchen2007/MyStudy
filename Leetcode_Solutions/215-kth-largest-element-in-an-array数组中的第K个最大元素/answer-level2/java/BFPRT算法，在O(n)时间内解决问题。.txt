
此算法可以在O(n)时间内找到第K大元素，同样在线性时间内找到中位数方法也出于此。用到的是递归的思想，时间复杂度具体的证明计算可以参考《算法导论》主方法部分。

class Solution {

    //算法接口
    public int findKthLargest(int[] nums, int k) {
        if (nums==null||k>nums.length||k==0)
            return 0;
        int position = BFPRT(0,nums.length-1,nums.length-k+1,nums);
        return nums[position];
    }

    //算法主入口
    private int BFPRT(int left,int right,int k,int[] array) {
        if (left>=right)
            return left;
        int pivotIndex = getPivotIndex(left,right,array);
        int mid = Partition(left,right,pivotIndex,array);
        int count =mid -left+1;
        if (count==k){
            return mid;
        }else if (count>k){
            return BFPRT(left,mid-1,k,array);
        }else{
            return BFPRT(mid + 1, right, k - count, array);
        }
    }

    //得到中位数
    private int getPivotIndex(int left,int right,int[] array){
        if ((right-left)<5) return insertSort(left,right,array);
        int back=left-1;
        for (int i=left;i+4<right;i+=5){
            int index =insertSort(i,i+4,array);
            Swap(array,++back,index);
        }
        return BFPRT(left,back,((back+left)>>1)+1,array);
    }

    //插入排序
    private int insertSort(int left,int right,int[] array){
        for (int i=left+1;i<right+1;i++){
            int temp = array[i];
            int j;
            for (j=i;j>left&&array[j-1]>temp;j--)
                array[j]=array[j-1];
            array[j]=temp;
        }
        return (right+left)>>1;
    }

    //交换
    private void Swap(int[] nums,int a, int b){
        int temp = nums[a];
        nums[a]=nums[b];
        nums[b]=temp;
        return;
    }

    //划分
    private int Partition(int left,int right,int index,int[] array){
        Swap(array,right,index);
        int position=left;
        for(int i=left;i<right;i++){
            if(array[i]<array[right])
                Swap(array,i,position++);
        }
        Swap(array,right,position);
        return position;
    }

    public static void main(String[] args) {
        Solution solution =new Solution();
        System.out.println(solution.findKthLargest(new int[]{3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,11,5,6,2,4,7,8,5,6},2));
    }
}