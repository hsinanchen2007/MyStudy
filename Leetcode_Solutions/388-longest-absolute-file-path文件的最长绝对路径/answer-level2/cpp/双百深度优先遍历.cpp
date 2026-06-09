# Solution0
思路是逐层遍历字符，每层开始的\t个数即层数，栈v用于保存当前的各层长度（记得加上“/”哦）。此法相当于深度优先遍历。
```C++
class Solution {
public:
    int sum(vector<int>& v){
        int n = 0;
        for(int i:v)
            n += i;
        return n;
    }
    int lengthLongestPath(string input) {
        const int length = input.size();
        vector<int> v;
        bool cal = false;
        int level = 0;
        int det = 0;
        int answer = 0;
        int j=-1;
        for(int i=0;i<length;){
            while(input[i]=='\t')
                ++i;
            level = i-j-1;
            det = v.size() - level;
            for(j = 0;j<det;++j)
                v.pop_back();
            for(j = i;j<length&&input[j]!='\n';++j)
                if(input[j]=='.')
                    cal = true;
            v.push_back(level?j-i+1:j-i);
            level = 0;
            if(cal){
                answer = max(answer, sum(v));
                cal = false;
            }
            i = j + 1;
        }
        return answer;
    }
};
```
![MrHuangIsShowingOff.png](https://pic.leetcode-cn.com/d8a3a89a1c68d271abecfed55a95a7042e6bc8bc03b81b95128dfed4e4fe4aa2-%E4%BC%81%E4%B8%9A%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_8e735450-1d04-44f8-aa51-dcbe41343e9e.png)