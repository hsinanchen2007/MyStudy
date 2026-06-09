### 解题思路
举例[30,20,150,100,40]

### 代码
```cpp
class Solution {
public:

    //2次遍历
    int numPairsDivisibleBy60(vector<int>& time) {
        int rs = 0;
        vector<int>hash(60); //0-59
        for (int num : time) {
            hash[num%60]++;
        }
        //20 30 40
        //1  2  2
        for (int num : time) {
            //遍历到一个数字 就让他-1，因为已经被用过了  比如20和40匹配   后面避免40和20匹配
            int mod = num % 60;
            hash[mod]--;
            int target = mod == 0 ? 0 : 60 - mod;
            rs += hash[target];
        }
        return rs;
    }
    
    //1次遍历
    //天然有序了  因为从左向右遍历
    int numPairsDivisibleBy60(vector<int>& time) {
        int rs = 0;
        vector<int>hash(60); //0-59
        for (int num : time) {
            int mod = num % 60;
            //target ->  60-mod的下标  如果60-mod存在 则满足题意  +1
            //如果 mod = 0 不能60-mod了 换成0 下次找0
            int target = mod == 0 ? 0 : 60 - mod;
            //当第一次遍历到30的时候，hash[30] = 0，当都二次遍历到30的时候，hash[30] = 1
            //所以2个30，只被加了一次
            rs += hash[target];
            hash[mod]++;
        }
        return rs;
    }
};
```