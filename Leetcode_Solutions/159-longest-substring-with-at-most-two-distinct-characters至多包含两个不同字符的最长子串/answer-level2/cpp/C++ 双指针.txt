注意特殊输入：单个字符和空串(对于max_len的初值设置)
时间复杂度：O(n)
空间复杂度: O(1)

```
class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        char c_two[2];
        int index=0;
        int s_len=s.length();
        int len=1,max_len=s_len>0?1:0;
        c_two[0]=s[0];
        
        for(int i=1;i<s_len;i++){
            char tmp_c=s[i];
            // 重复:从i-1位置开始找到第一个与s[i-1]相同值的元素下标;
            if(tmp_c!=c_two[0] && tmp_c!=c_two[1]){
                int j;
                for(j=i-2;j>=0;j--){
                    if(s[j]!=s[i-1]){
                        break;
                    }
                }
                c_two[0]=s[j+1];
                index=j+1;
                
                c_two[1]=tmp_c;
                
            }
            
            len=i-index+1;
            max_len=len>max_len?len:max_len;
        }
        return max_len;
    }
};
```
