## 解析
分两步 第一步：将数据放到他本来应该在的位置，即nums[i]=i+1,
第二步：遍历数组，如果哪个位置nums[i]!=i+1,则他就是缺失的数。
## 代码
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