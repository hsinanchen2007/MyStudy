- 个人认为这是一道索引绑定的题目，使用哈希表来保存score和rank是可以的，这里介绍一种不使用额外空间的算法。
- 在原数组的基础基础上，将每个score乘数组的长度len之后加上索引，以保证既保留了索引信息，又避免了索引信息对score排名的影响。
- 代码实现
``` java
public static String[] solution(int[] nums){
        int len = nums.length;
        for(int i =0;i<len;i++){
            nums[i] = nums[i]*len +i;
        }
        Arrays.sort(nums);
        String[] ans = new String[len];
        for(int i =0;i<len;i++){
            int rank = len-i;
            int index = nums[i]%len;
            if(rank==1){
                ans[index] = "Gold Medal";
            }else if(rank==2){
                ans[index] = "Silver Medal";
            }else if(rank==3){
                ans[index] = "Bronze Medal";
            }else {
                ans[index] = String.valueOf(rank);
            }
        }
        return ans;
    }
```