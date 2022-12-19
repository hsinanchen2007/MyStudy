### 解题思路
此处撰写解题思路
我的思路:
    同过一个当前的值，和后面所有的值进行相加，如果加起来等于target的时候。就用新的数组记录下标，直接跳出循环
最后返回这个数组;
### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int a[]=new int[2];
        for(int i=0;i<numbers.length-1;i++){
            for(int j=i+1;j<numbers.length;j++){
                if(numbers[i]+numbers[j]==target){
                    a[0]=i+1;
                    a[1]=j+1;
                    break;
                }
            }
        }
        return a;
        
    }
}
```