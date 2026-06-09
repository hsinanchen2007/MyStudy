由于两个数组严格增序，故可循环比较两数组的左边值，而且不需要比完，一旦指到了中位值的位置，就可以中止了。```
```
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n_1 = nums1.size();
    int n_2 = nums2.size();
    vector<int> dp(n_1+n_2,0);
    int judge = (n_1+n_2) % 2;
    int i=0,j=0,k=0;
    double mid=0;
    int tag = 0;            //用于判断是否已经找到了中位值所在位置
    while(i<n_1 && j<n_2){
        if(nums1[i]<nums2[j]){
            dp[k] = nums1[i];
            ++i;
        }
        else{
            dp[k] = nums2[j];
            ++j;
        }
        if(k==(n_1+n_2)/2){
            tag=1;  
            break;
        }
        ++k;
    }
    while(tag==0 && j<n_2){
        dp[k] = nums2[j];
        if(k==(n_1+n_2)/2){
            tag=1;  
            break;
        }
        ++k,++j;
    }
    while(tag==0 && i<n_1){
        dp[k] = nums1[i];
        if(k==(n_1+n_2)/2){  
            break;
        }
        ++k,++i;
    }
    if(judge==0) mid=(double(dp[k-1])+double(dp[k]))/2;
    else mid = double(dp[k]);
    return mid;
}
```

