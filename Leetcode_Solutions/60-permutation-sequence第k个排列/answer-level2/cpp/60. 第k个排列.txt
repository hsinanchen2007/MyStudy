n = 3,k = 3的时候
nums=[1,2,3]的数组全排列为
1. 123
2. 132  --- 1 * 2!
3. 213
4. 231  --- 2 * 2!
5. 312
6. 321  ----3 * 2!


循环：
    如果(i-1)*(n - 1)! < k <= i * (n - 1)!
    那个第一个数字就应该为nums[i - 1]
    将这个数剔除nums中:nums.erase(nums.begin() + (i - 1));
    k = k - (i - 1) * ( n - 1)!


```
class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        
        vector<int> nums;
        //将所有的数字都放在nums这个数组中
        for(int i = 1; i <= n; i++)
            nums.push_back(i);
        
        
        for(int j = 0; j < n; j++){
            int len = nums.size();
            //k如果（i-1）* (len - 1)!到i * (len - 1)!
            //那个str += nums[i - 1]; k -= (i - 1) * (len - 1)!
            for(int i = 1; i <= len; i++){
                int n = getMul(len - 1);
                if((i - 1)*n < k && k <= i * n){
                    char c = '0' + nums[i - 1];
                    res += c;
                    nums.erase(nums.begin() + (i - 1));
                    k -= (i - 1) * n;
                    break;
                }
            }
        }  
        return res;
        
    }
    //计算阶乘的函数
    int getMul(int n){
        int res = 1;
        for(int i = 2; i <= n; i++)
            res *= i;
        return res;
    }
};
```
