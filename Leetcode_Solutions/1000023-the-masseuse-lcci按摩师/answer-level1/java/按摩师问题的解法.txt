### 解题思路
使用动态规划法求解该题，因为按摩师需要休息，所以其最多能服务的人数的个数为总人数的一半或者一半加一，因此最大的服务总长为该所有预约中时间最长的后 lestNums 位之和，使用二维数组hours[i][j]表示当前的最大总长时间，hours[i]的长度为maxHour（即排序后的数组的后lestNums个元素之和），当为第一个元素的时候，如果当前假设的最大服务总长大于当前元素，则加入当前元素的最大服务总长为当前元素的大小加上一最大服务总时长，即 hours[i][j]=  nums[i-1] + hours[i-1][j- nums[i-1]]; 否则直接复制上一元素的最大总服务时长hours[i][j]= hours[i-1][j]; ，当前假设的最大服务总长大于当前元素且 单前元素的大小加上加入前两位时（即未加入前一位元素时）的总服务时长大于加入前一位后的服务总时长，则当前最大的总服务时长为 单前元素的大小加上加入前两位时（即未加入前一位元素时）的总服务时长，其他情况直接复制上加入上一元素后的最大服务时长。

### 代码

```java
class Solution {
    public int massage(int[] nums) {

        int numsLen= nums.length;
        if (numsLen==0){
            return 0;
        }
        if (numsLen<2){
            return nums[0];
        }
        int[] numsSet=Arrays.copyOf(nums,numsLen);
        Arrays.sort(numsSet);
        int lestNums, maxHour=0;
        //当nums中的元素的数量为奇数时，取后一半加1，偶数时取一半
        if (numsLen % 2==0){
            lestNums = numsLen/2;
        }else {
            lestNums =numsLen / 2 +1;
        }
        //因为按摩师需要休息，所以其最多能服务的
        // 人数的个数为总人数的一半或者一半加一，
        // 因此最大的服务总长为该所有预约中时间最长的后 lestNums 位之和（即当每隔一位就遇到最大的 lestNums位中的元素）
        while (lestNums>0){
            maxHour+= numsSet[numsLen-lestNums];
            lestNums--;
        }

        int[][] hours= new int[numsLen+1][maxHour+1+1];  //

        for (int i=0 ; i< hours.length; i++){
            hours[i][0]= 0;
        }

        for (int j=0 ; j< hours[0].length; j++){
            hours[0][j]= 0;
        }

        for (int i=1; i<hours.length; i++){
            for (int j=1; j<hours[0].length; j++){
                if (i==1){
                    if (j>=nums[i-1]){
                        hours[i][j]=  nums[i-1] + hours[i-1][j- nums[i-1]];
                    }else {
                        hours[i][j]= hours[i-1][j];
                    }
                }else if(j>=nums[i-1] && hours[i-1][j]< nums[i-1] + hours[i-2][j- nums[i-1]]){
                        hours[i][j]=nums[i-1] + hours[i-2][j- nums[i-1]];
                }else {
                    hours[i][j]= hours[i-1][j];
                }
            }
        }


        return hours[hours.length-1][hours[0].length-1];
    }
}
```