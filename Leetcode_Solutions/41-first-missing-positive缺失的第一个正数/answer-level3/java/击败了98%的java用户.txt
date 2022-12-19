### 分析
以[3,5,-1,1]为例，整个过程分两步
第一步：将数据放到他本来应该在的位置，即nums[i]=i+1,
    1、对于 nums[0] = 3，需要将其放到第三个位置，即nums[2]的位置，因此调换nums[0]和nums[2]，数组变为[-1,5,3,1]。
    然后nums[0] = -1,我们最后需要找的是缺失的第一个正数，因此-1这种可以直接舍弃，本轮循环结束，进入下一轮。
    2、对于nums[1] = 5，因为数组的长度为4，因此，缺失的第一个正整数肯定小于5，因此5这种可以直接舍弃，本轮循环结束，进入下一轮。
    3、对于nums[2] = 3,这个位置不需要进行调换，因为3现在正好在第三个位置，不需要调换。
    4、对于nums[3] = 1,需要将其放到第一个位置，即nums[0]的位置，因此调换nums[0]和nums[3]，数组变为[1,5,3,-1]。
  第二步：遍历数组，如果哪个位置nums[i]!=i+1,则他就是缺失的数。很明显[1,5,3,-1]缺失的第一个正整数为2
###   代码
```java
public int firstMissingPositive(int[] nums) {
        if(nums == null || nums.length == 0){
            return 1;
        }
        int len = nums.length;
        for (int i = 0; i < len ; i++) {
            while (nums[i] >0 && nums[i] <= len && nums[i]!=nums[nums[i]-1]){
                swap(nums,i,nums[i]-1);
            }
        }
        int i = 0;

        for (; i < len; i++) {
            if(nums[i] != i+1){
                break;
            }
        }

        return i+1;
    }

    private void swap(int[] nums,int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
```