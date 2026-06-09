**![微信图片_20191027214915.png](https://pic.leetcode-cn.com/c19532ed611f9b29e6c04e6cbf95f6e4718bfbe047fc52468033088795cd89a1-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87_20191027214915.png)**



```
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> vec;
        if(k>9 || k<1 || n>45)
            return vec;
        vector<int>tmp;
        recur(vec,tmp,k,1,n); 
        return vec;
    }
    
    bool recur(vector<vector<int>>&vec, vector<int> &v, int k,int curi, int res)
    {
        if(res==0 && k==0)
        {
            vec.push_back(v);
            return true;
        }           
        if( res<0 || (res<curi && res>0)||(k==0&& res>0))
            return false;
        else
        {
            
            for(int i=curi;i<=9;i++)
            {
                v.push_back(i);
                recur(vec,v,k-1,i+1, res-i);
                v.pop_back();        
            }
            return false;
        }
    }
    
    
};
```
