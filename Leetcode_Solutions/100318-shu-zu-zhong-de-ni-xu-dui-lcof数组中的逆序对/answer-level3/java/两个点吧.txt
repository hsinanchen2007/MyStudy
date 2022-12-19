### 解题思路
超时间超了好几次
temp数组从函数外开，作为参数传递
不必全部复制nums，复制相应区间即可
这两个操作很费时间，算是习惯吧。。。

### 代码

```java
class Solution {
    public int merge(int[] nums,int l,int r,int[] temp){
        if(l==r) return 0;
        int mid = (l+r)/2;

        int n1=merge(nums,l,mid,temp);
        int n2=merge(nums,mid+1,r,temp);

        int res=n1+n2;
        if(nums[mid]<=nums[mid+1]) return res;

        int i=l;
        int j=mid+1;
        for(int dsj=l;dsj<=r;dsj++){
            temp[dsj]=nums[dsj];
        }
        for(int k=l;k<=r;k++){
            if(i>mid){
                nums[k]=temp[j++];
            }
            else if(j>r){
                nums[k]=temp[i++];
                res+=(r-mid);
            }
            else if(temp[i]<=temp[j]){
                nums[k]=temp[i++];
                res+=(j-mid-1);
            }
            else{
                nums[k]=temp[j++];
            }
        }
        return res;
    }
    public int reversePairs(int[] nums) {
        int len=nums.length;
        if(len<=1) return 0;
        int[] temp = new int[len];
        return merge(nums,0,len-1,temp);
    }
}
```