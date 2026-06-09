```
class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> arr(n);
        // k-1个不同的差值，且大于1
        for(int i=0; i<k; i++){
            if(i % 2 == 0){
                arr[i] = i / 2 + 1;
            } else {
                arr[i] = n - i / 2;
            }
        }
        int prv = k-1;
        // 剩余差值都为1
        for(int i=prv+1; i<n; i++){
            if(prv % 2 == 0){
                arr[i] = prv / 2 + 1 + (i - prv);
            } else {
                arr[i] = n - prv/2 - (i - prv);
            }
        }
        return arr;
    }
};
```
