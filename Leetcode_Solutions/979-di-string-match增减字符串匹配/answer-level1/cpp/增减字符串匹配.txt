【C++ ： 56 ms - 97.18% ，10.6 MB - 67.89% 】

I -> min，D -> max，依次寻找未使用的 max 或 min 。
```
class Solution {
public:
    vector<int> diStringMatch(string S) {
        vector<int> N;
        int max = S.length(),min = 0;
        
        for(char c : S){
            if(c=='I')  N.push_back(min++);
            else        N.push_back(max--);
        }
        N.push_back((min+min)/2);
        return N;
    }
};
```