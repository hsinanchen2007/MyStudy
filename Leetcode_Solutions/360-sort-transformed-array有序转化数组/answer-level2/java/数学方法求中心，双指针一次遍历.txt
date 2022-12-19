### 解题思路
数学方法求中心点，找到对应位置，维持ij双指针，前后同时进行，一次遍历实现

### 代码

```java
class Solution {
    public int[] sortTransformedArray(int[] nums, int a, int b, int c) {
        int[] result = new int[nums.length];
        if(a == 0){
            for(int i = 0; i < nums.length; i++){
                if(b > 0){
                    result[i] = calculate(nums[i], a, b, c);
                }else{
                    result[nums.length - 1 - i] = calculate(nums[i], a, b, c);
                }
            }
            return result;
        }
        double mid = ((0 - b) / (double)(2 * a));
        //System.out.println(mid);
        if(mid < nums[0]){
            //System.out.println("1");
            for(int i = 0; i < nums.length; i++){
                if(a > 0){
                    result[i] = calculate(nums[i], a, b, c);
                }else{
                    result[nums.length - 1 - i] = calculate(nums[i], a, b, c);
                }
            }
        }else if(mid > nums[nums.length - 1]){
            //System.out.println("2");
            for(int i = 0; i < nums.length; i++){
                if(a < 0){
                    result[i] = calculate(nums[i], a, b, c);
                }else{
                    result[nums.length - 1 - i] = calculate(nums[i], a, b, c);
                }
            }
        }else{
            //System.out.println("3");
            int i = 0;
            for(i = 0; i < nums.length; i++){
                if((nums[i] <= mid) && (nums[i+1] >= mid)) break;
            }
           
            int j = i + 1; 
            //System.out.println(i+" "+j);
            int index = 0;
            while(i != -1 || j != nums.length){
                //System.out.println(nums[i]+" "+nums[j]);
                //System.out.println(i+" "+j);
                //System.out.println(Math.abs((double)(mid - nums[i])) + " " + Math.abs(nums[j] - mid));
                if(Math.abs((double)(mid - nums[i])) > Math.abs((double)(nums[j] - mid))){
                    result[index++] = calculate(nums[j++], a, b, c);
                    //System.out.println("i > j");
                }else{
                    result[index++] = calculate(nums[i--], a, b, c);
                    //System.out.println("i < j");
                }
                if(i == -1){
                    while(j != nums.length)
                        result[index++] = calculate(nums[j++], a, b, c);
                    break;
                }
                if(j == nums.length){
                    while(i != -1)
                        result[index++] = calculate(nums[i--], a, b, c);
                    break;
                }
            }
            if(a < 0){
                for(i = 0; i < nums.length/2; i++){
                    swap(result, i, nums.length - 1 - i);
                }
            }
        }
        return result;
    }

    public int calculate(int num, int a, int b, int c){
        return a * num * num + b * num + c;
    }

    public void swap(int[] nums, int index1, int index2){
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }
}
```