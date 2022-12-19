```
// 主要的思路：从最右边开始，当左边数比右边小的时候，将此数替换为右边数中第一个比他大的数
// 右边的剩余数(包含此数)一起进行升序排列，放到替换后的数后面，即满足题意
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = std::to_string(n);
        int len = s.length();
        int res = -1;
        priority_queue<char,std::vector<char>, std::greater<char>> min;
        for(int i = len-1;i>0;--i){
            min.push(s[i]);
            if(s[i-1]<s[i]){
                //找到最小栈中比当前数大的第一个数，其余数(包含当前数进行排序)
                vector<char> vc;
                while(min.top()<=s[i-1]){
                    vc.push_back(min.top());
                    min.pop();
                }
                vc.push_back(s[i-1]);
                s[i-1] = min.top();
                min.pop();//把当前栈顶弹不弹掉其实无所谓
                while(!min.empty()){
                    vc.push_back(min.top());
                    min.pop();
                }
                std::sort(vc.begin(),vc.end());
                for(int j = i;j < len;++j){
                    //重新赋值后面的
                    s[j] = vc[j-i];
                }
                if(s.length() >= 10){
                    string base = std::to_string(INT_MAX);
                    if(s > base) {
                        return -1;
                    }
                }
                res = stoi(s);
                break;
            }    
        }
        return res;
    }
};
```
