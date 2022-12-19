前后有序，找到对应的最小值，只要盯住numbers[mid]与numbers[right]的大小关系，及时的更新对应的left right 即可；
```java
class Solution {
    public int minArray(int[] numbers) {
        int left = 0,right = numbers.length-1;
        while(left<right){
            int mid = left+(right-left)/2;
            if(numbers[mid]<numbers[right]){
                right = mid;
            }else if(numbers[mid]>numbers[right]){
                left= mid+1;
            }else{
                right = right-1;
            }
        }
        return numbers[right];
    }
}
```
