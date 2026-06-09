```

public int[] decompressRLElist(int[] nums) {
        if(nums.length % 2 != 0){
            return new int[]{};
        }
        int size = 0;
        for(int i = 0 ; i < nums.length ; i = i+2){
            size += nums[i];
        }

        int[] array = new int[size];
        int count = 0;
        int num = 0;
        int index = 0;
        for(int i = 0; i < nums.length; i++){
            if(i % 2 == 0){
                count = nums[i];
            }else{
                num = nums[i];
                for(int j = 0 ; j < count ; j++){
                    array[index++] = num;
                }
            }
        }

        return array;
    }
```
先算size，再遍历赋值
