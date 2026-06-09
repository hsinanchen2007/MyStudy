本题的最大和比较好求，但是对应的下标集合不太好保存

首先要算出前缀和。

求最大和的思路：定义dp数组dp[len+1][4],dp[i][1]意义是以i为开头，len-1为结尾中1个长度为K的子数组的最大和
从尾部开始遍历数组，新来一个数nums[i]时 nums[i]~nums[i+k]总和为sum
1、如果i到len-1长度>=1  dp[i][1] = Math.max(dp[i+1][1],sum),表示i~len-1中1个k长度子数组最大值
2、如果i到len-1长度>=2  dp[i][2] = Math.max(dp[i+1][2],sum + dp[i+k][1])
3、如果i到len-1长度>=3  dp[i][3] = Math.max(dp[i+1][3],sum + dp[i+k][2])

下标保存，我只想到了这个笨方法，如代码所示，index[len+1][4][3],记录每次的最大值的下标
```
public int[] maxSumOfThreeSubarrays(int[] nums, int k) {
        int len = nums.length;
        int[][]dp = new int[len+1][4];
        int[][][] index = new int[len+1][4][3];
        int[] sum = new int[len];
        sum[0] = nums[0];
        for(int i=1 ; i<nums.length ; i++){
            sum[i] = sum[i-1] + nums[i];
        }


        for(int i=len-k ; i>=0 ; i--){
            int l = (len-i)/k;
            int num = sum[i+k-1]-sum[i]+nums[i];
            if(l>=1){
                if(num>=dp[i+1][1]){
                    index[i][1][0] = i;
                } else{
                    index[i][1][0] = index[i+1][1][0];
                }
                dp[i][1] = Math.max(dp[i+1][1],num);
            }
            if(l>=2){
                if(num + dp[i+k][1]>=dp[i+1][2]){
                    index[i][2][0] = i;
                    index[i][2][1] = index[i+k][1][0];
                } else{
                    index[i][2][0] = index[i+1][2][0];
                    index[i][2][1] = index[i+1][2][1];
                }
                dp[i][2] = Math.max(dp[i+1][2],num + dp[i+k][1]);
            }
            if(l>=3){
                if(num + dp[i+k][2]>=dp[i+1][3]){
                    index[i][3][0] = i;
                    index[i][3][1] = index[i+k][2][0];
                    index[i][3][2] = index[i+k][2][1];
                } else{
                    index[i][3][0] = index[i+1][3][0];
                    index[i][3][1] = index[i+1][3][1];
                    index[i][3][2] = index[i+1][3][2];
                }
                dp[i][3] = Math.max(dp[i+1][3],num + dp[i+k][2]);
            }
        }
        return index[0][3];
    }
```
