   
    int solve1(int n) {
        int nCopy = n;

        if(n < 10) return n;
        vector<int> nums;
        int i = 0;
        while(n > 0) {
            nums.push_back(n % 10);
            cout<<"   "<<n%10; 
            n = n / 10;
        }
        
        int max = 0;
        vector<int> numsCopy = nums;
        int replace = 0;
        sort(numsCopy.begin(), numsCopy.end());
        int k = 0;
        for(k = nums.size() - 1; k >= 0;) {
            cout<<endl<<"  numsCopy[k]:  "<<numsCopy[k]<<endl;
            if(nums[k] == numsCopy[k]) {
                k--;
            }else{
                max = numsCopy[k];
                replace = k;
                break;
            }
        }
        if(k <= 0) {
            return nCopy;
        }
        cout<<endl<<"   max:  "<<max<<"   i: "<<replace<<endl;
        int ii = 0;
        for(ii = 0; ii < nums.size(); ++ii) {
            if(max == nums[ii]) {
                break;
            }
        }
        
        
        cout<<"   ii:  "<<ii<<endl;
        swap(nums[replace], nums[ii]);
        int res = 0;
        for(int j = nums.size() - 1; j >= 0; --j ) {
            cout<<"  j: "<<j<<"   nus[j]:  "<<nums[j]<<endl;
            res = res * 10 + nums[j];
        }
        cout<<"res:   "<<res<<endl;
        return res;
    }
