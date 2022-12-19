### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int a[1000]={0};
        int n = answers.size();
        int sum = 0;
        int s;
        for(int i = 0; i < n; i++){
            s=answers[i];
            a[s]++;
            if(a[s]==1) sum = sum + s + 1;
            if(a[s]> s) {
                a[s]=0;
            }
        }
        return sum;
    }
};
```