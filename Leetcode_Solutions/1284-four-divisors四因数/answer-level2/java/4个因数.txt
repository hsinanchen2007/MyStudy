### 解题思路


### 代码

```java
class Solution {
    public int sumFourDivisors(int[] nums) {
        int allSum = 0;//返回结果是一个int
        for(int i = 0; i<nums.length;i++){
            if(nums[i]<=5) continue; //不超过5的都是不行的，直接去掉
            int sum = 1+nums[i];
            ArrayList<Integer> yinshu = new ArrayList<>();
            boolean flag = isZheng((float)Math.sqrt(nums[i]));
            for(int j=2;j<=Math.sqrt(nums[i]);j++){ //感觉大于4的偶数j可以直接跳过忽略不计
                float result = (float)nums[i]/j;
                 boolean flag2 = isZheng(result);
                if(flag2&&!flag){
                    yinshu.add(nums[i]/j);
                    yinshu.add(j);
                    sum +=j;
                    sum+=nums[i]/j;
                }
               
            }
             if(yinshu.size()==2){
                allSum+=sum;
            }
        }

        return allSum;
    }

    boolean  isZheng(float num){
        int zheng = (int)num;
        if(zheng  == num){
            return true;
        }else{
            return false;
        }

    }

}
```