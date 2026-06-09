class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int head_idx = 0;
        int tail_idx = 0;
        int max_size = 1;
        unordered_map<char, int> word_record;
        for(int i = 0; i < s.size(); ++i) {
            head_idx = i;
            char now_word = s[i];
            auto itor = word_record.find(now_word);
            auto mapEnd = word_record.end();
            if(head_idx - tail_idx+1 > max_size && (itor == mapEnd || word_record[now_word] < tail_idx)) {
                max_size = head_idx - tail_idx+1;
            }
            if(itor != mapEnd && word_record[now_word] >= tail_idx) {
                tail_idx = word_record[now_word] + 1;
            }
            word_record[now_word] = i ;
        }
        return max_size;
    }
};