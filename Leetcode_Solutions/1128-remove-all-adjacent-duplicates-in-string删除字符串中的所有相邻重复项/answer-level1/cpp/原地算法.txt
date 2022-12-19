```
class Solution {
public:
    string removeDuplicates(string S) {
        
        //原地算法
        
        int len = 0;//返回字符串的长度（返回区间）
        
        for(int i=0; i<S.length(); i++){
            
            if(len==0 || S[len-1]!=S[i]){//如果返回区间最后一个字母和新探索到的字母不等，则返回区间长度加一，新探索的的字母通过交换加入到返回区间末位
                
                S[len] = S[i];
                len++;   
            }
            else//如果返回区间的最后一个字母和新探索到的字母相同，则返回区间长度减一
                len--;  
        }
        
        S.resize(len);
        
        return S;
    }
};
```
