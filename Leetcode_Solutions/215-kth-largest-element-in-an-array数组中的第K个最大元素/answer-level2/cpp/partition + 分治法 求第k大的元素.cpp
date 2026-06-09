    

    public:
    //函数作用：pivot左边的元素都比它小，右边的元素都比它大，返回pivot的实际位置
    //思想：双指针法，不用swap函数交换多次
    int partition(vector<int>& nums, int begin, int end)
    {
        int pivot = nums[begin];//第一个元素作为枢轴
        while(begin < end)
        {
            while(begin < end && nums[end] >= pivot)
                end--;
            nums[begin] = nums[end];//尾部找到了小于pivot的元素，换到头部
            while(begin < end && nums[begin] <= pivot)
                begin++;
            nums[end] = nums[begin];//头部找到大于pivot的元素，换到尾部
        }
        nums[begin] = pivot;//枢轴回到中间
        return begin;
    }
    public:
    int findKthLargest(vector<int>& nums, int k) {
        //采用partition找目标元素，总体分治法求解
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int target = len - k;//从小到大排序，倒数第k元素的索引是len-k
        
        while(true)
        {
            int index = partition(nums, left, right);//相当于排序后数组的index位置
            if (index == target) //恰好是目标元素的位置，即找到了目标元素
                return nums[index];
            else if(index < target) //比目标元素的位置靠前，向后二分
                left = index + 1;
            else if(index > target) //比目标元素的位置靠后，向前二分
                right = index - 1;
        }
        return -1;
    }