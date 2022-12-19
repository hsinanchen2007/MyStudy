### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public static int[] closestDivisors(int num) {
        int []nums1 = getNums(num+1);
        int []nums2 = getNums(num+2);
        if(Math.abs(nums1[1]-nums1[0])>Math.abs(nums2[1]-nums2[0])){
            return nums2;
        }else{
            return nums1;
        }
    }

    private static int [] getNums (int num){
        int sqrt = (int)Math.sqrt(num);
        while (sqrt>0){
            if(num%sqrt==0){
                return new int []{sqrt,num/sqrt};
            }else{
                sqrt--;
            }
        }
        return new int []{1,num};
    }
}
```