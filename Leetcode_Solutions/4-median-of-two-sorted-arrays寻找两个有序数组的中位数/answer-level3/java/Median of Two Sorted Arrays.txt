执行用时 :3 ms, 在所有 Java 提交中击败了92.72%的用户
内存消耗 :42.3 MB, 在所有 Java 提交中击败了96.44%的用户
### 解题思路
p1、p2两个指针分别指向两个数组，从头开始比较，每次只移动一个指针。
cur计数，控制循环提前结束、判断是否将这个数保存。

### 代码

```java
class Solution {
    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int sum = nums1.length + nums2.length;
        boolean isOdd  = ((sum % 2) == 1);
        int med = (sum>>1);
        int p1=0,p2=0 ,cur = 0;
        int [] re = new int[2];

        while(p1<nums1.length && p2 < nums2.length && cur <=med){
            if(nums1[p1] >nums2[p2]){ 
                 if(cur>=med-1) re[cur -(med-1)] = nums2[p2];
                p2++;
            }else{
                if(cur>=med-1) re[cur-(med-1)] = nums1[p1];
                p1++;
            }
            cur++;
        }

        while(p1 < nums1.length && cur<=med ){
            if(cur>=med-1)   re[cur -(med-1)] = nums1[p1]; 
            p1++;
            cur++;
        }
        while(p2 < nums2.length && cur <= med){          
            if(cur>=med-1) re[cur -(med-1)] = nums2[p2];
            p2++;
            cur++;
        }
        

        if(isOdd){
            return re[1];
        }else{
            return (re[0]+re[1])/2.0;
        }

    }
}
```