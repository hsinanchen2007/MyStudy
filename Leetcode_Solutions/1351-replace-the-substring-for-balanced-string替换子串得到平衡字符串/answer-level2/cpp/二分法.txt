```
class Solution {
public:
    int low,high,mid,top,len,res;
    int q,w,e,r;
    bool flag;
    char list[4] = {'Q','W','E','R'};
    unordered_map<char,int> presum[100005],sufsum[100005]; //前缀和和后缀和
    int balancedString(string s) {
        len = s.length();res = INT_MAX;
        top = len / 4;//元素最大值
        for(auto&it:list) presum[0][it] = 0;
        for(int i=1;i<=len;i++) {
            presum[i] = presum[i-1];
            presum[i][s[i-1]]++;
        }
        for(auto&it:list) if(presum[len][it]!=top) {flag=true;break;}
        if(!flag) return 0;//已经平衡
        for(auto&it:list) sufsum[len-1][it] = 0;
        sufsum[len-1][s[len-1]]++;
        for(int i=len-2;i>=0;i--) {
            sufsum[i] = sufsum[i+1];
            sufsum[i][s[i]]++;
        }
        for(int i=0;i<len;i++) {
            low = i;high = len-1;flag = false;
            for(auto&it:list) if(presum[i][it]>top) {flag=true;break;}
            if(flag) continue;
            while(low<high) {
                mid = (low+high) / 2;
                q = presum[i]['Q'] + sufsum[mid+1]['Q'];
                w = presum[i]['W'] + sufsum[mid+1]['W'];
                e = presum[i]['E'] + sufsum[mid+1]['E'];
                r = presum[i]['R'] + sufsum[mid+1]['R'];
                if(q>top||w>top||e>top||r>top) low = mid + 1;//向左逼近
                else high = mid;
            }
            q = presum[i]['Q'] + sufsum[low+1]['Q'];
            w = presum[i]['W'] + sufsum[low+1]['W'];
            e = presum[i]['E'] + sufsum[low+1]['E'];
            r = presum[i]['R'] + sufsum[low+1]['R'];
            if(q>top||w>top||e>top||r>top) flag = true;
            if(!flag) res = min(res,low-i+1);
        }
        return res;
    }
};
```
