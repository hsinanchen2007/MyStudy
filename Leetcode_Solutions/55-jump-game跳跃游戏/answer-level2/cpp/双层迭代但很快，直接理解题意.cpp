
直接检测所有0前面的数是否有超过间隔的，否则肯定是false
bool canJump(vector<int>& nums) {
        bool res = true;
        for (int i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                int j = 0;
                while(j < i){
                    if (nums[j] >(i - j)) break;
                    j++;
                }
                if (j >= i && i != nums.size()-1){//注意如果该0在最后一位则是可以的
                    res = false;
                    break;
                }
            }
        }
        return res;
    }