#### 步骤：
 输入：有序数组，使每个元素最多出现两次，输出移除后数组的新长度
 步骤：
 1. 创建指针i、j，i为慢指针，j为快指针，
 慢指针i用于指向最近已确定元素的位置，快指针j用于搜索下一个满足判断条件的元素位置，
 pre记录前一个已确定元素的值，
 state用于确定判断条件，当state为true时，判断条件为 >= ；当state为false时，判断条件为 <
 2. 初始化i=0，j=1，pre = nums[i] ，state = true（>=） ，
 3. 用快指针j遍历数组
 4. 根据state来确定判断条件（state为true >= state为false >），
 若满足（也就是快指针j找到符合条件的元素）i++，交换i，j位置上的值
 5. j++;
 6. 通过比较pre和nums[i]，来确定下一次的state，
 pre = nums[i]时，意味着已经有两个重复的确定元素，因此下一次state一定得是false（>）；
 pre < nums[i]时，意味着没有找到重复的确定元素，因此下一次state是true（>=），且pre该为最新的确定元素
 7. 直到快指针到达数组尽头，返回i+1
```
public int removeDuplicates(int[] nums) {
        if(nums.length == 0){
            return 0;
        }
        int i = 0;
        int j = 1;
        int pre = nums[i]; // 这里需要排空
        boolean state = true; // >=

        while(j < nums.length){
            if(state == true ? nums[j] >= nums[i] : nums[j] > nums[i]){
                i++;
                //交换值
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
            j++;
            //通过比较pre和nums[i]，来确定下一次的state
            if(pre == nums[i]){
                state = false;
            }else if(pre < nums[i]){
                pre = nums[i];
                state = true;
            }
        }
        return i+1;
    }
```
