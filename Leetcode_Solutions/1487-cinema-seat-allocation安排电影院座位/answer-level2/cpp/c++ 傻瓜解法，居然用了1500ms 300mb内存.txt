```
class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        sort(reservedSeats.begin(),reservedSeats.end(),[&](vector<int> a,vector<int>b)
        {   
            if(a[0]==b[0])
                return a[1]<b[1];
            return a[0]<b[0];
        }); //排序，按行优先排
        int num=0;int k=0;int a,b;map<int,int> mp;
        for(int i=0;i<reservedSeats.size();)
            {
                a=reservedSeats[i][0];
                mp[reservedSeats[i][1]]=1;
                if(a>k) {num+=(a-k-1)*2;k=a;} //当前行前面的空余行数*2；
                while(i+1<reservedSeats.size()&&reservedSeats[i+1][0]==a)
                {
                    mp[reservedSeats[i+1][1]]=1;
                    i++;
                }                             //当前行被占用的位置信息
                int f1=1,f2=1,f3=1,f4=1,f2_5=1,f4_7=1;// 4个标识符和2个前面是否已有人坐
                if(mp[2]==1||mp[3]==1) f1=0;
                if(mp[4]==1||mp[5]==1) f2=0;
                if(mp[6]==1||mp[7]==1) f3=0;
                if(mp[8]==1||mp[9]==1) f4=0;
                if(f1&&f2) {num++;f2_5=0;}
                if(f2&&f3&&f2_5) {num++;f4_7=0;f2_5=0;}
                if(f3&&f4&&f4_7) {num++;f4_7=0;}
                i++;
                mp.clear();
            }
        if(n>k) num+=(n-k)*2;   //后面空余的行数直接*2
            return num;
    }
};
```
