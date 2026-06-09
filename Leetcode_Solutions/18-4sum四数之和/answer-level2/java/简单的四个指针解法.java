### 解题思路
由于本题有四个数，将采用四个指针，使用3重嵌套循环，每次指针循环时都检查是否与前一个数相同，再以该指针以及前面的指针为基，循环查找是否有符号要求的四个数，我写的时候发现到最后两个指针前，每一阶循环的操作都大致相同，进而能用递归实现，但是我递归用的不熟悉，有时间再看看大佬的递归解法，进而可以做n个数之和的题目。

### 代码

```java
class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if(nums == null || nums.length < 4)
            return result;

        Arrays.sort(nums);
        //采用四个指针
        int k, i, j, h;
        //以k点为起点得出最大值最小值
        for(k = 0; k < nums.length-3; k ++){
            //去重处理
            if(k > 0 && nums[k] == nums[k-1])
                continue;
            i = k + 1;
            h = nums.length -1;

            //若最小值都大于了目标值，循环下去就没有意义
            int min = nums[k] + nums[i] + nums[i + 1] + nums[i + 2];
            if(min > target) break;

            //若最大值都小于了目标值，说明k所指的数不够大，结束本次循环，向右移动一位继续循环
            int max = nums[k] + nums[h] + nums[h - 1] + nums[h - 2];
            if(max < target) continue;

            //以k, i为起点，得出最小最大值
            for(i = k + 1; i < nums.length -2; i ++){
                //去重处理
                if(i > k + 1 && nums[i] == nums[i -1]) continue;
                j = i + 1;
                h = nums.length - 1;
                //若最小值都大于了目标值，循环下去就没有意义
                min = nums[k] + nums[i] + nums[j] + nums[j + 1];
                if(min > target) break;
                //若最大值都小于了目标值，说明i所指的数不够大，结束本次循环，向右移动一位继续循环
                max = nums[k] + nums[i] + nums[h] + nums[h - 1];
                if(max < target) continue;
                //来到最后两个指针的环节
                while(j < h){
                    //去重处理
                    if(j > i + 1 && nums[j] == nums[j - 1]){
                        j ++;
                        continue;
                    }

                    if(h < nums.length - 1  && nums[h] == nums[h + 1]){
                        h --;
                        continue;
                    }
                    int sum = nums[k] + nums[i] + nums[j] + nums[h];
                    if(sum > target){
                        h --;
                        continue;
                    }
                    else if(sum < target){
                        j ++;
                        continue;
                    }
                    else{
                        result.add(Arrays.asList(nums[k], nums[i], nums[j], nums[h]));
                        j ++;
                        h --;
                    }
                }
            }
        }
        return result;
    }
}
```