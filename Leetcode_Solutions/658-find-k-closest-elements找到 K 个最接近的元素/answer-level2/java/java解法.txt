执行用时 :28 ms, 击败了23.70%的用户。
内存消耗 :50.7 MB, 击败了40.43%的用户。
```
class Solution {
    public List<Integer> findClosestElements(int[] arr, int k, int x) {
        List<Integer> list = new ArrayList<>();
        if(k == 0){
            return list;
        }
        if(x <= arr[0]){
            for(int i = 0; i < k; i++){
                list.add(arr[i]);
            }
            return list;
        }
        if(x >= arr[arr.length-1]){
            for(int i = arr.length - k; i < arr.length; i++){
                list.add(arr[i]);
            }
            return list;
        }
        int left = 0, right = 0;
        //先找到第一个大于或等于x的下标，然后开始左右两个数依次判断哪个数比较接近，放进列表中，直到数量达到k个
        for(int i = 1; i < arr.length; i++){
            if(arr[i] >= x){
                right = i;
                left = i-1;
                break;
            }
        }
        while(list.size()<k){
            if(left >=0 && right < arr.length){
                if(Math.abs(arr[left] - x) <= Math.abs(arr[right] - x)){
                    list.add(arr[left]);
                    left--;
                }else{
                    list.add(arr[right]);
                    right++;
                }
            }else if(left >=0){
                list.add(arr[left]);
                left--;
            }else{
                list.add(arr[right]);
                right++;
            }
        }
        Collections.sort(list);
        return list;  
    }
}
```