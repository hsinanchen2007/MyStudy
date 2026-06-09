class Solution {
public:
    bool isNumber(string s) {
        if(s.empty())
            return false;
        string::iterator sIdx = s.begin();
        string::iterator sEnd = s.end();
        while(sIdx<sEnd && *sIdx==' ')
            sIdx++;
        while(sEnd>sIdx && *(sEnd-1)==' ')
            sEnd--;
        if(sIdx>=sEnd)
            return false;

        for(string::iterator s1=sIdx; s1!=sEnd; s1++){
            if(*s1==' ')
                return false;
        }
        bool r1 = scanSignedInteger(sIdx, sEnd);
        if(*sIdx=='.'){
            ++sIdx;
            //r1 = r1 || scanUnsignedInteger(sIdx, sEnd);
            r1 = scanUnsignedInteger(sIdx, sEnd) || r1;
        }
        if(*sIdx=='e'||*sIdx=='E'){
            ++sIdx;
            //r1 = r1 && scanSignedInteger(sIdx, sEnd); 
            r1 = scanSignedInteger(sIdx, sEnd)&&r1;
        }
        return r1&&(sIdx==s.end()||*sIdx==' ');
    }

    bool scanSignedInteger(string::iterator& sIdx, string::iterator& sEnd){
        if(*sIdx=='+'||*sIdx=='-'||*sIdx==' ')
            ++sIdx;
        return scanUnsignedInteger(sIdx, sEnd);
    }

    bool scanUnsignedInteger(string::iterator& sIdx,  string::iterator& sEnd){
        string::iterator before = sIdx;
        while(*sIdx>='0' && *sIdx<='9' && sIdx!=sEnd){
                ++sIdx;
        }
        return sIdx>before; // 存在数字
    }
};