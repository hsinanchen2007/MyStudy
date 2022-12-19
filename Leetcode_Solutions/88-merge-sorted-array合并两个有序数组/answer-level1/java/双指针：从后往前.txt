双指针，从后往前：
```
 public void merge(int[] nums1, int m, int[] nums2, int n) {
        int p1=m-1;int p2=n-1;int i=1;
        while(p1>=0&&p2>=0){
            if(nums1[p1]>=nums2[p2]){
                nums1[m+n-i]=nums1[p1];
                i++;p1--;
            }
            else{
                nums1[m+n-i]=nums2[p2];
                i++;p2--;
            }
        }
        while(p2>=0){//nums2的内容还未完全插入到nums1中
            nums1[m+n-i]=nums2[p2];
            i++;p2--;
        }
    }

```
