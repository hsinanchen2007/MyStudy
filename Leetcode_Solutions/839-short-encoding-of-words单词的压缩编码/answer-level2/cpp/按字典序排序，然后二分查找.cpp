### 解题思路
此题的数据特点为，单个字符串较短，但字符串总数较多，因此主要的花销应该是在查找是否可以压缩的字符串上，因此利用二分查找减少查找的开销。
1. 每次插入新的字符串的时间复杂度最坏是logn，总的时间复杂度o(nlogn)
2. 建立字典需要n个数据长度的空间，总空间复杂度为o(n)

### 代码

```cpp
class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        vector<int> dir;
        for (size_t i = 0; i < words.size(); i++) {
            join(words, dir, i);
        }

        int ret = 0;
        for (size_t i = 0; i < dir.size(); i++) {
            ret += words[dir[i]].size() + 1;
            //输出词典
            // cout << words[dir[i]] << endl;
        }
        // cout << ret;
        return ret;
    }


    // 如果str1 < str2 返回-1， 如果大于返回-2， 如果可以合并，返回短的那个字符串的长度
    int ifMerge(string& str1, string& str2)
    {
        int l1 = str1.size(), l2 = str2.size();
        int n = min(l1, l2);

        //逆序逐位比较
        for (int i = 1; i < n + 1; i++)
        {
            if (str1[l1 - i] < str2[l2 - i]) return -1;
            if (str1[l1 - i] > str2[l2 - i]) return -2;
        }
        
        return n;
    }

    //向词典中中加入新的单词，如果可以压缩，保留最长的那个在词典中
    void join(vector<string>& words, vector<int>& dir, int n)
    {
        // cout << "join" << endl;
        //如果是空字典，则直接加入
        if (dir.size() == 0)
        {
            dir.push_back(n);
            return;
        }
        int  r = dir.size() - 1; //字典最后一个词的索引
        string newStr = words[n];
        //判断是否要插入两端
        if (ifMerge( newStr, words[dir[0]]) == -1) {
            dir.insert(dir.begin(), n);
            return;
        }
        if (ifMerge(newStr, words[dir[r]]) == -2) {
            dir.push_back(n);
            return;
        }
        
        //二分查找
        int l = 0;
        //将最终结果锁定在两个字符串之间
        while (l < r-1) {
            int cur = (l + r) / 2;
            // cout << "cur = " << cur << "dir[cur] = " << dir[cur] << endl;
            int temp = ifMerge(newStr, words[dir[cur]]);
            switch (temp)
            {
            case -1:
                r = cur;
                break;
            case -2:
                l = cur;
                break;
            default:
                if (temp > words[dir[cur]].size()) {
                    dir[cur] = n;
                }
                return;
                break;
            }
        }
        //判断是否可以与区间端点合并，否则将新字符串插入区间中
        for (int i : {l, r}) {
            int temp = ifMerge(newStr, words[dir[i]]);
            if (temp > 0) {
                if (temp == words[dir[i]].size()) {
                    dir[i] = n;
                }
                return;
            }
        }
        
        dir.insert(dir.begin() + r, n);

    }
};
```