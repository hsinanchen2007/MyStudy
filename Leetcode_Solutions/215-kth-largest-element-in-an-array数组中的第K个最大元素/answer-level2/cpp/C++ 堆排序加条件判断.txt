```
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        buildheap(nums,n);
        for(int i=n-1;i>=0;i--){
            swap(nums,0,i);
            k--;
            if(k==0){
                return nums[i];
            }
            heapadjust(nums,i,0);
        }
        return 0;
    }
    void buildheap(vector<int>& nums,int n)//初始堆
    {//结点与子结点关系，parent=i，lchild=2i+1,rchild=2i+2
        int parent=(n-2)/2;//最后一个非叶结点与总结点数的关系是,下标=(n-2)/2,n是总数
        for(int i=parent;i>=0;i--){//从最后一个非叶结点向前调整
            heapadjust(nums,n,i);
        }
        
    }
    void heapadjust(vector<int>& nums,int n,int i)//堆结构调整，保证大的在上，小的在下
    {//将父结点与孩子结点比较取大者，放到原父结点位置，这样交换的孩子结点数值会变，这个孩子结点当作下一层递归的父结点
    //继续与它的孩子结点比较，将这个分支上小的数一直往下移，大的数往上移
    //递归结束条件是当前的结点超过n，也就是上一层的结点没有孩子结点
        if(i>=n){
            return ;
        }
        int c1=2*i+1;
        int c2=2*i+2;
        int max=i;
        if(c1<n && nums[c1]>nums[max])//若有左子结点
            max=c1;
        if(c2<n && nums[c2]>nums[max])//若有右子结点
            max=c2;
        if(max!=i){
            swap(nums,i,max);
            heapadjust(nums,n,max);
        }
    }
    void swap(vector<int>&nums,int i, int max){//交换
        int temp=nums[i];
        nums[i]=nums[max];
        nums[max]=temp;
    }
};

```
