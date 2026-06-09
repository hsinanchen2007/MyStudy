思路：用nums2[i]与nums1中每一个元素逐一比较，如果比nums1中的某一元素小，则交换。最后将nums2拼接到nums1后面。
应将nums2中的数从大到小以此与nums1中的每个元素进行比较和交换操作，这样得到的nums2才能直接拼接到nums1后面。void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int t;
    if(n==0)return;
    for(int k=n-1;k>=0;k--)
    for(int i=0;i<m;i++){
        if(nums1[i]>nums2[k]){
            t=nums2[k];
            nums2[k]=nums1[i];
            nums1[i]=t;
        }
    }
    for(int i=0;i<n;i++){
        nums1[i+m]=nums2[i];
    }
    //for(auto x:nums1)cout<<x<<endl;
}



```
