主要注意编码长度限制

```
class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int n = data.size();
        for(int i=0;i<n;i++) {
            // 查找前缀1个数
            int ans = 0;
            for(int j=7;j>=0;j--) {
                if((data[i]>>j)&1) ans++;
                else break;
            }
            // cout<<i<<ans<<endl;
            if(ans==0) continue;
            // 个数不能为1，不能大于4，不能超过数组长度
            if(ans==1 || ans>4 || i+ans>n) return false;
            // 依次判断前缀
            for(int j=1;j<ans;j++) {
                if((data[i+j]>>6)!=2) return false;
            }
            i += ans-1;
        }
        return true;
    }
};
```
