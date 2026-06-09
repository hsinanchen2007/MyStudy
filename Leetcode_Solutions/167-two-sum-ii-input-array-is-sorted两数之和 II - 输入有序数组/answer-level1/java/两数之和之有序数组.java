定义头指针start和尾指针end，两数之和sum>target 时，end--，sum<target时start++

代码如下：

class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int[] arr=new int[2];
        for(int start=0,end=numbers.length-1;start<end;){
                if(numbers[start]+numbers[end]==target){
                    arr[0]=start+1;
                    arr[1]=end+1;
                    return arr;
                }else if(numbers[start]+numbers[end]>target){
                    end--;
                }else{
                    start++;
                }
            } 
            return  null; 
        }
        
    }

   