for(int i=0;i<nums.size();++i){
            int num=count(nums.begin(),nums.end(),nums[i]);
            if(num==1){
                return nums[i];
            }
        }
        return 0;
直接用个count()，判断那个元素只出现一次，然后一个retrun就ok了。