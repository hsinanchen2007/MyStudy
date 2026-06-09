执行用时 :8 ms, 在所有 cpp 提交中击败了99.71%的用户
内存消耗 :9.1 MB, 在所有 cpp 提交中击败了86.89%的用户

    void quickSort(vector<int>& nums,int l,int r){
        if(l>=r){
            return;
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
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if(nums.size()<4){
            return {};
        }
        vector<vector<int>> result;
        int a,b,c,d,t,n=nums.size();
        quickSort(nums,0,n-1);
        int max3=nums[n-1]+nums[n-2]+nums[n-3];
        int max2=nums[n-1]+nums[n-2];
        for(a=0;a<n-3;a++){
            if(nums[a]*4>target){
                break;
            }
            if((a>0&&nums[a]==nums[a-1])||nums[a]+max3<target){
                continue;
            }
            for(b=a+1;b<n-2;b++){
                if((nums[a]+nums[b])*2>target){
                    break;
                }
                if((b>a+1&&nums[b]==nums[b-1])||nums[a]+nums[b]+max2<target){
                    continue;
                }
                for(c=b+1,d=n-1,t=target-nums[a]-nums[b];c<d;){
                    if(nums[c]+nums[d]<t){
                        c++;
                    }
                    else if(nums[c]+nums[d]>t){
                        d--;
                    }
                    else{
                        result.push_back({nums[a],nums[b],nums[c],nums[d]});
                        while(c<d&&nums[c]==nums[++c]){
                            ;
                        }
                        while(c<d&&nums[d]==nums[--d]){
                            ;
                        }
                    }
                }
            }
        }
        return result;
    }