至少有一位重复数字的反面就是：所有数字都不一样。
所以采用数位dp求解出所有$\le{N}$的，并且满足所有数字都不一样的数字个数。
数位DP的每一层依次填入每个可能的$\le{x}$的数字，然后在剩下的数字中选取i（剩下的坑位）个填入剩下的位置，即有$A_{10-(n-i)}^i$种可能情况。依次累加。一旦发现重复数字直接break。

```
int fact(int i)
{
    if(i==1 || i==0) return 1;
    return fact(i-1) * i;
}

int A(int a, int b)
{
    return fact(a)/fact(a-b);
}

int dp(int n)
{
    vector<int> nums;
    while(n) nums.push_back(n%10),n/=10;
    
    int ans = 0;
    vector<int> last(10,0);
    
    for(int i = 1 ; i < nums.size() ; i++)
        for(int j = 1 ; j <= 9 ; j++)
            ans += A(9,i-1);
    
    for(int i = nums.size()-1 ; i >= 0 ; i--) {
        int x = nums[i];
        
        for(int j = i==nums.size()-1 ; j < x ; j++) {
            if(last[j]) continue;
            ans += A(10-(nums.size()-i),i);
        }
        
        if(++last[x] == 2) break;
        
        if(!i) ans ++;
    }
    return ans;
}

class Solution {
public:
    int numDupDigitsAtMostN(int N) {
        return N - dp(N);
    }
};
```