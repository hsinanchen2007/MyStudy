```
    //思路：
    //   从左到右依次填充 重点是选择那个字母去填在当前答案串的尾部
    //策略：   
    //   每次都从可以选的字母中，选择剩余数最多的那个去填充 少的当隔板 从而使串最长 
    string longestDiverseString(int a, int b, int c) {
        string res;
        vector<pair<int,char>> nums{{a,'a'},{b,'b'},{c,'c'}};
        while(true){
            char ban = 'd';//尾部不能填的字母
            int  p = res.size();
            if(p >=2 && res[p-1]==res[p-2]) ban = res[p-1];//当已经有两个一样的了 则接下来不能填该数
            int idx = -1,maxx = 0;//剩余的最多的那个数的下标
            for(int i = 0; i < 3; i++){//寻找最大数
                if(nums[i].second==ban) continue;//不能填的数跳过
                if(idx==-1||nums[idx].first<nums[i].first){
                    idx = i;
                }
            }
            auto& [x,y] =  nums[idx];//y-当前要填的字母 x-该字母的剩余数量
            if(x==0) break;//此时没有可以填的字母了,结束过程
            res += y, x--;//尾部填一个
        }
        return res;
    }
```
