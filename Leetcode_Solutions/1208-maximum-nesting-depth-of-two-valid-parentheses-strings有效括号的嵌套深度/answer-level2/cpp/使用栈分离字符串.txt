```
class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {

        vector<int> result;
        //将栈简化为数字
        int A =0;
        int B = 0;
        
        for(int i = 0 ;i < seq.size();i++)
        {
            if(seq[i] == '(')
            {
                if(A==0 || A <= B)
                {
                    A++;
                    result.push_back(0);
                }else
                {
                    B++;
                    result.push_back(1);
                }
            }else
            {
                if(A >=B)
                {
                    A--;
                    result.push_back(0);   
                }else
                {
                    B--;
                    result.push_back(1);
                }
            }
        }
        return result;
    }
};
```
