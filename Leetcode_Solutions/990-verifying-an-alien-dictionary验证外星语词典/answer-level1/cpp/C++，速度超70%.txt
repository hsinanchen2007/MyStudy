### 解题思路
C++，根据给出的字典，从前往后依次比较相邻两个单词是否按字典排序。
1.先检查两个相邻单词是否为其中一个单词前缀，若前面单词是后面单词的前缀，直接比较接下来的两个单词；若后面单词是前面单词的前缀，直接返回false；
2.两个单词并不是前缀的关系，依次检查两个单词对应位置的字母是否按字典排序；
3.有一个位置对应的字母不按字典排序，直接返回false；
4.当对应位置的字母按指定排序时，再比较下一个字母；
5.按上面的方法依次比较所有的单词

### 代码

```cpp
class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        bool res = true;
        int i, j;
        for( i = 0; i < words.size() - 1; i++)
        {
            string s1(words[i]);
            string s2(words[i+1]);
            //比较两个单词是否为前缀关系
            if(s1.size() <= s2.size()){
                //判断s1是否为s2的前缀
                if(s2.find(s1, 0)!= string::npos){
                    //s1为s2的前缀，直接比较接下个的两个单词
                    continue;
                }
            } else {
                //s1.size() > s2.size()
                 //判断s2是否为s1的前缀
                if(s1.find(s2, 0)!= string::npos){
                    //s2为s1的前缀，直接返回false;
                    return false;
                }
            }
            //比较两个单词是否按字典排序
            
            for(j = 0; j < s1.size()&& j < s2.size(); j++)
            {
                //比较两个单词对应位置的单词的排序是否合理
                int pos1 = order.find(s1[j]);
                int pos2 = order.find(s2[j]);
                //后一个字符串对应位置的字符排在前面时，则说明单词序列不按字典排序
                if(pos1 > pos2){
                    res = false;
                    break;
                } else if(pos1 < pos2){
                    //两个单词排序正确
                   // 跳出循环
                    break;
                }
                // pos1 = pos2，继续比较下一个单词
            }
            // //但两个单词的前 j 个字符相等时，若前面的单词长度大于后面的单词长度
            // //返回false
            // if(s1.size() > s2.size() && j == s2.size()){
            //     res = false;
            //     break;
            // }
            //检查出单词不按字典排序
            if(!res)
                break;
        }
        //返回检查的结果
        return res;
    }
};
```