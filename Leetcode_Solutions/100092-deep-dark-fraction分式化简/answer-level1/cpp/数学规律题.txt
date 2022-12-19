借鉴了题解中 `不用约分` 和 `C++简单几行的规律题`

```
#include "LCP2.h"
#include<vector>
using namespace std;
class LCP2 {
public:
    vector<int> fraction(vector<int>& cont) {
        int up = cont[cont.size()-1], down = 1;
        for(int i=cont.size()-2;i>=0;i--){
            swap(up,down);
            up += down*cont[i];
        }
        return {up,down};
    }
};
```
