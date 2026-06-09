我的思路比较简单，先在s中找到所有t中字母的索引，保存起来放到lookup里面。

然后找到一组(长度为t)可用的非重复的索引值。找到当前组中的最小与最大值，(差值 + 1)就是最终字符串的长度，起始位置为最小值。

找一组数据的时候需要过滤掉重复的元素，因为重复的元素的索引在lookup中是相同的。

```c++
string minWindow(string s, string t) {
        int len_s = s.size();
        int len_t = t.size();

        if (0 == len_s || 0 == len_t || len_s < len_t) return "";

        int pos = 0;
        vector<vector<int>> lookup(len_t, vector<int>());   // t中所有字母在s中的索引集合 [t中的下标，t中下标对应字母在s中的集合]
        for (int i = 0; i < len_t; ++i) {
            pos = s.find(t[i]);
            if (string::npos == pos) {  // 如果没找到 说明t中存在s中找不到的字母 直接结束
                return "";
            } else {
                while (pos != string::npos) {
                    lookup[i].push_back(pos);
                    pos = s.find(t[i], pos + 1);
                }
            }
        }

        vector<int> pos_vec(len_t, 0);              // lookup中每个字母查找的进度
        unordered_map<int, int> start_umap;         // <s中的下标, pos_vec中的下标(用来找到当前组中最小的值)>
        std::pair<unordered_map<int, int>::iterator, bool> upr;
        unordered_map<int, int>::iterator it_umap;
        unordered_map<int, int>::iterator it_umap_erase;
        
        bool loop_flag = true;
        for (int i = 0; i < len_t; ++i) {
            while (pos_vec[i] < lookup[i].size()) {
                pos = lookup[i][pos_vec[i]];        // 找到可用的s中的下标
                upr = start_umap.insert(make_pair(pos, i));
                if (upr.second) { // 找到退出
                    break;
                }
                // 重复元素向后走
                ++pos_vec[i];
            }

            // 有任一一个字母走完 结束
            if (pos_vec[i] >= lookup[i].size()) {
                loop_flag = false;
                break;
            }
        }

        int start_pos = 0;
        int ans_len = INT_MAX;
        int min = INT_MAX;
        int max = INT_MIN;
        int min_index = 0;
        // 每次找到最小的那个(也就是最靠前的那个字母) 重新组成新的答案
        while (loop_flag) {
            min = INT_MAX;
            max = INT_MIN;
            min_index = 0;
            for (it_umap = start_umap.begin(); it_umap != start_umap.end(); ++it_umap) {
                // 找到最靠前的字母信息
                if (it_umap->first < min) {
                    it_umap_erase = it_umap;
                    min_index = it_umap->second;
                    min = it_umap->first;
                }
                // 找到最靠后的字母信息
                max = (it_umap->first > max) ? it_umap->first : max;
            }

            if (max - min + 1 < ans_len) { // 发现比预计字符串更短的 更新
                start_pos = min;
                ans_len = max - min + 1;
            }
            ++pos_vec[min_index];
            start_umap.erase(it_umap_erase);

            // 更新最靠前字母的下一个位置
            while (pos_vec[min_index] < lookup[min_index].size()) {
                pos = lookup[min_index][pos_vec[min_index]];
                upr = start_umap.insert(make_pair(pos, min_index));
                if (upr.second) {
                    break;
                }
                
                ++pos_vec[min_index];
            }

            if (pos_vec[min_index] >= lookup[min_index].size()) {
                break;
            }
        }

        if (INT_MAX == ans_len) {
            return "";
        }
        return s.substr(start_pos, ans_len);
    }
```