直接上代码。
        //判断数组是否为空
        if(nums1.length == 0 && nums2.length == 0){
            return 0;
        }else{
            //声明一个全新的数组，用于存放俩个数组
            int[] nums = new int[nums1.length+nums2.length];
            //工具类，参数分别为，数组对象，开始下标，目标对象，从该下标开始赋值，复制长度
            System.arraycopy(nums1,0,nums,0,nums1.length);
            System.arraycopy(nums2,0,nums,nums1.length,nums2.length);
            //工具类，进行数组排序，从小到大
            Arrays.sort(nums);

            int size = nums.length;
            //判断该数组是奇数，还是偶数
            if(size % 2 == 1){
                size ++; 
                return nums[size/2 - 1];
            }else{
                size /= 2;
                return (nums[size - 1]+nums[size])/(double)2;
            }
        }