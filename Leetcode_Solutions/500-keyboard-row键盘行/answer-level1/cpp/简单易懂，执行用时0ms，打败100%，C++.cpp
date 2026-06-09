1.先转换大小写；

2.判断单词首字母属于哪一行；

3.遍历判断接下的字母和首字母是否同属一行，若是，放入结果数组返回，若不是，直接跳过。


```
class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> keybord = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
        vector<string> res;
        int kLine = 0;    // 标记当前单词由第几行键盘打印, 值为-1时表示不能同一行打印
        for(int i=0; i<words.size(); i++){
            string temp = words[i]; // 便于转换大小写，同时不改变原单词

            for(int j=0; j<temp.length(); j++){
                // 单词字母转成小写
                if( temp[j]>='A' && temp[j] <= 'Z'){
                    temp[j] += 32; // 转为小写
                }
                // 先判断首字母属于键盘第几行
                if( j == 0 ){
                    if( keybord[0].find( temp[j] ) != -1 )
                        kLine = 0;
                    else if( keybord[1].find( temp[j] )  != -1 )
                        kLine = 1;
                    else if( keybord[2].find( temp[j] )  != -1 )
                        kLine = 2;
                }else{
                    // 若有一个字母和首字母不在同一行，则该单词非所求
                    if( keybord[ kLine ].find( temp[j] ) == -1 ){
                        kLine = -1;
                        break;
                    }
                }
            }
            if( kLine != -1){
                res.push_back(words[i]);
            }
        }
        return res;
    }
};
```