```
class Solution {
public:
    int gcd(int a,int b)
    {
        return b==0?a:gcd(b,a%b);
    }
    bool hasGroupsSizeX(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int x = 1, pos = 1, cnt = 1;
        int N = deck.size()-1;
        int num = deck[0];
        bool flag = false;
        if(N == 0) return false;
        while(N--)
        {
            if(deck[pos] != num)
            {
                if(flag && gcd(cnt, x) < 2) return false;
                x = cnt;
                flag = true;
                num = deck[pos];
                cnt = 1;
            }
            else{
                cnt ++;
                if(flag && pos==deck.size()-1 && gcd(cnt, x) < 2)
                    return false;
            }
            pos++;
        }
        return true;
    }
};
```
