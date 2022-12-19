看着一堆大神用快速/堆/二叉搜索树解题，居然没看到我的冒泡。。。


```
public class Solution {
    public int[] GetLeastNumbers(int[] arr, int k) {
        if(k == arr.Length){
            return arr;
        }
        if(k == 0){
            return new int[0];
        }
        int min = arr[0];
        List<int> newArr = new List<int>();
        var i = 0;

        //冒泡排序，排K次，走起
        while(newArr.Count < k){
            for (var j = i + 1 ; j<arr.Length; j++){
                if(arr[j]<=arr[i]){
                    min = arr[j];
                    arr[j] = arr[i];
                    arr[i] = min;
                }
            }
            newArr.Add(arr[i]);
            i++;
        }

        return newArr.ToArray();
    }
}
```
