```cpp []
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> temp;
        stack<int> date;
        vector<int> diff;
        for (int i=0;i<T.size();i++){
            diff.push_back(0);
        }

        temp.push(T[0]);
        date.push(0);

        int size = T.size();
        for (int i = 1; i < size; i++) {
            if(!temp.empty()) {
                if(T[i]<temp.top()){ temp.push(T[i]); date.push(i);}
                else{
                    while(!temp.empty() && temp.top()<T[i]){
                        diff[date.top()] = i - date.top();
                        temp.pop();
                        date.pop();
                        /*
                         * 尝试通过stack date来判断每个未被处理
                         * 的温度的日期和当前日期差几天，从而确定
                         * 给diff的哪个位赋一个差值。
                         */
                        }
                    
                        temp.push(T[i]);
                        date.push(i);
                    }
                } else {temp.push(T[i]); date.push(i);}
        }

        return diff;
    }
};

```

空间耗的稍微多些，但是换来的是速度上的提升

