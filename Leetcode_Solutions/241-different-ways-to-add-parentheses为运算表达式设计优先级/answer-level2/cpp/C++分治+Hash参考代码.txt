分治思路各位大佬都讲得很清楚了，现在把我写的代码供大家参考
![image.png](https://pic.leetcode-cn.com/6d14ab60f39628cfd31f3264d76220f30e0b99b28021a7e76f7f404a3a403ad3-image.png)

```
class Solution {
private:
    vector<int> p(vector<string> &input, int l, int r, map<pair<int, int>,vector<int>> &h){
        pair<int, int> pr(l, r);
        if(h[pr].size())   return h[pr];
        vector<int> res;
        if(!(r-l))
            res.push_back(stoi(input[l]));
        else{
            for(int i = l+1; i <= r-1; i+=2){
                vector<int> a = p(input, l,i-1, h), b = p(input, i+1, r, h);
                for(auto m:a){
                    for(auto n:b){
                        if(input[i] == "+")
							res.push_back(m+n);
                        if(input[i] == "-")
                            res.push_back(m-n);
                        if(input[i] == "*")
                            res.push_back(m*n);
                        if(input[i] == "/")
                            res.push_back(m/n);
                    }
                }
            }
        }
        h[pr] = res;
        return res;
    }
public:
vector<int> diffWaysToCompute(string s) {
        vector<string> input;
        map<pair<int, int>,vector<int>> h;
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(s[i] <= '9' && s[i] >= '0')
                temp += s[i];
            else{
                input.push_back(temp);
				temp = "";
                temp += s[i];
                input.push_back(temp);
                temp = "";
            }
        }
		input.push_back(temp);
        return p(input, 0, input.size()-1, h);
    }
};
```
