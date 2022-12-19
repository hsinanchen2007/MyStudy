### 解题思路
感觉凑了一下就出来了，for循环内嵌套二分查找

### 代码

```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int N=numbers.length;
        int result[]={-1,-1};
        for(int i=0;i<N;i++){      
            int left=0;
            int right=N-1;
            while(left<=right){
            int mid=left+(right-left)/2;
            if(mid==i){
                mid=mid+1;
            }
                if(numbers[mid]+numbers[i]==target){
                    result[0]=i+1;
                    result[1]=mid+1;
                    return result;
                }else if(numbers[mid]+numbers[i]<target){
                    left=mid+1;
                }else if(numbers[mid]+numbers[i]>target){
                    right=mid-1;
                }
            }
        }
        return result;
    }
}
```