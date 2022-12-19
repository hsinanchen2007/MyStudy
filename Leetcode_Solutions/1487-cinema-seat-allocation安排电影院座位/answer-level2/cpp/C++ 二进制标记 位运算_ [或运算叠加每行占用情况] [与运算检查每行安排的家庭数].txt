```
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        unordered_map<int,int> mp;//存储每一行的占用情况 若被预约 该位为1
        for(int i = 0; i < rs.size(); i++){
            int x = rs[i][0], y = rs[i][1];//行x 列y
            mp[x] |= 1<<(y-1);//记录x行的y列被占用
        }
        int res = 2*n;//假设每行都能安排两个 
        int l = (1<<5)-1 - 1;//左边安排时 0000011110       注意低位在右
        int r = ((1<<9)-1) - ((1<<5)-1);//右边安排时 0111100000
        int mid1 = ((1<<7)-1)-((1<<3)-1);//中间安排一个时0001111000
        int mid2 = (1<<9)-1 - 1;//中间安排两个时 0111111110
        for(auto v : mp){
            res -= 2;//该行重新算
            int x = v.second;//该行的占用情况
            if((x&mid2)==0) res+=2;//该行可以安排两个时
            else if((x&l)==0||(x&mid1)==0||(x&r)==0) res++;//该行可以安排一个时
        }
        return res;
    }
```
