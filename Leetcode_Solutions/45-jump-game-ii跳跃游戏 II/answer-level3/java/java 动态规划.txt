### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int jump(int[] nums) {
        if(nums.length==1){
            return 0;
        }
        int[] array=new int[nums.length];
        Arrays.fill(array,Integer.MAX_VALUE);
        int first=nums[0];
        for(int i=0;i<nums.length&&i<first+1;i++){
            array[i]=1;
        }       
        int max=first;
        for(int i=1;i<nums.length-1;i++){
            int step=nums[i];
            if(i+step<max){
                continue;
            }else{
                max=i+step;
            }
            for(int j=0;j<step;j++){
                if(i+j+1<=array.length-1&&array[i]+1<array[i+j+1]){
                    array[i+j+1]=array[i]+1;
                }
            }
        }
        return array[nums.length-1];
    }
}
```