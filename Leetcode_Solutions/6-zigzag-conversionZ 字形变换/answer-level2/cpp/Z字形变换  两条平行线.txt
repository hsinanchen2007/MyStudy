```
class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        int interval = 2 * numRows -2 ;
        int size = s.length();
        string result = "";
        for (int i = 0; i < numRows; i++) {
            int index2 = (numRows - i - 1) * 2 + i;            
            int temp = i;
            int temp1 = index2;   
            bool isIndex2 = false;
            if (index2 != interval && index2 != i) {
                isIndex2 = true;
            }

            if (isIndex2) {
                while(temp < size || temp1 < size) {   
                    if (temp < size){
                        result += s[temp];
                        temp += interval; 
                    }

                    if (temp1 < size) {
                        result += s[temp1];
                        temp1 += interval;
                    }   
                }  
                                    
            }     
            else {
                while(temp < size) {   
                    if (temp < size){
                        result += s[temp];
                        temp += interval; 
                    }
                }                  
            }
        }   
        
        return result;
    }
};
```
