题目中已经给出的条件可以少进行一些判断，直接使用标准库的to_string和stoi进行整型字符串互转
```
class Solution {
public:
    int maximum69Number (int num) {
        std::string num_str = std::to_string(num);
        for (auto& c : num_str)
        {
            if (c == '6')
            {
                c = '9';
                break;
            }
        }

        return std::stoi(num_str);
    }
};
```
