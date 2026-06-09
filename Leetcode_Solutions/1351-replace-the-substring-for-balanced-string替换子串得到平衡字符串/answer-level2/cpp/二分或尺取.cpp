法一：枚举一个端点，二分另一个端点，能过但不够优秀O(nlogn)
```
class Solution {
public:
    int need[8];
    int sum[8][100000];
    int getNum(char c)
    {
        switch(c)
        {
            case 'Q': return 0;
            case 'W': return 1;
            case 'E': return 2;
            default: return 3;
        }
    }
    bool OK(int l, int r)
    {
        for (int i = 0; i < 4; i++)
        {
            if (l == 0)
            {
                if (sum[i][r] < need[i]) return false;
            }
            else
            {
                if (sum[i][r] - sum[i][l-1] < need[i]) return false;
            }
        }
        return true;
    }
    int biSearch(int l, int r)
    {
        int sl = l;
        while (l < r)
        {
            int mid = (l+r) >> 1;
            //cout << sl << " " << mid << " " << OK(sl, mid) << endl;
            if (OK(sl, mid))
            {
                r = mid;
            }
            else 
            {
                l = mid+1;
            }
        }
        if (OK(sl, r)) return r;
        else return -1;
    }
    int balancedString(string s) {
        int cnt[8];
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        memset(need, 0, sizeof(need));
        int len = s.length();
        int ans = len;
        for (int i = 0; i < len; i++)
        {
            int num = getNum(s[i]);
            cnt[num]++;    
            sum[num][i]++;
            if (i == 0) continue;
            for (int j = 0; j < 4; j++)
            {
                sum[j][i] += sum[j][i-1];
            }
        }
        bool isBalence = true;
        for (int i = 0; i < 4; i++)
        {
            need[i] = max(0, cnt[i] - len/4);
            isBalence &= (need[i] == 0);
        }
        if (isBalence) return 0;
        //for (int i = 0; i < 4; i++) cout << need[i] << endl;
        for (int st = 0; st < len; st++)
        {
            int tmp = biSearch(st, len-1);
            //cout << st << " " << tmp << endl;
            if (tmp == -1) continue;
            else ans = min(ans, tmp-st+1);
        }
        return ans;            
    }
};
```

法二：尺取法（滑动窗口法），当前区间[l, r]， 满足条件l++, 缩短区间, 不满足r++考察更多字母
```
class Solution {
public:
    int need[8];
    int sum[8][100000];
    int getNum(char c)
    {
        switch(c)
        {
            case 'Q': return 0;
            case 'W': return 1;
            case 'E': return 2;
            default: return 3;
        }
    }
    bool OK(int l, int r)
    {
        for (int i = 0; i < 4; i++)
        {
            if (l == 0)
            {
                if (sum[i][r] < need[i]) return false;
            }
            else
            {
                if (sum[i][r] - sum[i][l-1] < need[i]) return false;
            }
        }
        return true;
    }
    int balancedString(string s) {
        int cnt[8];
        memset(sum, 0, sizeof(sum));
        memset(cnt, 0, sizeof(cnt));
        memset(need, 0, sizeof(need));
        int len = s.length();
        int ans = len;
        int l = 0, r = 0;
        
        for (int i = 0; i < len; i++)
        {
            int num = getNum(s[i]);
            cnt[num]++;    
            sum[num][i]++;
            if (i == 0) continue;
            for (int j = 0; j < 4; j++)
            {
                sum[j][i] += sum[j][i-1];
            }
        }
        bool isBalence = true;
        for (int i = 0; i < 4; i++)
        {
            need[i] = max(0, cnt[i] - len/4);
            isBalence &= (need[i] == 0);
        }
        if (isBalence) return 0;
        while(r < len)
        {
            if (OK(l, r)) 
            {
                ans = min(ans, r-l+1);
                l++;
            }
            else r++;
        }
        return ans;            
    }
};
```
