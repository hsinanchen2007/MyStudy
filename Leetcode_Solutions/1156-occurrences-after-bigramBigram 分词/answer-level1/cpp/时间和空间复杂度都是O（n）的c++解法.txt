算法题还是不建议用诸如find()和substr()的高级函数，尽可能自己编写算法。



执行用时 :8 ms, 在所有 C++ 提交中击败了30.41%的用户
内存消耗 :8.5 MB, 在所有 C++ 提交中击败了100.00%的用户



```
class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        
        
        string temp;
        
        vector<string> pool;
        vector<string> output;
        
        for(int i=0; i<=text.length(); i++){//先把text以" "为分隔拆分成一组vector
            
            if(text[i]!=' ' && text[i]!='\0'){
                
                temp.push_back(text[i]);
            }
            else{
                pool.push_back(temp);
                temp = "";
            }
        }
        
        for(int i=0; i+1<pool.size(); i++){//遍历重组的vecotr 保存first和second后面的那个字符串
            
            if(pool[i]==first && pool[i+1]==second && i+2<pool.size())
                output.push_back(pool[i+2]);
        }
        
        
        
        return output;
        
    }
};
```
