### 解题思路
维护一个单调栈，每次新进来的元素比栈顶小，就将栈顶弹出
注意这里是要保证新进来的数是最小的，因此要一直弹

所有的元素都要入栈比较一遍

### 代码

```cpp
// #include<iostream>
// #include<string>
// #include<vector>
// #include<stack>
// #include<algorithm>
// using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>mystack;
        string result;
        for (int i = 0; i < num.size(); i++) {
            while (!mystack.empty() && k > 0 && mystack.top() > num[i]) {  // 新进来的元素比栈顶小。将栈顶弹出，一直弹直到栈顶大于新进来的元素（所以要用while）
                mystack.pop();
                k--;
            }
            mystack.push(num[i]); //所有的元素都会先存一遍再比较
        }
        while (k > 0) {  //从前到后遍历一遍k还没有移除完，就要从后到前遍历，也就是继续弹栈顶较大的元素
            mystack.pop();
            k--;
        }
        while (!mystack.empty()) {  //将mystack中的元素倒序存到结果里
            result += mystack.top();
            mystack.pop();
        }
        reverse(result.begin(), result.end());
        while (!result.empty() && result[0] == '0') { //  前面可能不止一个0，所以要用while一直删
            result.erase(result.begin());
        }
        return result.empty() == 1 ? "0" : result;
    }
};

// int main()
// {
//     int cnt =1;
//     string numStr = "10200";
//     Solution s;
//     string result = s.removeKdigits(numStr, cnt);
//     cout << "The result is " << result << endl;
//     system("pause");
//     return 0;

// }