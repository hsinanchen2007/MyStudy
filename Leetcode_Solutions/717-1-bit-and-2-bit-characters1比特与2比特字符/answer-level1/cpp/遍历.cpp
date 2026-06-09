```c++
class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        
        if(bits.size() == 1) return true;
        
        for(int i = 0; i < bits.size() ; i ++) {
            if(bits[i] == 0) continue;
            
            if(i + 1 < bits.size()) {
              if(bits[i] == 0 && bits[i + 1] == 0) {
                  i ++;
                  continue;
              } else if(bits[i] == 0 && bits[i + 1] == 1) {
                  continue;
              } else if (bits[i] == 1 && bits[i + 1] == 1) {
                  i ++ ;
                  continue;
              } else if (bits[i] == 1 && bits[i + 1] == 0) {
                  if(i + 1 == bits.size() -1 ) return false;
                  i ++;
                  continue;
              }
            } else {
                if(bits[i] == 1) return false;
                else return true;
            }
        }
        
        return true;
        
    }
};