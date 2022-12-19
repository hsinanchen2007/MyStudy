```
class Solution {
    int[] help;
    int[] indexs;
    int[] ans;
    //参考了精选题解：liweiwei1419
    //关键点：
    //1.利用索引数组定位，排序的时候排的是索引
    //2.在归并的时候，左边元素出列的时候计数
    public List<Integer> countSmaller(int[] nums) {
        List<Integer> res = new ArrayList<>();
        int n = nums.length;
        if(n == 0){
            return res;
        }
        
        help = new int[n];
        indexs = new int[n];
        ans = new int[n];
        
        for(int i = 0; i < n; i++){
            indexs[i] = i;//给索引数组赋值
        }
        mergeSort(nums,0,n - 1);
        for(int i = 0; i < n; i++){
            res.add(ans[i]);
        }


        return res;
        
    }
    
    public void mergeSort(int[] nums,int l,int r){
        if(l >= r){
            return;
        }
        
        int mid = l + ((r - l) >> 1);
        
        mergeSort(nums,l,mid);
        mergeSort(nums,mid + 1,r);
        
        if(nums[indexs[mid]] > nums[indexs[mid + 1]]){
            merge(nums,l,mid,r);
        }
 
    }
    
    public void merge(int[] nums,int l,int mid,int r){

        int len = r - l + 1;
        int p1 = l;
        int p2 = mid + 1;
        
        int i = 0;
        
        while(p1 <= mid && p2 <= r){
            if(nums[indexs[p1]] <= nums[indexs[p2]]){//这种情况前面的数出列
                ans[indexs[p1]] += p2 - mid - 1; 
            }
            help[i++] = nums[indexs[p1]] <= nums[indexs[p2]] ? indexs[p1++] : indexs[p2++];
        }
        
        while(p1 <= mid){//p2已越界
            ans[indexs[p1]] += r - mid;
            help[i++] = indexs[p1++];
            
        }
        
        while(p2 <= r){//p1越界不用计算
            help[i++] = indexs[p2++];
        }
        
        for(int k = 0; k < len; k++){
            indexs[k + l] = help[k];
        }

    }

    
}
```
