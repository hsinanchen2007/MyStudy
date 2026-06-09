### 解题思路
双指针，一个zero指向队首，一个two指向队尾。
当nums[i]==1，跳过
当nums[i]==2的时候，将two队尾指针向前挪动一位，之后将nums[two]与nums[i]交换值，在判断此时nums[i]的值
当nums[i]==0的时候，将zero向后移动一位，将nums[i]与nums[zero]交换后i++;此时无需判断nums[i]的值了

### 代码

```java
class Solution {
    public  void sortColors(int[] nums) {
      int zero= -1;
        int two=nums.length;
        for (int i = 0; i <two ; ) {
            if (nums[i]==1)
                i++;
            else  if (nums[i]==2){
                --two;
                int z =nums[i];
                nums[i] = nums[two];
                nums[two] = z;
            }else {
                zero++;
                int z =nums[zero];
                nums[zero] = nums[i];
                nums[i] = z;
                i++;
            }
        }
    }

}
```