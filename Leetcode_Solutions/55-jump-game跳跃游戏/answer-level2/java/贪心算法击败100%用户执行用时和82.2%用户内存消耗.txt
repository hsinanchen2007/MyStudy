思路：依次找到跳跃距离为0的元素们，然后看它前面是否存在可以跳过0元素位置的元素即可
Ps:边界上注意考虑第一位为0和最后一位为0的情况
效果：
执行用时 :1 ms, 在所有 java 提交中击败了 100.00%的用户
内存消耗 :40.7 MB, 在所有 java 提交中击败了82.22%的用户
```

public static boolean canJump(int[] nums){
        assert nums.length>0;
        if(nums.length==1)return true;
        //数组首位为0且0不是唯一元素肯定跳不到最后
        if(nums.length>1&&nums[0]==0)return false;

        for (int i = 1; i < nums.length-1; i++) {
            int j = i - 1; //设置一个j标志往num[i]前找能跳到第i个位置的nums[j]
            while (nums[i] == 0) {
               //找到让这个0元素可以被到达或跳过的j位置
                if (nums[j] > i - j) break;
                //找不到能跳过0的元素位了
                if (j <= 0) return false;
                j--;
            }
        }
        return true;
    }
```
该方法最坏情况为O（n^2）,平均情况是O（NlogN）


