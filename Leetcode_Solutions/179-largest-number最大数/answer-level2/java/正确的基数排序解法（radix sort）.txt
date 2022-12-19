```
public String largestNumber(int[] nums) {
        if (nums.length == 1) {
            return nums[0] + "";
        }
        StringBuilder res = new StringBuilder();
        //find max length of nums[i]
        int maxLength = 1;
        for (int i = 0; i < nums.length; i++) {
            maxLength = Math.max(maxLength,String.valueOf(nums[i]).length());
        }

        int[] digitArr = new int[10];
        int[] sortedNums = new int[nums.length];
        while (maxLength-- > 0) {
            for (int j = 0; j < nums.length; j++) {
                int numberByIndex = getNumberByIndex(nums[j], maxLength);
                digitArr[numberByIndex]++;
            }
            //stable count sort
            for (int j = digitArr.length-2; j >= 0; j--) {
                digitArr[j] += digitArr[j+1];
            }

            for (int j = nums.length-1; j >= 0; j--) {
                sortedNums[--digitArr[getNumberByIndex(nums[j], maxLength)]] = nums[j];
            }
//            nums = sortedNums.clone();
            System.arraycopy(sortedNums,0,nums,0,nums.length);
            for (int j = 0; j < digitArr.length; j++) {
                digitArr[j] = 0;
            }
        }
        for (int i = 0; i < nums.length; i++) {
            res.append(nums[i]);
        }
        return res.toString().startsWith("0") ? "0" : res.toString();
    }

    private int getNumberByIndex(int num,int index) {
        int numLen = String.valueOf(num).length();
        if (index < numLen) {
            return Integer.parseInt(String.valueOf(num).charAt(index) + "");
        }else {
            //if the index is illegal,return the max number
            int max = Integer.parseInt(String.valueOf(num).charAt(0) + "");
            int idx = 0;
            while (idx < String.valueOf(num).length()) {
                max = Math.max(Integer.parseInt(String.valueOf(num).charAt(idx) + ""),max);
                idx++;
            }
            return max;
        }
    }
```
