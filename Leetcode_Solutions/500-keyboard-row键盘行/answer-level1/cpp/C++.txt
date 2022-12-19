class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> keyboard = {"QWERTYUIOPqwertyuiop", "ASDFGHJKLasdfghjkl", "ZXCVBNMzxcvbnm"};
        vector<string> result;
        int j, z;
        for(int i = 0; i < words.size(); i++){
            z = 0;
            //对于每个字符串，首字母肯定属于某一个keyboard的字符串，先找到那个字符串
            while(keyboard[z].find(words[i][0]) == string::npos){
                    z++;
            }
            j = 1;
            while(j < words[i].size() and keyboard[z].find(words[i][j]) != string::npos){
                j++;
            }
            //如果全都到末尾了
            if(j == words[i].size()){
                result.push_back(words[i]);
            }
        }
        return result;
    }
};