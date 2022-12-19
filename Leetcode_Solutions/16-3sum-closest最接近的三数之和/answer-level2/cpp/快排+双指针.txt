执行用时 :8 ms, 在所有 cpp 提交中击败了92.29%的用户
内存消耗 :8.9 MB, 在所有 cpp 提交中击败了71.57%的用户

几乎和15题一摸一样

    void quickSort(vector<int>& nums,int l,int r){
        if(l>=r){
            return ;
        }
        int i=l,j=r,key=nums[l];
        while(i<j){
            while(i<j&&nums[j]>=key){
                j--;
            }
            nums[i]=nums[j];
            while(i<j&&nums[i]<=key){
                i++;
            }
            nums[j]=nums[i];
        }
        nums[i]=key;
        quickSort(nums,l,i-1);
        quickSort(nums,i+1,r);
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int i,l,r,result,sum;
        quickSort(nums,0,nums.size()-1);
        result=nums[0]+nums[1]+nums[2];
        for(i=0;i<nums.size()-2;i++){
            for(l=i+1,r=nums.size()-1;l<r;){
                sum=nums[i]+nums[l]+nums[r];
                if(abs(sum-target)<abs(result-target)){
                    result=sum;
                }
                if(sum<target){
                    l++;
                }
                else if(sum>target){
                    r--;
                }
                else{
                    return result;
                }
            }
        }
        return result;
    }