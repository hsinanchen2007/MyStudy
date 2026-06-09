最直观易懂的写法
```
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2) return 0;
        return mergeSort(nums,0,nums.size());
    }
    int mergeSort(vector<int>& nums,int sta,int end){
        if(end-sta<=1) return 0;
        int mid = (sta+end)/2;
        int cot = mergeSort(nums,sta,mid)+mergeSort(nums,mid,end);
        for (size_t i = sta; i < mid; i++)
        {
            int pos = lower_bound(nums.begin()+mid,nums.begin()+end,nums[i]/2.0)-nums.begin();
            cot += pos - mid;
        }
        inplace_merge(nums.begin()+sta,nums.begin()+mid,nums.begin()+end);
        return cot;
    }
```
简单优化
```
    int *aux;
    int reversePairs(vector<int>& nums) {
        if(nums.size()<2) return 0;
        aux = new int[nums.size()];
        return mergeSort(nums,0,nums.size());
    }
    int mergeSort(vector<int>& nums,int sta,int end){
        if(end-sta<=1) return 0;
        int mid = (sta+end)/2;
        int cot = mergeSort(nums,sta,mid)+mergeSort(nums,mid,end);
        for (size_t i = sta; i < mid; i++)
        {
            int pos = lower_bound(nums.begin()+mid,nums.begin()+end,nums[i]/2.0)-nums.begin();
            cot += pos - mid;
        }
        //采用自己的归并替代inplace_merge减少临时数组的分配与释放
        //当数组已有序就不归并
        if(nums[mid-1]>nums[mid])   
            merge(nums,sta,mid-1,end-1);
        // inplace_merge(nums.begin()+sta,nums.begin()+mid,nums.begin()+end);
        return cot;
    }
    void merge(vector<int>& a,int lo,int mid,int hi){
        for (size_t i = lo; i <=hi; i++)
            aux[i] = a[i];

        int j=lo,k=mid+1;
        for (size_t i = lo; i <=hi; i++)
        {
            if(j>mid)               a[i]=aux[k++];
            else if(k>hi)           a[i]=aux[j++];
            else if(aux[k]<aux[j])  a[i]=aux[k++];
            else                    a[i]=aux[j++];
        }
    }
```
