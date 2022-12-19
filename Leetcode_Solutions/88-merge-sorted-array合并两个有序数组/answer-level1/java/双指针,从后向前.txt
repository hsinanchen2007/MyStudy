### 解题思路

### 代码

```java
class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        //记录当前值
        int curr=0;
        //索引位置,从尾部开始
        int tail=nums1.length-1;
        //定义两个指针
        int i=m-1,j=n-1;
        while(i>=0||j>=0){
            //如果i<0说明nums1的数组值已经比较完了,直接将取nums2数组的值即可,同理j<0也是一样
            if(i<0){
                curr=nums2[j];
                j--;
            }else if(j<0){
                curr=nums1[i];
                i--;
            }else if(nums2[j]>nums1[i]){
                //比较两个值,如果将大的值取出来,并且指针移动
                curr=nums2[j];
                j--;
            }else{
                //比较两个值,如果将大的值取出来,并且指针移动
                curr=nums1[i];
                i--;
            }
            //放到对应索引位置
            nums1[tail]=curr;
            //索引减1
            tail--;
        }
    }
}
```