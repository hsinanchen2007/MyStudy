### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) {
            return 0;
        }
        int first = 0, count = 0, index = 0;
        for (int i = 0; i < chars.size(); ++i) {
            if (chars[i] != chars[first] || i == chars.size() - 1) {
                // if (i == chars.size() - 1) {
                //     LastTwoDiff(chars, index, first, i, count);
                //     return count;
                // }
                if (i == chars.size() - 1) {
                    LastTwoDiff(chars, index, first, i, count);
                    // Print(chars, index);
                    return count;
                }
                AddChars(chars, index, first, i, count);
                // Print(chars, index);
                first = i;
                i -= 1;
            }
        }
        return count;
    }
    void Print(vector<char>& chars, int index) {
        for (auto i = 0; i < index; ++i) {
            cout<<chars[i]<<" ";
        }
        cout<<endl;
    }
    void AddChars(vector<char>& chars, int& index, int first, int i, int& count) {
        int val = i - first;
        // cout<<i<<"  "<<first<<"  "<<chars[first]<<" |";
        chars[index] = chars[first];
        index += 1;
        count += 1;
        if (val > 1) {
            string str;
            while (val) {
                str.push_back(val % 10 + '0');
                count += 1;
                val /= 10;
            }
            cout<<str<<endl;
            for (int s = str.size() - 1; s >= 0; --s) {
                chars[index++] = str[s];
            }
        }
    }
    void LastTwoDiff(vector<char>& chars, int& index, int first, int second, int& count) {
        if (chars[first] == chars[second]) {
            AddChars(chars, index, first, second + 1, count);            
        } else {
            AddChars(chars, index, first, second, count);
            chars[index++] = chars[second];
            count += 1;
        }
    }
};
```