一个一个例子debug很久，才摸清楚判断字符串是否的有效的依据，和上面一个朋友一样，以e为中间轴切分为底数和指数
```
    bool isNumber(string s) {
        while(s[0] == ' ') s = s.substr(1);
        while(s[s.size()-1] == ' ') s = s.substr(0, s.size()-1); //去掉首位的所有空格
        if(s[0] == '+' || s[0] == '-') s = s.substr(1); //去掉第一个+/-
        if(s.empty()) return false;

        int count_E{0}, pos_E{-1};
        for(int i = 0; i<s.size(); i++){
            if(s[i] == 'e') {
                count_E++;
                pos_E = i;
            }
        }//找e的位置，害怕有多个e出现，就没用库函数，事实上样例中似乎都最大只含一个e

        if(count_E > 1) return false; //多个e直接爆炸

        if(pos_E != -1){
            string base = s.substr(0, pos_E), pow = s.substr(pos_E+1); 
            //有e时，拆分字符串；true/false表示是不是指数部分
            return isValidNum(base, false) && isValidNum(pow, true);
        }

        return isValidNum(s, false);
    }

    bool isValidNum(string &s, bool isTail){
        if(s.empty()) return false;
        if(isTail && (s[0] == '+' || s[0] == '-')) s = s.substr(1); 
        //如果是e的指数部分，可以有一个合法的+/-

        int countNum = 0, countDot = 0;
        while( !s.empty() && ((s[0] >= '0' && s[0] <= '9' )|| s[0] == '.')){
            if(s[0] == '.') countDot++;
            else countNum++;
            s = s.substr(1);
        } 
        
        //空意味着没有奇怪字符，数字至少有1个
        //指数部分不可以有小数，即没有点
        if(isTail) return s.empty() && (countNum > 0) && (countDot == 0);
        //e的基数或者正常数字中，点的位置可以在首或尾，.1、1.也是合法的；多个点爆炸
        return s.empty() && (countNum > 0) && (countDot <= 1);
    }
```
