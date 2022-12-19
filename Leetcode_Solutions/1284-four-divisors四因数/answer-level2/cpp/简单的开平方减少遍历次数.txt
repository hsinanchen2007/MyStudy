### 解题思路
开平方

### 代码

```cpp
class Solution {
    int k;
public:
    int sumFourDivisors(vector<int>& nums) {
        int res=0;
        for(int i=0;i<nums.size();i++){
            if(f(nums[i])==4) res+=k;
        }
        return res;
    }
    int f(int n){
        int cnt=0,a=sqrt(n);  //cnt为因素个数，开平方遍历
        k=0;
        for(int i=1;i<=a;i++){
            if(n%i==0) {     //如果得到一个因数i，另一个因数就是n/i
                cnt++;
                k+=i;
                k+=n/i;
            }
        }
        if(a*a==n) cnt=cnt*2-1; //一个数的因数如果正好为它的开平方，两个相同的因数只算一个
        else cnt=cnt*2;
        return cnt;
    }
};
```