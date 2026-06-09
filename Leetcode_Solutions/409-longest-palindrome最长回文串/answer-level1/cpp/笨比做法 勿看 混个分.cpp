### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int longestPalindrome(string s) {
        //遍历s每一个字符 ,存入map中
        unordered_map<char,int> count;
        int ans=0;
        for(char c:s){
            ++count[c];
        }
        //遍历map，如果value大于1 进行二次判断
        //如果为偶数 直接value加入
        //如果为奇数 value-1后加入

        //如果value值有奇数 在加1
        bool add =true;
        for(auto p:count){
            int value = p.second;
            if(value>1 && value%2==0){
                ans+=value;
            }else if(value >1 && value%2==1){
                ans+=(value-1);
            }
            if(value%2==1 && add){
                ans+=1;
                add = false;
            }
        }
        return ans;


    }
};
```