```cpp

#include<iostream>
#include<vector>
using namespace std;

/**
*   题解：https://leetcode-cn.com/problems/counting-bits/solution/bi-te-wei-ji-shu-by-leetcode/
*/
class Solution {
public:
    vector<int> countBits(int num) {
        // 解空间
        vector<int> temp(num + 1);
        if(num >= 0) temp[0] = 0;
        if(num >= 1) temp[1] = 1;

        // count(x + b) = count(x) + 1 其中 b = 2^m > x
        int b = 2;
        int b2 = 3; // 4 - 1
        for(int i = 2; i <= num; i++){
            temp[i] = temp[i - b] + 1;
            if(i == b2){
                b = b2 + 1;
                b2 = 2*b2 + 1;
            }
        }

        return temp;
    }
};

int main(){

    Solution solu;

    vector<int> temp = solu.countBits(7);

    for(int i = 0; i <= 7; i++){
        cout<<temp[i]<<", ";
    }

    // 输出：0, 1, 1, 2, 1, 2, 2, 3,

    return 0;
}



```
