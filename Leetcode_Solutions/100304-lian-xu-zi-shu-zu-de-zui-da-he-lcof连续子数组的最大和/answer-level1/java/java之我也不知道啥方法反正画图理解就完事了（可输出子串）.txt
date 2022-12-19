如图，紫色为tmp的更新过程，红色为maxSum的更新过程，绿色的s为子串起始，e为子串结尾。
![IMG_0331.PNG](https://pic.leetcode-cn.com/91df5e4c8879cd512f073cc5c691066ef9460650294551bc215c5acb19e86497-IMG_0331.PNG)

**tmp更新规则：**
    1.tmp记录的是从s开始到当前的元素和。
    2.当(tmp+当前元素)<当前元素本身时，即可直接抛弃前面部分。将s指向当前元素。
**maxSum更新规则：**
    1.当tmp大于当前maxSum时即将maxSum更新。
    2.子串结尾e由maxSum所在位置决定。

代码如下（双100%）：
```
class Solution {
    public int maxSubArray(int[] nums) {
        int start = 0;
        int end = 0;
        int maxSum = nums[0];
        int tmp = 0;
        for(int i=0; i<nums.length; i++){
            tmp += nums[i];
            if(tmp<nums[i]){
                start = i;
                tmp = nums[i];
            }
            if(tmp>maxSum){
                maxSum = tmp;
                end = i;
            }
        }
        return maxSum;
    }
}
```
