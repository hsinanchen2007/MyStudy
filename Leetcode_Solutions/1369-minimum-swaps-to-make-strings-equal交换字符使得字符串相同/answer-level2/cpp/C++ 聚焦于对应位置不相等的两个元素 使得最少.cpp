```
    int minimumSwap(string s1, string s2) {
        int ans = 0, n = s1.size();
        int cnt1 = 0,cnt2 = 0;//统计有多少对x-y和y-x
        for(int i = 0; i < n; i++){
            if(s1[i]=='x'&&s2[i]=='y') cnt1++;
            else if(s1[i]=='y'&&s2[i]=='x') cnt2++;
        }
        //对于每一对 x-y 和 x-y 以及 y-x 和 y-x 都只需要一次操作即可完成匹配
        ans += cnt1/2+cnt2/2;//所需要的操作数
        cnt1%=2;//剩余未匹配的对数
        cnt2%=2;
        if(cnt1+cnt2==1) return -1;//只剩一个时无法匹配
        else if(cnt1+cnt2==2) ans+=2;//只剩了 x-y和y-x 需要两次匹配
        return ans;
    }
```
