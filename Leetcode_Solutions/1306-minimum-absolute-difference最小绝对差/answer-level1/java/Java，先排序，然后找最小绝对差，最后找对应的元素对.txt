1. 对数组进行排序
2. 最小绝对差必然是**相邻两个数的差**，所以需要遍历一边数组把相邻元素对的差的最小值找出来
3. 再遍历一遍，把与最小差相等的相邻元素对填入列表
```
class Solution {
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
        List<List<Integer>> ans=new ArrayList<>();
        Arrays.sort(arr);
        int n=arr.length;
        int min=arr[1]-arr[0];//最小绝对差
        for(int i=2;i<n;i++){
            int e=arr[i]-arr[i-1];
            if(e<min){
                min=e;
            }
        }
        for(int i=1;i<n;i++){
            if(arr[i]-arr[i-1]==min){
                List<Integer> res=new ArrayList<>();
                res.add(arr[i-1]);
                res.add(arr[i]);
                ans.add(res);
            }
        }
        return ans;
    }
}
```
