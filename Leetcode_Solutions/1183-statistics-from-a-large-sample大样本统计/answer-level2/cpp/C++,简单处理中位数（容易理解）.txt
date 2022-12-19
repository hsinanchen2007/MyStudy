```
typedef long long ll;
typedef double db;
class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int n=count.size();
        ll sum=0;
        int cnt=0,maxx=0,temp=0;
        int half=-1,halfcount=0;
        vector<int>res;
        res.reserve(256);
        for(int i=0;i<n;i++){
            if(count[i]==0)continue;
            res.push_back(i);
            sum+=count[i]*i;
            cnt+=count[i];
            if(count[i]>temp){
                temp=count[i];
                maxx=i;
            }
            while(halfcount==0||cnt/2>halfcount){
                half++;
                halfcount+=count[res[half]];//halfcount表式的含义是拥有多少个数据
            }
        }
        //下面是判断中位数的，因为上面的while操作，所以我们再进行中位数的判断会非常的容易。。。
        db med;
        if(cnt/2==halfcount){//这个表示的是，我们拥有偶数个数据
            med=(db)0.5*(res[half]+res[half+1]);
        }else{
            med=(db)res[half];
        }
        vector<db>ans;
        ans.push_back(1.0*res[0]);
        ans.push_back(1.0*res.back());
        ans.push_back(1.0*sum/cnt);
        ans.push_back(med);
        ans.push_back(1.0*maxx);
        return ans;
    }
};
```
