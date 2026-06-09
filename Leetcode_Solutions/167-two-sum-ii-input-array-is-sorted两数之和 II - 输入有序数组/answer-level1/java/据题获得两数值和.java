### 解题思路
此处撰写解题思路
按照如题所示例：要的结果是数组从1开始的，实际计算数组是从0开始，故在获得最终的结果时，把两结果分别+1
### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int a = 0;
        int b = 0;
        for(int i =0;i<=numbers.length;i++){
            for(int j = i+1;j<numbers.length;j++){
                if(numbers[i]+numbers[j]==target){
                    a=i+1;
                    b=j+1;
                    continue;
                }
            }
        }
        int[] result;
        if(a==0&&b==0&&target!=0){
            result = new int[]{};
        }else{
            result = new int[]{a,b};
        }
        return result;
    }
}
```