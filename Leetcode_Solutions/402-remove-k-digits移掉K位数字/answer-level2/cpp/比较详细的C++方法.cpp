### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    string removeKdigits(string num, int k) {
        //从左到右扫描，遇到的第一个递减的数就删掉
        //当全部扫描完却还没有删满K个时，说明字符都是递增排列，直接删去末尾的几个即可
        if(num.size()==k) return "0";
        stack<char> mystk;
        string res;
        for(int i=0;i<num.size();i++){
            //栈内有数据，且字符出现递减，且K>0
            while(!mystk.empty() && num[i]<mystk.top() && k>0){
                mystk.pop();
                k--;
            }
            mystk.push(num[i]);//不论是否删去了，都要存入这次扫描的数据
        }
        //扫描完成后还没删完，说明全部递增排列，直接删去末尾数据
        while(k){
            mystk.pop();
            k--;
        }
        while(!mystk.empty()){  //栈转为字符串(此时是倒序的)
            res+=mystk.top();
            mystk.pop();
        }
        while(!res.empty() && res[res.size()-1]=='0')//删去0200中2前的0
            res.pop_back();
        reverse(res.begin(),res.end());
        if(res.size()==0) res="0";
        return res;
    }
};
```