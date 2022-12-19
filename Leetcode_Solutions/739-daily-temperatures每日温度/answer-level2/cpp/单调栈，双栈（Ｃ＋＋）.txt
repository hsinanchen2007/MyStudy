执行用时 :224 ms, 在所有 C++ 提交中击败了98.57%的用户
内存消耗 :14.9 MB, 在所有 C++ 提交中击败了86.73%的用户

思路：维持一个单调递减栈ｓｔ1（从栈底到栈顶单调递减）来寻找下一个最大元素；同时维持一个与st1每一个元素一一对应的栈st2来记录天数——就是最终返回的那个天数，代表还有多少天达到更高的温度。
```
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st1;
        stack<int> st2;//保存st1对应的天数
        vector<int> results(T.size());
        for(int i=T.size()-1;i>=0;i--){
            int days=1;
            while(!st1.empty()&&st1.top()<=T[i]){
                st1.pop();
                days+=st2.top();
                st2.pop();
                
            }
            results[i] = st2.empty()? 0:days;
            st1.push(T[i]);
            st2.push(days);
          
        }
        return results;

    }
};
```
