1、少于二个数组元素的不需要查找，直接返回就好；
2、等于两个的直接交换返回
3、大于等于三个元素的需要寻找交换的位置
    a、从前往后索引，得到需要交换的位置，代码中start是最后一个上升的值的下标，swap是最后的最接近下标为start的值的值
    b、start为-1则为全降序，将数组翻转即可
    c、当start不为-1时，start的值，比swap后面的值都要大，并且交换后是降序，则需要先将swap及其后面的数据翻转即可

代码如下
```
public void nextPermutation(int[] nums) {

        int start = -1,swap = -1,len = nums.length;
        int i = 0;
        if (len < 2){
            return;
        } else if (len == 2){
            start = nums[i];
            nums[i] = nums[i + 1];
            nums[i + 1] = start;
            return;
        }

        for (i = 0 ;i < len - 1; i++){

            if (nums[i] < nums[i + 1]){
                start = i;
                swap = i + 1;
            } else if (start != -1){
                if (nums[start] < nums[i + 1] && nums[swap] >= nums[i + 1]){
                    swap = i +1;
                }
            }
        }

        int l = -1,tmp;
        if (start == -1){
            l = len / 2;
        } else {
            l = (len - start) / 2;
            tmp = nums[start];
            nums[start] = nums[swap];
            nums[swap] = tmp;
        }
        for (i = 0;i < l; i++){
            tmp = nums[start+i+1];
            nums[start+i+1] = nums[len-i-1];
            nums[len-i-1] = tmp;

        }
    }
```
