代码逻辑是很清晰的
第一步，遍历字符串，获取char的频次
第二步，初始化堆，使堆成为最大堆
第三步，每次把头部和尾部调换，然后重新更新堆
```
class Solution {
private:
    unordered_map<char, int> g_char_freq_map;
public:
    void update_heap(vector<char>& char_vector, int pos, int last_pos) {
        //最大堆，顶部节点的值应该是最大的
        int dad = pos;
        int son = 2 * pos + 1;
        while (son <= last_pos) {
            if (son + 1 <= last_pos 
               and g_char_freq_map[char_vector[son + 1]] > g_char_freq_map[char_vector[son]] ) {
                //找子节点中最大的
                ++son;
            }
            if (g_char_freq_map[char_vector[son]] > g_char_freq_map[char_vector[dad]]) {
                //替换值
                char temp = char_vector[son];
                char_vector[son] = char_vector[dad];
                char_vector[dad] = temp;
            }
            else {
                break;
            }
            dad = son;
            son = 2 * dad + 1;
        }
        
    }
    string frequencySort(string s) {
        //获取所有字符的频次
        vector<char> result_vector;
        for (int i = 0; i < s.size(); ++i) {
            if (g_char_freq_map.count(s[i]) == 0) {
                g_char_freq_map.insert(pair<char, int>(s[i], 1));
                result_vector.push_back(s[i]);
            }
            else {
                ++g_char_freq_map[s[i]];
            }
        }
        //initial heap 1, 2, 3, 4, 5
        int last_dad = result_vector.size() / 2 - 1;
        for (int i = last_dad; i >= 0; --i) {
            update_heap(result_vector, i, result_vector.size()  - 1);
        }
        //开始排序
        string result_string = "";
        for (int i = result_vector.size() - 1; i >= 0; --i) {
            for(int j = 0; j < g_char_freq_map[result_vector[0]]; ++j) {
                result_string.push_back(result_vector[0]);
            }
            char temp_char = result_vector[i];
            result_vector[i] = result_vector[0];
            result_vector[0] = temp_char;
            update_heap(result_vector, 0, i - 1);           
        }
        return result_string;
    }
};
```
