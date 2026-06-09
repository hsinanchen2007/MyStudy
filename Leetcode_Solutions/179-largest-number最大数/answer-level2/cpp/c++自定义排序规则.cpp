### 解题思路
1. 首先要明白排序规则是如何起作用的。简单说明: 如果要降序，那么`comp(n1, n2)`这个函数就要返回在`n1 > n2` 为真时返回`true`(或者直接`return n1 > n2`)。降序则是`return n1 < n2` 。
2. 此题要使得组合起来的数字为最大数，那么就要采取降序排列。根据1.说明的排序规则，要`return n1 > n2`，**即让组合的字符串最大时**`return true`。即下面的代码`if(temp1>temp2) return true;`(或者直接`return temp1 > tmep2`)
### 代码

```cpp
class Solution {
public:
    static bool comp(int& n1, int& n2){
        string str1 = to_string(n1);
        string str2 = to_string(n2);
        string temp1 = str1+str2;
        string temp2 = str2+str1;
        if(temp1>temp2) return true;
        else return false;
    }

    string largestNumber(vector<int>& nums) {
        bool flag = true;
        for(auto n: nums){
            if(n!=0)    flag = false;
        }
        if(flag) return "0";
        string result;
        sort(nums.begin(), nums.end(), comp);
        for(auto n: nums) {
            result += to_string(n);
            cout << n <<" ";
        }
        cout << endl;
        return result;
    }
};
```