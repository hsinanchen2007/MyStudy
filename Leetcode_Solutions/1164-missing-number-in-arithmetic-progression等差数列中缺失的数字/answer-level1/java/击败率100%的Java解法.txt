```Java
class Solution {
    public int missingNumber(int[] arr) {
        int p = 0;
        int q = arr.length -1;
        int sum = arr[p] + arr[q];
        int change = 0;
        int sequence = arr[q] - arr[p];
        while(p < q) {
            p++;
            q--;
            change = arr[p] + arr[q] - sum;
            if(change != 0) {
                return (change * sequence > 0) ? (sum - arr[q]) : (sum - arr[p]);
            }
        }
        return sum / 2; //原数列长度为奇数且去掉了中间项时
    }
}
```