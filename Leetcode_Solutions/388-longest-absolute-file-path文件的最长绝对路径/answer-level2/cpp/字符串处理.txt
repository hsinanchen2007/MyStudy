```
class Solution {
public:
    string s;
    int level[100];//保存各层的长度
    int index,cnt,i,len,max_len,tmp;
    int lengthLongestPath(string input) {
        input.push_back('\n');
        len = input.length();
        while(i<len) {
            index = input.find('\n',i);//找到当前层的目录名或文件名
            s = input.substr(i,index-i);
            level[cnt] = s.length() + 1;
            if(judge(s)) {
                tmp = 0;
                for(int i=0;i<=cnt;i++) tmp += level[i];
                max_len = max(max_len,tmp-1);
            }
            cnt = 0;
            i = index + 1;
            while(i<len&&input[i]=='\t') cnt++,i++; //记录下一次目录或文件的层级
        }
        return max_len;
    }
    bool judge(string s) { //判断是否为文件
        static int index;
        index = s.find_last_of('.',s.length()-1);
        if(index==-1||index==s.length()-1) return false;
        else return true;
    }
};
```
