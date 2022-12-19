印刷得到的字的长度的范围为[1,所给字符串长度]，所以我们可以依次取不同长度去求字符串的全排列
```
class Solution {
public:
    int numTilePossibilities(string tiles) {
        int maxlen=tiles.size(),ans=0;
        sort(tiles.begin(),tiles.end());
        for(int len=1;len<=tiles.size();++len)
            permute(ans,tiles,0,tiles.size(),len,0);  
        return ans;
        
    }
    void permute(int& ans,string str,int left,int right,int len,int cur)
    {
        if(cur==len)
            ++ans;
        else
            for(int i=left;i<right;++i)
            {
                if(i>left&&str[i]==str[left])
                    continue;
                swap(str[left],str[i]);
                permute(ans,str,left+1,right,len,cur+1);
            }
    }
    
};
```