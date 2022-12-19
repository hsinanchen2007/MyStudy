### 若遇到更小的差，则清空列表，将目前的数加入列表。若差相等，则将目前的数加入列表。
![QQ图片20200106153853.png](https://pic.leetcode-cn.com/6731724821c2c8223ecd5a8ab61fe8592a72dc9e0f712e4f91c8be89e4218a49-QQ%E5%9B%BE%E7%89%8720200106153853.png)
此处撰写解题思路

### 代码

```java
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {

        List<List<Integer>> ans=new ArrayList<>();
        quikSort(arr,0,arr.length-1);
        int mix=arr[arr.length-1]-arr[0];
        for(int i=0;i<arr.length-1;i++){
            if(mix>arr[i+1]-arr[i]){
                mix=arr[i+1]-arr[i];
                List<Integer> list=new ArrayList<>();
                ans.clear();
                list.add(arr[i]);
                list.add(arr[i+1]);
                ans.add(list);
            }else if(mix==arr[i+1]-arr[i]){
                List<Integer> list=new ArrayList<>();
                list.add(arr[i]);
                list.add(arr[i+1]);
                ans.add(list);
            }
        }
        return ans;
    }
    public static void quikSort(int[] nums,int low,int high){
        if(low>=high)
            return;
        int i=low;
        int j=high;
        int temp=nums[i];
        while(i<j){
            while(i<j && nums[j]>temp)
                j--;
            if(i<j)
                nums[i++]=nums[j];
            while(i<j&&nums[i]<temp)
                i++;
            if(i<j)
                nums[j--]=nums[i];
        }
        nums[i]=temp;
        quikSort(nums,low,i-1);
        quikSort(nums,i+1,high);
    }
}
```