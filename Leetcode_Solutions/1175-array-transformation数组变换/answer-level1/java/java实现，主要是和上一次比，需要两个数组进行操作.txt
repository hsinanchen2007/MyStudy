```
class Solution {
    public List<Integer> transformArray(int[] arr) {
        boolean flag = true;
        while (flag){
            flag = false;
            int[] curr = arr.clone();
            for (int i = 1;i < curr.length-1;i++){
                if (curr[i]>curr[i-1]&&curr[i]>arr[i+1]){
                    arr[i]=arr[i]-1;
                    flag=true;
                }
                else if (curr[i]<curr[i-1]&&curr[i]<arr[i+1]){
                    arr[i]=arr[i]+1;
                    flag=true;
                }
            }
        }

        List<Integer> res = new ArrayList<>();
        
        for (Integer each:arr) {
            res.add(each);
        }
        return res;
    }
}

```
