执行用时 :128 ms, 在所有 cpp 提交中击败了84.38%的用户
内存消耗 :14.5 MB, 在所有 cpp 提交中击败了94.66%的用户

    void siftdown(vector<int>& nums,int i,int n){
        int j,temp=nums[i];
        while((j=2*i+1)<n){
            if(j<n-1&&nums[j]<nums[j+1]){
                j++;
            }
            if(temp<nums[j]){
                nums[i]=nums[j];
                i=j;
            }
            else{
                break;
            }
            nums[i]=temp;
        }
    }
    void heapSort(vector<int>& nums){
        int i,temp;
        for(i=(nums.size()-2)/2;i>=0;i--){
            siftdown(nums,i,nums.size());
        }
        for(i=nums.size()-1;i>0;i--){
            temp=nums[0];
            nums[0]=nums[i];
            nums[i]=temp;
            siftdown(nums,0,i);
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> temp;
        temp.resize(3);
        int sum,i,j,k;
        if(nums.size()<3){
            return result;
        }
        heapSort(nums);
        for(k=0;k<nums.size()-2;k++){
            if(nums[k]>0){
                break;
            }
            if(k>0&&nums[k]==nums[k-1]){
                continue;
            }
            i=k+1;
            j=nums.size()-1;
            while(i<j){
                sum=nums[k]+nums[i]+nums[j];
                if(sum<0){
                    while(i<j&&nums[i]==nums[++i]){
                        ;
                    }
                }
                else if(sum>0){
                    while(i<j&&nums[j]==nums[--j]){
                        ;
                    }
                }
                else{
                    temp[0]=nums[k];
                    temp[1]=nums[i];
                    temp[2]=nums[j];
                    result.push_back(temp);
                    while(i<j&&nums[i]==nums[++i]){
                        ;
                    }
                    while(i<j&&nums[j]==nums[--j]){
                        ;
                    }
                }
            }
        }
        return result;
    }