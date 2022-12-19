- 从后往前移位，当前要移位的次数等于当前值加前一个值
``` C++
class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        if(S.empty()) return S;
        if(S.size()!=shifts.size()) return S;
        int pre=0;
        int index=shifts.size()-1;        
        while(index>=0)
        {
            int temp=(shifts[index]+pre)%26;//对26取余，否则数过大
            pre=temp;;
            S[index]=S[index]+temp<='z'?S[index]+temp:'a'+S[index]+temp-'z'-1;//区分不超过‘z’及超过‘z’    
            index--;
        }
        return S;
    }
};
```