![image.png](https://pic.leetcode-cn.com/9ef503f0344e3a0bb9f5b80ac97526a36fdce3b07e87c1e97ae68e0655236db3-image.png)

思路：
（一开始太蠢了，把cmp改了又改，写了好几十行代码，最后灵光一闪，不如一行代码，要哭了）
把整形数组改成字符串数组，然后用sort+自定义cmp,
```
class Solution {
private:
static bool cmp(string a, string b){
    return a+b > b+a;
}
public:
    string largestNumber(vector<int>& nums) {
        string res;
        int falg = 0;
        vector<string> temp;
        for(auto i:nums)
            temp.push_back(to_string(i));
        sort(temp.begin(), temp.end(), cmp);
        for(auto i:temp)
            res += i;
        for(auto i:res){
            if(i != '0')
                return res;
        }
        return "0";
    }
};
```
