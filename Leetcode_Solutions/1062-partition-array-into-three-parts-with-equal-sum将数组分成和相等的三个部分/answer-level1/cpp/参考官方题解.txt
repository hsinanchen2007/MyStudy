```
class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int s = 0;
        for(auto a:A) s += a;
        s = s / 3;

        int pos = 0, count = 0;
        for(auto a:A){
            count += a;
            if(count==s && pos==1)  // 求得第二段的和
                return true;
            if(count==s){  // 求得第一段的和
                pos = 1;
                count = 0;
            }
        }
        return false;
    }
};
```
