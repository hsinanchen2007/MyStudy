给出条件做判断，碰到e就全部重置，最后再判断一下冲突，一遍扫描

```
class Solution {
public:
    bool isNumber(string s) {
        int numCount = 0, eCount = 0, pointCount = 0, plusCount = 0;
        string temp = "0123456789";
        s.erase(0,s.find_first_not_of(" "));  
        s.erase(s.find_last_not_of(" ") + 1);
        vector<char> numVec(temp.begin(),temp.end());
        vector<char>::iterator it;
        for (int i = 0; i < s.size(); i++) {
            it = find(numVec.begin(),numVec.end(),s[i]);
            if (it != numVec.end()) {
                numCount++;
            } else if(s[i] == 'e') {
                eCount ++;
                if (eCount > 1) {
                    return false;
                }
                if (numCount == 0) {
                    return false;
                }
                numCount = 0;
                pointCount = 0;
                plusCount = 0;
            } else if(s[i] == '.') {
                pointCount++;
                if (pointCount > 1){
                    return false;
                }
            }else if (s[i] == '+' || s[i] =='-') {
                plusCount++;
                if (plusCount > 1 || numCount > 0 || pointCount > 0) {
                    return false;
                }
            } 
            else {
                return false;
            }
        }
        if (numCount == 0) {
            return false;
        }
        
        if (eCount > 0) {
            if (numCount == 0 || pointCount > 0 ){
                return false;
            }
        }
        return true;
    }
};
```
