public static int search(int[] nums, int target) {
        int temp=nums[nums.length-1];
        int i=0;
       //找到反转了几个元素
        while(nums[i]>temp){
            i++;
        }
        int start=0,end=nums.length-1;
        //在翻转后的前半部分查找
        if(target>temp){
            start=0;
           end=i-1;

        //在翻转后数组的后半部分查找
        }else{
            start=i;
            end=nums.length-1;


        }
        int re=find(nums,start,end,target);
        return re;

    }

    //二分法查找元素位置 
     public static int find(int[] nums,int start,int end,int target){
        while(start<=end){
            int mid=(start+end)/2;
            if(nums[mid]==target){
                return mid;
            }else if(nums[mid]>target){
                end=mid-1;
            }else{
                start=mid+1;
            }
        }
        return -1;

    }