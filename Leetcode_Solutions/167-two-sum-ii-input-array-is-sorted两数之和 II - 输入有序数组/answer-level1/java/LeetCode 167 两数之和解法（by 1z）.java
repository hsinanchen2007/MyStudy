### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    /**
        numbers:数组
        target:目标数
        1.采用头尾指针的方法，将头指针固定在数组的首部，尾指针固定在数组的尾部
        2.开始进入while判断，如果两数相加为target 直接返回即可
        3.如果两数之和小于target，因为首部指针为最小值还有增加的空间，所以首部指针后移（使得和更大）
        4.如果两数之和大于target，因为尾部指针为最大值，还有变小的空间，所以尾部指针前移(使得和更小)
        5.当index1>=index2 时，循环结束
        6.ps: 注意返回的不是数组下标 数组初始为1
           
    */
    public int[] twoSum(int[] numbers, int target) {
        if(numbers.length <=1) return null;
        //头指针
        int index1 = 0;
        //尾指针
        int index2 =numbers.length-1;
        while(index1 < index2){
            //如果两数相加为target 直接返回即可
            if(numbers[index1] + numbers[index2] == target){
                return new int[]{index1+1,index2+1};
            }else if (numbers[index1] + numbers[index2] < target){
                index1++;
            }else{
                index2--;
            }
        }
        return null;
    }
}

```