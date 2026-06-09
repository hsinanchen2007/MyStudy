双指针的引用
一个指针指向值较小的元素，一个指针指向值较大的元素。指向较小的元素的指针从头到尾遍历，指向较大的元素从尾到头遍历。
* 如果两个指针指向元素的和sum == target ，那么得到要求的结果。
* 如果sum>target，移动较大的元素，使得sum值变小一点。
* 如果sum<target,移动较小的元素，使得sum值变大一点。
```java
class Solution {
    public int[] twoSum(int[] numbers, int target) {
        int p1=0,p2=numbers.length-1;
        while(p1<p2){
            int sum = numbers[p1]+numbers[p2];
            if(sum==target){
                return new int[]{p1+1,p2+1};
            }else if(sum<target){
                p1++;
            }else{
                p2--;
            }
        }
        return null;
    }
}
```