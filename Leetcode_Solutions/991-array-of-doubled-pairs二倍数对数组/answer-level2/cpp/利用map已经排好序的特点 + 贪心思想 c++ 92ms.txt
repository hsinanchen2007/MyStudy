将原来数组里面的数字拆分成 正数集 和 负数集
可以将负数集合里面的数全部转化为正数，这样子会更简单一点

然后利用map自动排序的特点，核心就是贪心思想，从小到大一个一个找过去。
```
class Solution {
    
public:
    bool handle(map<int,int>& A){
        for(auto emun : A){
            if(emun.second == 0) continue;
            int num = emun.first;
            A[num*2] -= emun.second;
            if(A[num*2] < 0) return false;
        }
        return true;

    }
    bool canReorderDoubled(vector<int>& A) {
        
        map<int,int> positive;
        map<int,int> negative;
        int zero_count = 0;
        
        for(auto a:A){
            if(a > 0) positive[a]++;
            else if(a < 0) negative[-1*a]++;
            else zero_count++;
        }
        if(zero_count % 2) return false;

        return handle(positive)&&handle(negative);
    }
};
```

