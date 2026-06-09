```
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int now = 1;
        int cnt = 0;
        while(cnt++ < n){
            ans.push_back(now);
            int t1 = now * 10;
            if(t1 <= n){
                //屁股（个位）后边加一位
                now = t1;
            }
            else{
                //减少一位，检查个位是否小于9，满足则加一
                int back = now % 10;
                while(back >= 9 || now+1 > n){
                    now /= 10;
                    back = now % 10;
                }
                ++now;
            }
        }
        return ans;
    }
};
```
