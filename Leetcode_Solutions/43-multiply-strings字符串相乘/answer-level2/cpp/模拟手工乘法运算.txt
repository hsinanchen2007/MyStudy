### 解题思路
模拟乘法运算：
999 * 999
8991
 8991
  8991
-------
998001

### 代码

```cpp
class Solution {
public:
string multiply(string num1, string num2) {
    vector<vector<int> > vec;
    if(num1 == "0" || num2 == "0")
        return "0";
    
    for(int i = num2.size() - 1; i >= 0; i--){
        vector<int> num;
        int carry = 0;
        for(int j = num1.size() - 1; j >= 0; j--){
            int a = num2[i] - '0';
            int b = num1[j] - '0';
            int c = a * b + carry;
            num.push_back(c % 10);
            carry = c / 10;
        }
        if(carry != 0)
            num.push_back(carry);
        vec.push_back(num);
    }


    for(int i = 1; i < vec.size(); i++){
        int carry = 0;
        int j = 0;
        while(j + i < vec[0].size()){
            int a = vec[0][j + i];
            int b = vec[i][j];
            int c = a + b + carry;
            vec[0][j + i] = c % 10;
            carry = c / 10;
            j++;
        }

        while(j < vec[i].size()){
            int c = vec[i][j] + carry;
            vec[0].push_back(c % 10);
            carry = c / 10;
            j++;
        }

        if(carry != 0)
            vec[0].push_back(carry);
    }

    //reverse(vec[0].begin(), vec[0].end());
    string str;
    while(!vec[0].empty()){
        int index = vec[0].size() - 1;
        str.push_back(vec[0][index] + '0');
        vec[0].pop_back();
    }

    return str;
}
};
```