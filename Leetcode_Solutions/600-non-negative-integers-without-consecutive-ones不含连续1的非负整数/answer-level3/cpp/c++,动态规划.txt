dp，如果这个题改成二进制n个长度的数中1不相邻的数字的个数，那就是个普通的dp。但这个题给了一个数字大小的上限。首先求出n个长度中
1不相邻的个数，但这中间可能会存在超出题目给定数字大小的，比如给定8（1000），所求的答案中会包含1010和1001，显然我们要把他剔除。
那我们从从高位到低位遍历这个给定的数字，遍历过程中同时检查以下两个条件。
如果当前位是1上一位也是1，那么我们的答案里就不会存在大于这个数字的了，因为答案给出的一定是10或者01，都比11小，直接break。
如果当前0上一位也是0，那么我们的答案中会包含01这样的，会超过给定范围，就要减去之前dp数组中这个位置以1结尾的数字个数。
对于当前位置是0上一位置是1的，不用处理，因为不会超过范围。
对于当前位置是1，上一位置是0的也不用处理，因为也不会超过范围。
```
class Solution {
public:
    vector<int> changetoBinary(int n){
        int length = int(log(n)/log(2))+1;
        vector<int>ans(length);
        while(n!=0){
            int pos = log(n)/log(2);
            ans[pos] = 1;
            n = n-pow(2,pos);
        }
        for(int i = length-1;i>=0;i--)
            cout << ans[i] <<" ";
        return ans;
    }
    int findIntegers(int num) {
        vector<int>binary = changetoBinary(num);
        int length = int(log(num)/log(2))+1;
        vector<int>num1(length);
        vector<int>num0(length);
        num1[0] = 1,num0[0] = 1;
        for(int i = 1 ; i < length ; i++ ){
            num1[i] = num0[i-1];
            num0[i] = num0[i-1]+num1[i-1];
        }
        int ans = num1[length-1]+num0[length-1];
        for(int pos = length-2; pos >= 0 ; pos--){
            if(binary[pos] == 1 && binary[pos+1] == 1) break;
            if(binary[pos] == 0 && binary[pos+1]==0)
                ans-=num1[pos];
        }
        return ans;
    }
};
```
