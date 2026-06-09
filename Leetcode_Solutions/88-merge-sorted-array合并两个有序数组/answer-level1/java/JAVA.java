### 解题思路
此处撰写解题思路
我的思路:
    从数组1的3的下标开始循环，一直循环m+n个,将数组2的内容赋值给数组1的后面
    然后将数组1进行排序
### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int z=0;
        int k=m+n;
        for(int i=m;i<k;i++){
            nums1[i]=nums2[z];
            z++;
        }

        for(int i=0;i<nums1.length-1;i++){
            for(int j=i+1;j<nums1.length;j++){
                if(nums1[i]>nums1[j]){
                    int t=nums1[i];
                    nums1[i]=nums1[j];
                    nums1[j]=t;
                }
            }
        }
    }
}
```