## 思路：双指针
**注意：重复字符个数大于10，转为字符串处理**
### 代码
```c++
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;
        int size = chars.size();       
        int k = 0;
        for (int i = 0, j; i < size; i = j) {//重定位下一个不同字符i = j
            int cnt = 0;    
            //统计重复字符个数        
            for (j = i; j < size; ++j) {
                if (chars[j] != chars[i]) {
                    break;
                }
                ++cnt;
            }
            chars[k++] = chars[i];
            //如果个数大于1，则设置个数
            if (cnt > 1) {          
                string numStr = to_string(cnt);      
                for (int t = 0; t < numStr.size(); ++t) {
                    chars[k++] = numStr[t];
                }                              
            }
        }
        return k;
    }
};
```
#### 另一种代码
```c++
class Solution {
public:
    int compress(vector<char>& chars) {
        if (chars.empty()) return 0;
        int size = chars.size();       
        int k = 0;
        for (int i = 0, cnt = 1, j; i < size; ++i, ++cnt) {
            if (i + 1 == size || chars[i] != chars[i + 1]) {
                chars[k++] = chars[i];
                if (cnt > 1) {
                    for (char c : to_string(cnt)) {
                        chars[k++] = c;
                    }
                }
                cnt = 0;
            }            
        }
        return k;
    }
};
```

