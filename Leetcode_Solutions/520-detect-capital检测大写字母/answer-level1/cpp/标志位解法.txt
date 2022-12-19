```
class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size()==1){
            return true;
        }
        bool allCapital = false;
        bool allLower = false;
        bool firstCapital = false;
        if(word[0]-'a'<0){
            //第一个字母如果是大写，则有可能是仅第一个字母大写或全部大写
            allCapital = true;
            firstCapital = true;
        }else{
            //第一个字母如果是小写，只能是全部小写
            allLower = true;
        }
        for(int i = 1;i<word.size();i++){
            int temp = word[i]-'a';
            if(temp<0){
                //第二个字母起出现大写字母，第一个大写和所有小写标志为置为false;
                firstCapital = false;
                allLower = false;
            }
            else{
                //第二个字母起出现小写字母，所有大写标志置为false;
                allCapital = false;
            }
        }
        return (allCapital||allLower||firstCapital);
    }
};
```
设置了三个标志位，用于判断是那种情况，如果三种情况都不符合最后会输出false
