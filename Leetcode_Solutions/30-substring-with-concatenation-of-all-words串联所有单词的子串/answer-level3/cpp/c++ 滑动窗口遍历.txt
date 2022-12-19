```
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> answer;
        if(s.size()==0 || words.size()==0){
            return answer;
        }
        unordered_map<string, int> words_cnt; //words_cnt
        unordered_map<string, int> temp_cnt; //窗口内string

        int all_len = 0;
        int one_len = words[0].size();
        for(int i=0; i<words.size(); i++){
            words_cnt[words[i]]++;
            all_len += words[i].size();
        }
        if(s.size() < all_len){
            return answer;
        }

        for(int left=0; left<one_len; left++){
            temp_cnt.clear();
            int i=left, j=left; //初始窗口
            while(j+one_len<=s.size()){
                string w = s.substr(j, one_len); //试探右边界
                if(words_cnt.count(w)==0){ //该单词失配,重新开始
                    i = j + one_len;
                    j = i;
                    temp_cnt.clear();
                    continue;
                }else{
                    temp_cnt[w]++;
                    if(temp_cnt[w] > words_cnt[w]){ //收缩左边界
                        while(temp_cnt[w] > words_cnt[w]){
                            temp_cnt[s.substr(i, one_len)]--;
                            i = i + one_len;
                        }
                    }
                    
                    if(j-i+one_len == all_len){ //说明找到答案了
                        answer.push_back(i);
                    }
                }
                j+=one_len;
            }
        }
        return answer;
    }
};
```
