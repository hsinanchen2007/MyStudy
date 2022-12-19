```cpp
class Solution {
public:
    int nextGreaterElement(int n) {
        std::string s=to_string(n);
        if (next_permutation(s.begin(), s.end())) {
            try{
                int n=stoi(s);
                return n;
            }catch(exception &e){
                return -1;
            }
            
        }else{
            return -1;
        }
        
    }
};
```