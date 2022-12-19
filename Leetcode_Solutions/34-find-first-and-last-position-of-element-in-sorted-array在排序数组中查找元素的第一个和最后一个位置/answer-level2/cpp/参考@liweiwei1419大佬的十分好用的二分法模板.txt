    vector<int> searchRange(vector<int>& nums, int target) {

        if(nums.size() == 0 || nums[0] > target || nums[nums.size()-1] < target)
                return vector<int>({-1,-1});
        
        int fisrtPos = Find_First_Pos(nums,target);
         
         if(fisrtPos == -1)
            return {-1,-1};

         int lastPos = Find_Last_Pos(nums,target);
            return vector<int>({fisrtPos,lastPos});
    }

    //往右逼近 
    int Find_First_Pos(vector<int>& nums,int target)
    {
        int left = 0,right = nums.size() - 1;

        while(left < right)
        {
            int mid = left+((right -left) >> 1); //mid在左边区间 所以取左半边数

            if(nums[mid] < target)  //收缩左边
                left  = mid + 1;
            else
                right = mid;
        } 

        //可能不存在 所以需要判断
        return nums[left] == target ? left : -1;
    }

    //往左逼近
    int Find_Last_Pos(vector<int>& nums,int target)
    {
        int left = 0,right = nums.size() - 1;

        while(left < right)
        {
            int mid = left+((right-left+1) >> 1);   //mid在右边区间 所以取右半边数

            if(nums[mid] > target) //收缩右边
                right = mid - 1;
            else
                left = mid;
        }
        //可能不存在 所以需要判断
        return nums[left] == target ? left : -1;
    }

链接:https://leetcode-cn.com/problems/search-insert-position/solution/te-bie-hao-yong-de-er-fen-cha-fa-fa-mo-ban-python-/
