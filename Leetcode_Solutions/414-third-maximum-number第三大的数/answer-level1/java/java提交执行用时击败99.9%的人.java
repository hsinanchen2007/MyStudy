 if (nums[i] == Integer.MIN_VALUE)
                flag = 1;
            if (nums[i] == maxNum || nums[i] == secondMaxNum || nums[i] == thirdMaxNum)
                continue;
            if (nums[i]>=maxNum)
            {
                thirdMaxNum = secondMaxNum;
                secondMaxNum = maxNum;
                maxNum = nums[i];
            }
            else if (nums[i]>secondMaxNum)
            {
                thirdMaxNum = secondMaxNum;
                secondMaxNum = nums[i];
            }
            else if (nums[i]>thirdMaxNum)
            {
                thirdMaxNum = nums[i];
            }
        }
        if(secondMaxNum == Integer.MIN_VALUE)
            return maxNum;
        if(thirdMaxNum == Integer.MIN_VALUE && flag == 0)
            return maxNum;
        return thirdMaxNum;