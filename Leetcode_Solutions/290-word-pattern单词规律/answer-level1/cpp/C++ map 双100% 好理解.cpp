![360截图20200401201146543.jpg](https://pic.leetcode-cn.com/4847ae0260f3ab2b88f6a194f043aa834574d2e2aaa3a6d93946e30607b77df2-360%E6%88%AA%E5%9B%BE20200401201146543.jpg)




  bool wordPattern(string pattern, string str) {
        map<char,string> mymap;
        int i = 0,j=0,k=0;
        for(;i<pattern.size();i++) { //i<4
            string temp ;
            while(str[k] != ' ' && k<str.size()) k++;
            k--;
            for(int ss= j;ss<=k;ss++) temp +=str[ss];
            if(mymap.find(pattern[i]) !=mymap.end()) { //键 找到了
                if(mymap[pattern[i]] != temp) return false;
                
            }
            else {
                mymap.insert(pair<char, string>(pattern[i], temp));
            }
            k+=2;j = k;
            if (j > str.size() &&  i < pattern.size()-1) return false;

        }
        set<string> my;


    map<char, string>::iterator iter;
    for (iter = mymap.begin(); iter != mymap.end(); iter++) {
        if(my.find(iter->second) != my.end()) // 查找某个元素是否存在
            return false; //若存在则返回true
        my.insert(iter->second);
    }
 
        if(i<pattern.size() || j < k || k<str.size()) return false;
        else return true;

    }
