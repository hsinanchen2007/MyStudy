先上代码：
```
class SortedArraysMedianFinder {
    private int[] nums1;
    private int[] nums2;
    public SortedArraysMedianFinder(int[] nums1, int[] nums2){
        this.nums1 = nums1;
        this.nums2 = nums2;
    }
    private enum CompareState {
        EQ, GT, LT
    }
    public double getMedian(){
        Function<int[], Double> getSortedArrayMedian = arr->{
            int len = arr.length;
            int median = len>>1;
            double m1,m2;
            if(len%2 == 1){
                m1 = arr[median];
                return m1;
            }else{
                m1 = arr[median];
                m2 = arr[median-1];
                return (m1+m2)/2;
            }
        };
        if(nums1==null || nums1.length==0){
            return getSortedArrayMedian.apply(nums2);
        }
        if(nums2==null || nums2.length==0){
            return getSortedArrayMedian.apply(nums1);
        }
        int len1 = nums1.length;
        int len2 = nums2.length;
        int len = len1+len2, median = len>>1;
        double m1,m2;
        if(len%2 == 1){
            m1 = getTargetIdx(median);
            return m1;
        }else{
            m1 = getTargetIdx(median);
            m2 = getTargetIdx(median-1);
            return (m1+m2)/2;
        }
    }

    private int getTargetIdx(int target){
        BiFunction<int[], int[], Integer> findTargetIdx = (a, b)->{
            CompareState ct = null;
            int len1 = a.length, start = 0, end=len1;
            Integer index=null;
            while(ct!= CompareState.EQ && start>=0 && end<=len1 && start<end){
                index = (start+end)>>1;
                ct = checkIsMedian(index, target, a, b);
                if(ct == CompareState.GT){
                    end = index;
                }else if(ct == CompareState.LT){
                    start = index+1;
                }
            }
            return ct== CompareState.EQ ? index:null;
        };

        Integer ret = findTargetIdx.apply(nums1, nums2);
        if(ret!=null){
            return nums1[ret];
        }

        ret = findTargetIdx.apply(nums2, nums1);
        assert(ret != null);
        return nums2[ret];
    }


    //
    private static CompareState checkIsMedian(int index, int target, int[] nums1, int[] nums2){
        int len2 = nums2.length;
        int diff = target - index;
        if(diff>0 && len2>=diff && nums1[index]>=nums2[diff-1]){
            if(diff>= len2 || nums1[index] <= nums2[diff]){
                return CompareState.EQ;
            }else{
                return CompareState.GT;
            }
        } else if(diff==0){
            if(nums1[index]<=nums2[diff]){
                return CompareState.EQ;
            }
            return CompareState.GT;
        } else if(diff<0){
            return CompareState.GT;
        }else{
            return CompareState.LT;
        }
    }

}
public class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        SortedArraysMedianFinder finder = new SortedArraysMedianFinder(nums1, nums2);
        return finder.getMedian();
    }
}

```
受NP问题的提出思路启发,可以先看给定了一个数组的下标,是否可以判断出其是否为整个数组的中位数。
答案是可以的,见SortedArraysMedianFinder#checkIsMedian,该方法拥有常数复杂度。
既然如此，结合二分查找的思路，分别二分查找两个数组即可。
最终复杂度为O(log(m)+log(n)) == O(log(mn)) == O(log((m+n)^2) == O(log(m+n))