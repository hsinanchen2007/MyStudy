执行用时 :16 ms, 在所有 C++ 提交中击败了97.54%的用户
内存消耗 :10.4 MB, 在所有 C++ 提交中击败了89.06%的用户

这里曾尝试了用真的map<char, int>来做，结果效率比用数组差好多......

```
class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        
        //将牌照中的所有字母和其出现次数塞进哈希表里
        int true_licensePlate[26]={0};
        
        for(int i=0; i<licensePlate.length(); i++){
            
            if(licensePlate[i] >= 'a' && licensePlate[i] <= 'z' )
                true_licensePlate[licensePlate[i] - 'a']++;
            
            else if(licensePlate[i] >= 'A' && licensePlate[i] <= 'Z')
                true_licensePlate[licensePlate[i] - 'A']++;
        }
        
        
        
        int index = 0;
        int size = 16;
        
        for(int i=0; i<words.size(); i++){
            
            //创建一个牌照哈希表的副本
            int temp[26];
            memcpy(temp,true_licensePlate,sizeof(true_licensePlate));
            
            //遍历每个单词，每遇到在哈希表中存在的字母，就减去他的所在的值
            for(int j=0; j<words[i].size(); j++){
                
                if(temp[words[i][j] - 'a'] > 0)
                    temp[words[i][j] - 'a']--;
            }
            
            bool judge = true;
            
            //如果单词是完整单词，则哈希表里所有的元素都不应该有剩
            for(auto &it : temp){
                
                if(it!=0)
                    judge=false;
            }
            
            //这里用来记录和更新满足条件的最小长度的单词
            if(judge==true && words[i].size()<size){
                
                index = i;
                size = words[i].size();
            }
            
        }
        

        
        return words[index];
    }
};
```
