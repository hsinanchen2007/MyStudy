1. 题目本身不太难，但是有许多坑点，需要注意；
2. 主要求出比该数本身小的数即可，我们分为(1~n)位来分别计算；

3. 1~n-1位的数主要是为sum(pow(m,i))(i = 1...n-1);
```
比如4个数的组合为[1,4,5,6] 给定数字4位数为1530
则小于3位数的组合为:
1位的数目： 4^1
2位的数目： 4^2
3位的数目： 4^3
小于n位的组合为: sum1 = 4 + 16 + 64
```
4. 考虑n位的时候，我们只需要考虑保留前k位保持相同，第k+1位比原数小，剩余的n - (k+1)位的数，随机在m个数中抽选即可；
```
这时我们大到小每次计算替换一位比原数小的
组合为:
保留3位，个位替换的数目(1530)： 比0小的数字有0个，因此sum = 0；
保留2位，十位替换的数目(153x)： 比3小的数字有1个，按照计算sum = 1*4^1，但是由于153在并不能由该组合构成，因此sum = 0；
保留1位，百位替换的数目(15xx)： 比5小的数字有2个，因此sum = 2*4^2；
保留0位，千位替换的数目(1xxx)： 比1小的数字有0个，因此sum = 0；
小于n位的组合为: sum2 = 0 + 0 + 32 + 0;
最后需要考虑数字本身能否由组合实现，如果能够实现，还需要再加上1；
```

5. 简单来说就是排列组合，但是作对不容易；
```
class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& D, int N) {
        vector<int> nums;
        vector<int> keys;
        vector<bool> ten(10,false);
        bool hasSame = true;
        int res = 0;
        int tmp = N;
        
        while(tmp > 0){
            nums.push_back(tmp%10);
            tmp = tmp/10;
        }
        
        reverse(nums.begin(),nums.end());
        for(int i = 0;i < D.size(); ++i){
            keys.push_back(stoi(D[i]));
            ten[D[i][0]-'0'] = true;
        }
        sort(keys.begin(),keys.end());
        int m = nums.size();
        int n = keys.size();
        
        for(int i = 1; i <= m-1; ++i){
            res += pow(n,i);
        }
        
        for(int i = m-1; i >= 0; --i){
            hasSame = true; 
            for(int k = 0; k < i; ++k){
                if(!ten[nums[k]]){
                    hasSame = false;
                    break;
                }
            }
            
            if(!hasSame){
                continue;
            }
            
            int count = 0;
            for(int j = 0;j < n; ++j){
                if(keys[j] < nums[i]){
                    count++;
                }else{
                    break;
                }
            }
            res += count*pow(n,m-1-i);
        }
        
        /*same*/
        hasSame = true;
        for(int i = 0; i < m; ++i){
           if(!ten[nums[i]]){
               hasSame = false;
           }
        }
        
        if(hasSame){
            res++;
        }
        
        return res;
        
    }
};
```