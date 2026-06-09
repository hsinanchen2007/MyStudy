### 解题思路
此处撰写解题思路
抄的别人的思路和代码，中国大学MOOC郭炜
### 代码

```cpp
class Solution {
public:
    int getBit(char c,int i)
    {
        return (c>>i)&1;
    }
    void setBit(char& c,int i,int v)
    {
        if(v)
            c|=(v<<i);
        else
            c&=~(1<<i);
    }
    void flipBit(char& c,int i)
    {
        c^=(1<<i);
    }
    
    int minFlips(vector<vector<int>>& mat) {
        int res=-1;
        int m=mat.size();
        int n=mat[0].size();
        char oriLights[m];
        char lights[m];
        char result[m];
        char switchs;        
        memset(oriLights,0,sizeof(oriLights));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                setBit(oriLights[i],j,mat[i][j]);
            }
        }
        for(int k=0;k<pow(2,n);++k){
            switchs=k;
            memcpy(lights,oriLights,sizeof(oriLights));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;++j){
                    if(getBit(switchs,j)){
                        flipBit(lights[i],j);
                        if(j>0){
                            flipBit(lights[i],j-1);
                        }
                        if(j<n-1){
                            flipBit(lights[i],j+1);
                        }
                    }
                }
                if(i<m-1){
                    lights[i+1]^=switchs;
                }
                result[i]=switchs;
                switchs=lights[i];
            }
            if(switchs==0){
                int tmp=0;
                for(int i=0;i<m;++i){
                    for(int j=0;j<n;++j)
                    {
                        tmp+=getBit(result[i],j);
                    }
                }
                if(tmp>res){
                    res=tmp;
                }
            }
        }
        return res;
    }
};
```