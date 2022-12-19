```
class Solution {
    public boolean canReach(int[] arr, int start) {
        int[] visit = new int[arr.length];
        for (int i=0; i<arr.length;i++) {
            visit[i] = 0;
        }
        return ret(start, arr, visit);
    }
    
    public boolean ret(int index, int[] arr, int[] visit) {
        if (index < 0 || index >= arr.length || visit[index]==1) {
             return false;
        }
        if (arr[index]==0) {
            return true;
        }
        visit[index]=1;
        if (ret(index+arr[index],arr,visit)) {
            return true;
        }
         if (ret(index-arr[index],arr,visit)) {
            return true;
        }
        return false;
    }
}
```
