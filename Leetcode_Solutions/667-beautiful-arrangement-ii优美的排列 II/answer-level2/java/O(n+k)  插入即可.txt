```
    public int[] constructArray(int n, int k) {
        int[] nums = new int[n];
        for(int i=0;i<n;++i){
            nums[i]=i+1;
        }
        int s = k+1;   //插入数字的大小
        int c = s;
        for(int i=0,j=1;i<c;i++){
            if((i+1)%2==1) nums[i]=j++;
            else nums[i] = s--;
        }
       return nums;
    }
```
