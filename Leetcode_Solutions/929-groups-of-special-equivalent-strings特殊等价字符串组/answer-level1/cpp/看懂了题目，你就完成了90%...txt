```
class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        
        //题目里的意思是A中的字符串自身奇数位或偶数位的字符经过若干次交互后如果相同，则归为一组
        //建议出题的人重修小学语文...
        
        set<string> count;
        
        for(int i=0; i<A.size(); i++){
            
            string odd = "";//临时存储奇数位字符
            string even = "";//临时存储偶数位字符
            
            for(int j=0; j<A[0].size(); j++){
                //遍历容器，把每个字符串都分别拆分为奇数位的字符集合和偶数位的字符集合
                
                if(j%2 == 1)
                    odd += A[i][j];
                else if(j%2 == 0)
                    even += A[i][j];
            }
            
            sort(odd.begin(),odd.end());//将拆分出来的奇偶字符串排序
            sort(even.begin(),even.end());
            
            count.insert(odd+even);//合并后塞入集合
        }
        
        return count.size();
        
    }
};
```
