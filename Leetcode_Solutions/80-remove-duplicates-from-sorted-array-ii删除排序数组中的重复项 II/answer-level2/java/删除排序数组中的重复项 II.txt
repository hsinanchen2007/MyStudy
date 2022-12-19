```
import java.util.*;

class Solution {
    public int removeDuplicates(int[] nums) {
        if(nums == null || nums.length ==0)
            return 0;
        //操作之后的数的长度，默认长度为数组的长度
        int result = nums.length;
        //对数组遍历操作时的数组下标
        int cur = 0;
        //对于cur前一个不为空的数组元素出现的频率
        int fre = 0;
        //min的值是数组最小值减一，当数组元素为min时，表示该位置为空
        int min = nums[0] - 1;
        //对于cur而言的前一个不为空的数组下标
        int pre = -1;
        //need表示第一次出现空的数组下标，need==-1表示没有出现空位置
        int need = -1;
        while(cur < nums.length) {
            //对fre，pre，进行更新，对一个数出现大于三次进行操作（使其出现的最后的那个位置变为空）
            if(cur == 0 || nums[cur] != nums[pre]) {
                pre = cur;
                fre = 1;
            }else {
                if(fre == 2) {
                    nums[cur] = min;
                }else {
                    fre++;
                    pre = cur;
                }
            }
            //当第一次出现空位置，need更新
            if(nums[cur] == min && need == -1) {
                need = cur;
            }
            //当出现值不为空且之前有空位置，那么需要将值填充到最先的空位置，cur位置变为空
            //如果空位置不唯一，那么need+1也是空位置
            //如果空位置唯一，那么cur=need+1,所以need+1也是空位置
            else if(nums[cur] != min && need != -1) {
                nums[need] = nums[cur];
                nums[cur] = min;
                pre = need;
                need++;
            }
            cur++;
        }
        //最后的数的长度，即最后最先出先空位置的下标，也就是最后need的值
        if(need != -1)
            result = need;
        return result;
    }
}
```
![截屏2020-01-16下午3.40.06.png](https://pic.leetcode-cn.com/3baae73d85aa4fcf839230388e1467fb6cb0d64c8493e363ab9b3dd972e8d011-%E6%88%AA%E5%B1%8F2020-01-16%E4%B8%8B%E5%8D%883.40.06.png)

