### 解题思路


### 代码

```cpp
class Solution {
    vector<string> res;
    void helper(string s,int n,string ip){
        if(n>4){
            if(s.empty()) res.push_back(ip);
            return;
        }
        else{
            
           for (int k = 1; k < 4; ++k) {
				if (s.size() < k) break;
				int val = stoi(s.substr(0, k));//字符串转数字
				//值大于255或者以0开头不符合IP规定,可以剪枝
				if (val > 255 || k != std::to_string(val).size()) continue; //ip条件，不大于255，且首位非0
              //注意每次往ip里push，但因为它有退回操作，所以要么放到helper里面，要么放到外面就要有退回的操作
				helper(s.substr(k), n + 1,ip + s.substr(0, k) + (n == 4 ? "" : ".") );
			}
        }
    }
public:
    vector<string> restoreIpAddresses(string s) {
        string ip;
        helper(s,1,ip);//s是当前字符串，是当前ip里面的个数，一共4个
        return res;
    }
};
```