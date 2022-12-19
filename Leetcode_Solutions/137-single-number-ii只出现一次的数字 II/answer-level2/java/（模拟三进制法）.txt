   public int singleNumber(int[] nums){
        if(nums==null) return -1;
        else if(nums.length<=1) return nums[0];
        else{
            int length=nums.length-1;
            int ones=0,twos=0,threes=0;
            for (int i = 0; i <=length ; i++) {
                /*
                *   首先我们先说明不可能出现twos本来是1，然后ones也是1，nums也是1的情况是不肯出现的
                *   因为从一开都是零，只要出现twos和ones是1的位都会被消除为0
                *   所有ones和twos在同一位上不可能同时为1
                *   所以 twos=（ones&num[i])|twos;是可以确认该位只能是2次，而不会是四次
                *   存在一次则是ones=ones^num[i] 保证该位当前出现了一次
                *   获得出现三次的位 threes
                *   只要没出现三次的位我都保留它
                *
                *   最后返回出现了一次的位所表示的数
                *  
                *
                * */
                twos=(ones&nums[i])|twos;
                ones=ones^nums[i];
                threes=ones&twos;
                ones=(~threes)&ones;
                twos=(~threes)&twos;

            }
            return ones;
        }

    }