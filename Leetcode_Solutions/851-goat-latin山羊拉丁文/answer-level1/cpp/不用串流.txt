执行用时 :0 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 :9.1 MB, 在所有 C++ 提交中击败了81.52%的用户

```
class Solution {
public:
    string toGoatLatin(string S) {
        
        string sample = {"aeiouAEIOU"};//元音字母表
        
        string temp = "";//临时存放转换前后的单词
        
        string output = "";//输出
        
        string A = "a";//用于统计转换后单词结尾a的个数
        
        
        
        for(int i=0; i<=S.length(); i++){//遍历字符串
            
            if(S[i]!=' ' && i!=S.length()){//如果还没碰到空格或字符串末尾
                
                temp += S[i];
            }
            else{
                
                //if(sample.find(tolower(temp[0]))!=sample.npos){//如果是元音字母
                if(sample.find(temp[0])!=sample.npos){//如果是元音字母
                    
                    output += temp + "ma" + A;
                }
                else{
                    temp += temp[0];
                    temp = temp.erase(0,1);
                    output += temp + "ma" + A;

                }
                
                if(i!=S.length())//每个单词之间要加空格
                    output += " ";
                
                A += "a";
                temp = "";
                    
            }
            
        }
        
        return output;
    }
};
```
