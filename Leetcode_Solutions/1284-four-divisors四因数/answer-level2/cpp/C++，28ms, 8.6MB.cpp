### 解题思路
任意正整数，1和它本身一定是它的因数，所以这道题的意思是找到除了1和它本身这两个因数以外仅有的两个因数，并计算四个因数的和。
除了平方数（1,4,9,16......）以外,整数的因数都是成对出现的, 因数的个数一定是偶数个，完全平方数是奇数个。
![360截图20200322132405821.jpg](https://pic.leetcode-cn.com/2bd4ab70038eb5a496de1ab0bbcca580dc54c463b6e2c369cfdf70281905d470-360%E6%88%AA%E5%9B%BE20200322132405821.jpg)

### 代码

```cpp
class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(int num: nums){
            sum += sumoffourdivisors(num);
        }
        return sum;
    }
    int sumoffourdivisors(int num){
        if(num<2) return 0;
        int sum = 1 + num;
        int count = 2;
        for(int i = 2; i*i <= num; i++){
            if(num%i==0){
                if(num/i==i) return 0;
                sum += i + num/i;
                count += 2;
                if(count>4){
                    sum = 0;
                    return sum;
                }
            }
        }
        if(count<4)
            return 0;
        return sum;
    }
};
```