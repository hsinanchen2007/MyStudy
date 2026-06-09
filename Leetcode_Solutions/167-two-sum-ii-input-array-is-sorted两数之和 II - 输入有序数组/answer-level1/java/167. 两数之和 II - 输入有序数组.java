### 解题思路
此处撰写解题思路
双指针
### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int result[]=new int[2];
        int length=numbers.length;
        int index1=0;
        int index2=length-1;
        if(target>numbers[length-1]+numbers[length-2]||target<numbers[0]+numbers[1]){
            result=null;
        }
        while(index1<index2){
            if((numbers[index1]+numbers[index2])>target){
                index2--;
            }else if((numbers[index1]+numbers[index2])<target){
                index1++;
            }else{
                result[0]=index1+1;
                result[1]=index2+1;
                break;
            }
        }
        return result;
    }
}
```