解法1：
遍历整个数组，与val比较，不同的数放入新数组
public int remove(int[] nums,int val){
    StringBuffer sb = new StringBuffer();
    for (int i = 0;i < nums.length;i++){
        if (nums[i] != val){
            sb.append(nums[i]);
        }
    }
    return sb.length();
}

解法2：快慢指针
指针一直用不好，参考各位大神的代码写的
public int remove(int[] nums,int val){
    int i = 0;    //慢指针
    for (int j = 0;j < nums.length;j++){
        if (nums[j] != val){
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
   
}
