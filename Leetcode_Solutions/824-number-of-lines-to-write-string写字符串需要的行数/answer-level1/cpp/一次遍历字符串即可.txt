执行用时 :4 ms, 在所有 C++ 提交中击败了89.04%的用户
内存消耗 :8.4 MB, 在所有 C++ 提交中击败了93.94%的用户

```
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        
        int line = 0;//需要的行数
        int last_line_unit = 0;//最后一行的单位数
        int units = 0;//每行占用的单位数
            
        vector<int> output;    
            

        for(int i=0; i<S.length(); i++){
            
            if(units + widths[S[i]-'a'] <= 100)
                units += widths[S[i]-'a'];//如果某行占用的单位数不超过100，则可以在该行继续添加单位
            else{
                //如果某行不足以继续添加新的字符，则必须另起新行
                line += 1;
                units = widths[S[i]-'a'];
            }
        }

        last_line_unit = units;
        
        if(units!=0)//如果最后一行的单位数不为0，则统计的行数要继续加1
            line += 1;

        
        output.push_back(line);
        output.push_back(last_line_unit);
        
        return output;
    }
};
```
