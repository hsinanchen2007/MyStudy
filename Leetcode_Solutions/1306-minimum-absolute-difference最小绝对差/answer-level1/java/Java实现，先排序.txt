这道题比较简单，只要先将数组排序，因为arr.length >= 2，所以可以先初始化最小绝对差为arr[1] - arr[0],然后从索引1开始遍历数组，当这个索引的值和前一个索引的值得绝对值差==min时，添加到res里面，当<min时，清空res，因为之前添加的已经不算数了，更新min的值并且把当前索引的值和前一个索引的值添加到res里面。
因为兴趣，顺便写了几种排序算法测试时间复杂度。
分别是
1）归并排序
2）快速排序
3）Arrays提供的排序算法
4）希尔排序
所需时间也备注在后面了
```
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> res = new ArrayList<>();
        //merge_sort(arr,0,arr.length,new int[arr.length]);//29ms
        //quicksort(arr,0,arr.length - 1);//24ms
        Arrays.sort(arr);//25ms
        //shellsort(arr);//39ms
        int min = arr[1] - arr[0];
        for(int i = 1;i < arr.length;i++){
            if(arr[i] - arr[i - 1] == min)
                res.add(Arrays.asList(arr[i - 1],arr[i]));
            else if(arr[i] - arr[i - 1] < min){
                res.clear();
                res.add(Arrays.asList(arr[i - 1],arr[i]));
                min = arr[i] - arr[i - 1];
            }
        }
        
        return res;
    }
    
    private void quicksort(int[] nums,int left,int right){
        if(left >= right)
            return;
        int key = nums[left];
        int l = left,r = right;
        while(l < r){
            while(l < r && nums[r] >= key)
                r--;
            while(l < r && nums[l] <= key)
                l++;
            if(l < r)
                nums[l] = nums[l] + nums[r] - (nums[r] = nums[l]);
        }
        nums[left] = nums[l];
        nums[l] = key;
        quicksort(nums,left,l - 1);
        quicksort(nums,l + 1,right);
    }
    
    private void merge_sort(int[] nums,int left,int right,int[] temp){
        if(right - left == 1)
            return;
        int m = left + (right - left) / 2;
        merge_sort(nums,left,m,temp);
        merge_sort(nums,m,right,temp);
        int l = left,r = m,index = left;
        while(l < m || r < right){
            if(r >= right || (l < m && nums[l] <= nums[r]))
                temp[index++] = nums[l++];
            else
                temp[index++] = nums[r++];
        }
        for(int i = left;i < right;i++)
            nums[i] = temp[i];
    }
    
    private void shellsort(int[] nums){
        int gap = nums.length / 2;
        while(gap > 0){
            for(int i = gap;i < nums.length;i++){
                int insertNum = nums[i],preIndex = i - gap;
                while(preIndex >= 0 && nums[preIndex] >= insertNum){
                    nums[preIndex + gap] = nums[preIndex];
                    preIndex -= gap;
                }
                nums[preIndex + gap] = insertNum;
            }
            gap /= 2;
        }
    }
}
```
