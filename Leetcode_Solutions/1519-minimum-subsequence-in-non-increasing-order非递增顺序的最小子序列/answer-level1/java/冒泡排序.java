### 解题思路
此处撰写解题思路
1.冒泡排序 由大到小
2.循环  依次比较 是否大于剩余值。若大于返回；否则，与下一个相加，继续比较。
### 代码

```java
class Solution {
    public List<Integer> minSubsequence(int[] nums) {
        List<Integer> reslutSort = new ArrayList<>();
        int[] sort = new int[nums.length];
        for (int i = 0; i < nums.length; i++) {
            sort[i] = i;
        }
        //改进 排序时计算出 总和
        int overSum = 0;
        //排序 从大到小
        for (int i = 0; i < nums.length; i++) {
            overSum += nums[i];
            for (int j = i; j < nums.length; j++) {
                if (nums[sort[i]] < nums[sort[j]]) {
                    int tmp = sort[i];
                    sort[i] = sort[j];
                    sort[j] = tmp;
                }
            }
        }

        //判断前几个相加是否 大于剩余的
        int sum = 0;
        for (int i = 0; i < nums.length; i++) {
            reslutSort.add(nums[sort[i]]);
            sum = sum + nums[sort[i]];
            int endSum = 0;
            //前几个相加  > 剩余和
            if(sum > overSum - sum){
                break;
            }
//            for (int j = i + 1; j < nums.length; j++) {
//                endSum = endSum + nums[sort[j]];
//            }
//            if (sum > endSum) {
//                break;
//            }
        }


        return reslutSort;
    }
}
```