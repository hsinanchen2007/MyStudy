### 解题思路
 1.先将nums1前m个元素放到新的数组nums当中
 2.定义p1指向nums的第0个元素，p2指向nums2的第0个元素。p指向nums1的第0个元素
 3.循环遍历nums和nums2 并比较nums[p1]和nums2[p2] 小的放在nums1[p]中。并将p1/p2 和p后移一位 
 4.循环遍历nums和nums2将其中一个剩余的数据放进nums1中

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        
        int[] nums = new int[m];
		System.arraycopy(nums1,0,nums,0,m);
		int p1=0,p2=0,p=0;
		while(p1<m&&p2<n){
			if(nums[p1]<=nums2[p2]){
				nums1[p]=nums[p1];
				p1++;
			}else{
				nums1[p]=nums2[p2];
				p2++;
			}
			p++;
		}
		while(p1<m){
			nums1[p]=nums[p1];
			p1++;
			p++;
		}
		while(p2<n){
			nums1[p]=nums2[p2];
			p2++;
			p++;
		}
	}
}