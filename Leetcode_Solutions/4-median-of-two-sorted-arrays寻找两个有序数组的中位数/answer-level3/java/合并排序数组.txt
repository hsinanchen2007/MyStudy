### 解题思路
根据题目要求的时间复杂度，很容易想到限制的就是合并数组的排序时间复杂度问题，使用Java自带的Arrays.sort()可以很方便地达到这一目的

解决这一问题后就是很简单的思路：合并排序数组，根据数组的长度为奇数或是偶数得出最终的结果
```
执行用时 : 4 ms , 在所有 Java 提交中击败了 37.53% 的用户
内存消耗 : 46.8 MB , 在所有 Java 提交中击败了 95.38% 的用户
```
### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int len1 = nums1.length;
        int len2 = nums2.length;
        int[] array = new int[len1+len2];
        double answer=0;
        array= mergeSortedArrays(nums1,nums2);
        
        int len = array.length;
        if(len%2==1){//奇数长度
            answer=array[len/2];
        }
        else if(len%2==0){//偶数长度
            double first = array[len/2-1];
            double second = array[len/2];
            
            answer=(first+second)/2;
        }
        return answer;
    }
    
    public int[] mergeSortedArrays(int[] nums1,int[] nums2){
        if (nums1==null){return nums2;}
        if (nums2==null){return nums1;}
        
        int len1 = nums1.length;
        int len2 = nums2.length;
        
        int[] nums3 = new int[len1+len2];
        int i=0;int j=0;int k=0;
        for(;i<len1;i++,k++){
            nums3[k]=nums1[i];
        }
        for(;j<len2;j++,k++){
            nums3[k]=nums2[j];
        }
        
        Arrays.sort(nums3);
        
        return nums3;
    }
    
    
    
}
```