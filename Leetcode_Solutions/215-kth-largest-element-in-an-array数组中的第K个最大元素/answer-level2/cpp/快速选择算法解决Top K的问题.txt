### 解题思路
时间复杂度：n
空间复杂度：2个指针，多个tmp值

算法思路参考博客 [link](https://blog.csdn.net/weixin_44038165/article/details/103093914)
1. 从开头讲起，随机选择一个pivot，将其移动至数组的尾端
2. 然后初始化两个指针，一个叫store_index，其值代表当前小于pivot的个数，在数组中，其左边的元素代表小于pivot的元数，其初始值为0；
3. 另一个指针j是用来遍历的，起点为store_index，终点为right-1。
4. 每次j的数值小于pivot的话，把j和store_index的值互换，store_index+=1，也就是把小于pivot的值放在store_index的左边，然后j继续遍历。
5. j从store_index到right-1的遍历结束后，把最终store_index的位置和right(也就是pivot)的位置呼唤，使得此时pivot左边的值都小于pivot，右边的值都大于pivot。
6. 然后判断top k_smallest与当前pivot位置的大小关系，若两者相等，则找到目标位置啦，若两者不等，则由其大小关系去判断是要选择pivot的左边还是右边部分继续前面的步骤直到找到目标位置。
### 代码

```cpp
class Solution { //最小堆的方法
public:
    int partition(int left, int right, int k_smallest, vector<int>& nums, int pivot_index){
        //首先把pivot_index放在最后的位置
        int pivot=nums[pivot_index];
        int tmp=nums[pivot_index];
        nums[pivot_index]=nums[right];
        nums[right]=tmp;

        //选定当前小于pivot的位置，记为i
        int i=left;
        for(int j=i;j<right;j++){
            if(nums[j]<pivot){
                int tmp=nums[j];
                nums[j]=nums[i];
                nums[i]=tmp;
                i+=1;
            }
        }
        tmp=nums[i];
        nums[i]=nums[right];
        nums[right]=tmp;
        return i;
    }

    int select(int left, int right, int k_smallest,vector<int>& nums){
        if(left==right){
            return nums[left];
        }

        int pivot_index = (rand() % (right-left+1))+ left;

        pivot_index = partition(left, right, k_smallest, nums, pivot_index);

        if(pivot_index==k_smallest){
            return nums[pivot_index];
        }else if(k_smallest>pivot_index){
            return select(pivot_index+1, right,k_smallest, nums);
        }
        else{
            return select(left,pivot_index-1, k_smallest, nums);
        }
    }

    int findKthLargest(vector<int>& nums, int k) {
        return select(0, nums.size()-1, nums.size()-k, nums);
    }
};
