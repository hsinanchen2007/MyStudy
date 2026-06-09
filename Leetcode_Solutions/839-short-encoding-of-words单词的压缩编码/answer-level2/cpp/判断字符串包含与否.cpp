### 解题思路
此处撰写解题思路

所谓的字符压缩，指的字符串有重叠部分，并且有共同的结尾；要使压缩后的字符长度最短，肯定是要使某个字符串包含的子串尽可能的多

1、直观的暴力解法
   》 按长度进行排序，以当前元素为基准，判断后续元素是否被包含其中
   》 然后以下一个元素为基准进行遍历
   》 会超时

2、同样思考一个问题，上面超时主要是每次都要找下一个被包含的元素在哪？ 
   如果多个字符串被包含，那么这些元素的结尾必然是相同的；将这些元素逆序后，
   再进行一次排序，那么这些元素必然是相邻的。
   
   这个时候，需要找的元素都相邻了，就方便判断了，大大节省了时间；

   


### 代码

```cpp
    static bool cmp(string& a, string& b) 
    {
        if (a.size() <= b.size()) {
            return false;
        }

        return true;
    }

    

class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<string> str = words;
        if (str.size() == 1) {
            return str[0].size() + 1;
        }

        for (int i = 0; i < str.size(); i++) {
            string tmp = str[i];
            reverse(tmp.begin(), tmp.end());
            str[i] = tmp;
        }

        sort(str.begin(), str.end());
        int len = 0;
        int cnt = 0;
       
        for (int i = 0; i < str.size() - 1; i++) {
            int tmpLen = str[i].size();
            if (str[i + 1].substr(0, tmpLen) == str[i]) {
                continue;
            }
            cnt++;
            len += str[i].size();
        }
       // 最后一个元素要放进去，理由如下：
       // 如果最后一个元素包含前一个元素，则在上面的循环处理中是没有增加最后的元素 
       // 如果最后一个元素不包含前一个元素,上面的循环存储的是最后一个元素之前的元素
        cnt++;
        len += str[str.size() - 1].size();
     
        return len + cnt;
  #if 0
        sort(str.begin(), str.end(), cmp);
        vector<int> flag(str.size(), 0);
        vector<string> res;
        int len = 0;
  
        //flag[0] = 1;
        for (int i = 0; i < str.size(); i++) {
            if (flag[i] == 0) {
                res.push_back(str[i]);
                len += str[i].size();
                flag[i] = 1;
            
                for (int j = i + 1; j < str.size(); j++) {
                    if (flag[j] == 0 && IsValid(str[i], str[j])) {
                        flag[j] = 1; // 改元素已被访问 
                    }
                }
            }
            
        }

        return len + res.size();

   #endif      


        
    }

    // 判断字符串a中是否包含b,
    bool IsValid(string a, string b) 
    {
        //if (a.size() < b.size()) {
         //   return false;
       // }

        int i = a.size() - 1;
        int j = b.size() - 1;
        // 从后往前进行比较 
        while (i >= 0 && j >= 0) {
            if (b[j] != a[i]) {
                return false;
            }
            j--;
            i--;
        }

        return true;
    }


};
```