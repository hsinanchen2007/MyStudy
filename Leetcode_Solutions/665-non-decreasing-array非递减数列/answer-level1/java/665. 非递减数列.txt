
/**
 * Project:
 * Author : zhaozhen
 * Email  : 
 * Date   : 2019/9/28
 *
 * 解题思路: 遍历数组 当遇到 nums[i] > nums[i+1] 有两种处理方式 nums[i] = nums[i+1] 或者 nums[i+1] = nums[i] 也就是降低前一个 或者 升高后一个
 *
 * 处理之后 再次对后续区域进行升序判定即可([i-1,i...length]后面升序为true  降序为false)
 *
 */
```
public boolean checkPossibility(int[] nums) {
    int s = 0;
    int[] num_c = nums.clone();
    for(int i = 0 ;i < num_c.length - 1;i++){
        if(num_c[i] > num_c[i+1]){
            num_c[i+1] = num_c[i];
            i = -1;
            s++;
        }
        if(s >= 2){
            break;
        }
    }

    if(s <= 1) return true;
    s = 0;
    num_c.clone();
    for(int i = 0 ;i < num_c.length - 1;i++){
        if(num_c[i] > num_c[i+1]){
            num_c[i] = num_c[i+1];
            i = -1;
            s++;
        }
        if(s >= 2){
            break;
        }
    }

    if(s <= 1) return true;

    return false;
}

public boolean checkPossibility2(int[] nums) {
    for(int i = 0 ;i < nums.length - 1;i++){
        if(nums[i] > nums[i+1]){

            int[] nums_1 = Arrays.copyOf(nums,nums.length);
            nums_1[i] = nums_1[i+1];

            //nums[i+1] = nums[i]
            int[] nums_2 = Arrays.copyOf(nums,nums.length);
            nums_2[i + 1] = nums_2[i];

            return isIncrease(nums_1,i>0?i-1:i) || isIncrease(nums_2 , i>0?i-1:i);
        }
    }
    return true;
}

public boolean isIncrease(int[] nums , int s){
    for(int i = s;i < nums.length - 1;i++){
        if(nums[i] > nums[i+1]) return false;
    }
    return true;
}
```