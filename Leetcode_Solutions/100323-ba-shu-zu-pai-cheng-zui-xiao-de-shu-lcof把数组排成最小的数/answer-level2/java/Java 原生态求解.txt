```
class Solution {
    public String minNumber(int[] nums) {
        for(int i = nums.length - 1;i >= 0;i--){
            for(int j = 0;j < i;j++){
                if(compare(nums[j],nums[j + 1]) == -1){
                    swap(nums,j,j+1);
                }
            }
        }
        StringBuilder stringBuilder = new StringBuilder();
        for(int item : nums){
            stringBuilder.append(""+item);
        }
        return stringBuilder.toString();
    }


    //对于M，N 定义一个规则 计算 M和N的顺序大小 然后运用这个规则对数组进行排序，拼接即可。
    public static int compare(int m,int n){
        String str1 = m + "" + n;
        String str2 = n + "" + m;
        if(str1.equals(str2)){
            return 0;
        }
        for(int i = 0;i < str1.length() ;i++){
              if(str1.charAt(i) == str2.charAt(i)){
                continue;
            }else if (str1.charAt(i) < str2.charAt(i)) {
				return 1;
			} else {
				return -1;
			}
        }
        return 0;
    }

    //交换数组中两个数字 
    public static void swap(int[] nums,int i,int j){
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}
```
