官方快速排序说复杂了，好晕，看不懂！ 自己摸索解释一下：不知道对不对，请大神们指点，谢谢！
1。快速排序一次，检查中轴p
2。p>(n - k) 快排中轴左边
3。p<(n - k) 快排中轴右边
4。递归 直到 p=(n - k)
返回 nums[n-k];第[n-k]个元素，
完事。不知道理解是不是对

int findKthLargest(vector<int>& nums, int k) {
#if 1  //解法一，用快速排序，检查 下标为n-K则为结果 
     if(nums.size() == 0) {return -1;}
     if(k > nums.size()) {return -1;}

     quickSort(nums,0,nums.size()-1,k);
     return nums[nums.size()-k];
#endif 
    }
private:
    //快排递归方法
    void quickSort(vector<int> & nums,int left,int right ,int k)
    {
        if(left>=right)
        {
            return;
        }
        int index = quickSortOnece(nums,left,right);
        if(index == (nums.size() - k))
        {
            return ;
        }
        else if(index > (nums.size() - k))  
        {
            quickSort(nums,left,index-1,k);
        }
        else
        {
            quickSort(nums,index+1,right,k);
        }
    }
    int quickSortOnece(vector<int> &nums,int left,int right)  //快排一次
    {
        int grant = nums[left]; //选取哨兵
        bool hasChange = false;
        while(left < right)
        {
            while(nums[right] > grant && right > left){right--;}
            if(right > left)
            {
                nums[left++] = nums[right];
                hasChange = true;
            }
            while(nums[left] < grant && left<right) {left++;}
            if(left < right)
            {
                nums[right--] = nums[left]; 
                hasChange = true;
            }
            if(hasChange)
            {
                nums[left] = grant;
            }
        }
        return left;
    }