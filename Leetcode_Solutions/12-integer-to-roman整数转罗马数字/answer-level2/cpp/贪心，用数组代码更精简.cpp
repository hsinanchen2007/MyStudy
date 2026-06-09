思路：把罗马数字能直接表示的所有数的情况用数组表示出来，从大到小遍历使num能表示。
```
代码块
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        vector<int> nums = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
        vector<string> romans = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
        for(int i = nums.size()-1;i>=0;i--)
        {
            for(int j=0;j<num/nums[i];j++)
                s += romans[i];
            num %= nums[i];
        }
        return s;
    }
};

int main()
{
    int x;
    while(cin>>x)
    {
        Solution s;
        cout<<s.intToRoman(x)<<endl;
    }
    return 0;
}

```
