class Solution {
    public List<Integer> sortArray(int[] nums) {
        int size=nums.length;
        int index=0;
        int start=(size-1)/2;
        for(int i=start;i>=0;i--){
            MaxHeap(nums,size-1,i);
        }
        for(int i=size-1;i>0;i--){
            int temp=nums[0];
            nums[0]=nums[i];
            nums[i]=temp;
            MaxHeap(nums,i,0);
        }
        List<Integer> list=new ArrayList<>();
        for(Integer num:nums){
            list.add(num);
        }
        return list;
    }
    public void MaxHeap(int[] nums,int size,int index){
        int leftNode=2*index+1;
        int rightNode=2*index+2;
        int max=index;
        if(leftNode<size&&nums[leftNode]>nums[max]){
            max=leftNode;
        }
        if(rightNode<size&&nums[rightNode]>nums[max]){
            max=rightNode;
        }
        if(max!=index){
            int temp=nums[index];
            nums[index]=nums[max];
            nums[max]=temp;
            MaxHeap(nums,size,max);
        }
    }
}