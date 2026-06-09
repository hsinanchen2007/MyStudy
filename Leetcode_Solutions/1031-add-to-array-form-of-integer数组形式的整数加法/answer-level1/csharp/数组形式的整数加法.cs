```
public class Solution {
    public IList<int> AddToArrayForm(int[] A, int K) {
        int i = A.Length - 1;
        int num = K;
        List<int> arr = new List<int>();
        while(i >= 0 || num > 0){
            if(i >= 0){
                num += A[i];
            }
            arr.Add(num % 10);
            num /= 10;
            i--;
        }
        //数组转换
        int[] arr1 = arr.ToArray();
        //反转
        Array.Reverse(arr1);
        return arr1;
    }
}
```
