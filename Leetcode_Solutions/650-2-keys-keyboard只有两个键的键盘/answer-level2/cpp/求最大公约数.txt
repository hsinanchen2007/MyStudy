### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int minSteps(int n) {
         // 偶数
        // 求最大公倍数
        if(n==1) return 0;
        int count{0};
        int count2{0};
        int count3{0};
        int aa{0};
        vector<int> maxPubRes;
        while(true){
            aa = n;
            maxPubRes = maxPub(n);
            n = maxPubRes[0];
            if(n == aa){
                break;
            }
            
            count = count + maxPubRes[1];
        }
        if(count == 0) return n;
        if(count == 1){
            return 2 + n;
        }else{
            return count + n;
        }
        
    }

    vector<int> maxPub(int n){
        int maxPub{n};
        vector<int> res;
        for(int i =n-1; i>1; i--){
            if(n % i == 0){
                maxPub = i;
                break;
            }
        }
        res.push_back(maxPub);
        res.push_back(n/maxPub);
        return res;
    }
};
```