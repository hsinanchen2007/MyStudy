### 解题思路
四位，截取前0~3位,迭代判断是否合法

### 代码

```cpp
class Solution {
private:
    vector<string> res;
    vector<string> r;
public:
    void isVaild(string s,int count){
        if(count == 0 && s.size() == 0) {
            string str = "";
            for(int i=0;i<4;i++){
                str += res[i];
                if(i!=3) 
                    str+='.';
            }
            r.push_back(str);
            return ;
        }
        if(count == 0 || s.size() == 0) return;

        for(int i=1;i<=3 && i<=s.size();i++){
            string str = s.substr(0,i);
            //判断是否合法
            int sum = 0;
            for(int t =0;t<i;t++){
                sum=sum*10+(s[t]-'0');
            }
            if(sum>255 ||(sum == 0 && i>1)||(s[0] == '0' && sum!=0)) return ;
            //
            res.push_back(str);
            isVaild(s.substr(i),count-1);
            res.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        
        int n = s.size();
        isVaild(s,4);
        return r;
    }
};
```