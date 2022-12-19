

### 代码

```cpp
#include <string>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long result;
        string temp = "";
        temp = to_string(x);
        if(x<0) std::reverse(temp.begin()+1,temp.end());
        else std::reverse(temp.begin(),temp.end());

        result = stol(temp);
        if(result<2147483647&&result > -2147483648) return result;
        else return 0;
    }
};
```