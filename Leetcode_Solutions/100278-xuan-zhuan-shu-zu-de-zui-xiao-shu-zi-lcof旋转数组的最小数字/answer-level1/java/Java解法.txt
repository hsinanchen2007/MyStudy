### 解题思路
leetcode的剑指offer比起***的多了很多测试用例，确实有点难度

### 代码

```java
class Solution {
    public int minArray(int[] numbers) {
        if(numbers==null||numbers.length==0){
            return -1;
        }
        int left=0;
        int right=numbers.length-1;
        while(left<right){
            int mid=left+((right-left)>>1);
            if(numbers[mid]>numbers[right]){
                left=mid+1;
            }else if(numbers[mid]==numbers[right]){
                right--;
            }else{
                right=mid;
            }
        }
        return numbers[left];
    }
}
```