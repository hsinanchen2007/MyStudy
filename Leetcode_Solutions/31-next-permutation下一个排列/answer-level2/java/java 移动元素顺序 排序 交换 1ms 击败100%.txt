解题思路
    1.要找下一位排序,大数字尽可能不往高位移动
    2.要找比当前元素大的元素最小的元素交换
    3.交换过元素以后,后面的元素进行排序
    4.完成步骤以后即可跳出程序

    5.如果没有跳出程序,则说明没有最没有比当前顺序更大的数,将数组倒置
```
/**
     * 解题思路
     *     大数字替换到高位,数字值就会越大,因此,要想办法把大数字替换到低位
     *  1.从倒数第二个元素开始,往本元素后面找出比本元素大,且是比本元素大的元素中最小的一个元素,交换这两个元素的位置,剩余的元素做排序,自增即可
     * @param nums
     */
    public void nextPermutation(int[] nums) {
        if (nums.length < 2)
            return;
        //从倒数第二个元素开始
        for (int i = nums.length-2; i >=0 ; i--) {
            //比当前元素大,且是这些元素中的最小值的元素的位置(大于当前元素的最小值的下标)
            int tempIndex = -1;
            //从当前元素往后找 tempIndex
            for (int j = i+1 ; j < nums.length; j++) {
                if (nums[i] < nums[j] ){//比当前元素大
                    if (tempIndex == -1){//如果还没有判断过,则赋值
                        tempIndex = j;
                    }else{//比当前元素大,切之前也有过比当前元素的的元素,比较两个元素的最小值
                        if (nums[j] < nums[tempIndex]){
                            //取两个大元素的最小值的下标
                            tempIndex = j;
                        }
                    }
                }
            }
            //如果没发现了比当前元素大的元素的最小值对应的下标
            if (tempIndex != -1){
                if (nums[i] < nums[tempIndex]){
                    //交换两个元素的位置
                    swap(nums,i,tempIndex);
                    //剩余的元素按照从小到大的顺序排序
                    sortArray(nums,i+1);
                    return;
                }
            }
        }

        //如果数组元素顺序没有发生变化,则说明不存在下一个元素,反转数组的顺序
        int left = 0;
        int right = nums.length-1;
        while (left < right){
            swap(nums,left,right);
            left ++;
            right --;
        }
    }

    //数组排序,冒泡
    public void sortArray(int [] a,int index){
        for (int i = index; i < a.length; i++) {
            for (int j = index; j < a.length-(i-index)-1; j++) {
                if (a[j] > a[j + 1]){
                    swap(a,j,j+1);
                }
            }
        }
    }
    //交换两个元素的位置
    public void swap(int nums[],int left,int right){
        nums[left] = nums[left] + nums[right];
        nums[right] = nums[left] - nums[right];
        nums[left] = nums[left] - nums[right];
    }
```
