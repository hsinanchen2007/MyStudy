### 解题思路
1、将字符串入栈
2、获取栈顶字符串，如果字符串中包含.的个数小于3，依次在前一个.之后的1到3位数后加.，同时满足小于255，并依次入栈
如255.255255255 => 255.2.55255255,255.25.5255255,255.255.255255
3、当.的个数为3时，判断Ip地址最后一段的长度是否小于3，同时满足小于255， 不在0开头的多位数字，如255.255.255.09。
注意： 1)在加.时，如果当前数字为0，只入栈该字符串，1.00.255 格式不合法
       2)首入栈时，没有.，需要特殊处理加.的位置


### 代码

```cpp
class Solution {
public:
vector<string> restoreIpAddresses(string s) {
    vector<string> vec;
    stack<string> sk;

    sk.push(s);
    while(!sk.empty()){
        string str = sk.top();
        int cnt = count(str.begin(), str.end(), '.');
        sk.pop();

        int index = str.rfind('.');
        index = index != string::npos ? index : -1;
        if(cnt == 3){
            int len = str.size() - 1 - index;
            if((len > 1 && len <= 3 && str[index + 1] != '0' && atoi(str.substr(index + 1).c_str()) < 256) || len == 1){
                vec.push_back(str);
            }
        } else {
            string tmpStr = str;
            if(index + 1 < str.size()){
                sk.push(tmpStr.insert(index + 2, 1, '.'));
                if(str[index + 1] == '0')
                    continue;
                tmpStr = str;
            }

            if(index + 2 < str.size())
                sk.push(tmpStr.insert(index + 3, 1, '.'));

            if(index + 3 < str.size() && atoi(str.substr(index + 1, 3).c_str()) < 256)
                sk.push(str.insert(index + 4, 1, '.'));
        }
    }

    return vec;
}
};
```