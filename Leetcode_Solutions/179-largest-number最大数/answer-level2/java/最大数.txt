//其实最大的问题就是不太了解String.compareTo()这个方法
```java
class Solution {
    public String largestNumber(int[] nums) {
          String str="";
	while (nums.length>0){
	    int temp=nums[0];//存放每一轮数组中满足要求的最大的数，放于最终字符串的最前面
	    int tempIndex=0;//每轮比较temp的数组下标
	    for(int i=1;i<nums.length;i++){
            //先将nums[i]和temp转换成字符串，然后以两种不同的顺序进行连接，最后比较两种结果的大小
	        if ((Integer.toString(nums[i])+Integer.toString(temp)).compareTo(Integer.toString(temp)+Integer.toString(nums[i]))>0){
	            temp = nums[i];//temp赋值为当前位置的数组元素
	            tempIndex=i;//记录下当前数组下标
	        }
	    }
	    str+=Integer.toString(temp);   //将temp添加到字符串str中
	    nums[tempIndex]=nums[nums.length-1];    //将temp位置替换成数组的最后一个元素
            nums=Arrays.copyOf(nums, nums.length-1);//将数组最后一个元素剔除，数组长度减一
        }
        if(str.charAt(0)=='0')
        	return "0";
        return str;

    }
}