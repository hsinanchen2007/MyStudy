### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    void dfs(string s, int pos, vector<string>& cur) { //cur={"255","255","11","135"}cur为切割好的字符串

        if (pos == s.size() && cur.size() >= 4){ 
            string joint;
            for(string it : cur){ //将cur中切割好的字符串连接起来
                joint = joint +  "." + it;
            }
            joint = joint.substr(1); //去掉第一个多余的.
            res.push_back(joint);
            return;
        }
        
        for(int i = 1; i <= 3; i++) { //每一个ip段最多占3个位置  这个循环里面是负责每一次（一共有4次）分割有效字符串
            if(pos + i > s.size()) //回溯算法要留个裕量，会走到s.size()，pos + i = s.size()也是正常情况,给他一个回退的机会,体会这一步很关键
                break;
            string tmpStr = s.substr(pos,i);
            int tmpInt = stoi(tmpStr);


            if (tmpInt > 255 || ( tmpStr.size() > 1 &&  tmpStr[0] == '0') ) {   //剪枝，分割字符串大于255的或者以0开头的字符串
                break;
            }

            if (cur.size() < 4){ //如果cur中已经存了大于或等于4个字符串，就不要再dfs到下一层了
                cur.push_back(tmpStr);
                dfs(s, pos + i, cur);
                cur.pop_back();
            }
        }                                                                    

    }





    vector<string> restoreIpAddresses(string s) {
        vector<string> cur;
        dfs(s, 0, cur);
        return res;
    }

private:
    vector<string>res;
};
```