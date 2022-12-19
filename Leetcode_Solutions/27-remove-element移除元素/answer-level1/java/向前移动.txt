### 解题思路
`nums[j-1] = nums[j];`
只需要向前移动即可，不需要交换。


### 代码

```java
public class Solution {
    public int removeElement(int[] nums, int val) {
        int len = nums.length;
//        int num = 0;
        for(int i=0;i<len;){
            if(nums[i] == val){
//                num++;
                int j=i+1;
                while(j<len){// 最后一个需要考虑的元素是nums[j]所以j<len,边界条件有点难扣
                    nums[j-1] = nums[j];
                    j++;
                }
                len--;//没找到相等的一个，需要考虑的数组长度就减少1
                // 在找到相等之后，因为后面的元素整体向前移动了一个位置，所以i索引就不需要加1了
            }
            else{
                i++;
            }
        }
        return len;

    }

}

```