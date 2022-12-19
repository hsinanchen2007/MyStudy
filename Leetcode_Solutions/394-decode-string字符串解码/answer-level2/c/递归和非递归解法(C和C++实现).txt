```
char* decode(char* s, int* pos) {
    int len = strlen(s);
    int cnt = 0;
    int curPos = *pos;
    char *result = (char*)malloc(sizeof(char));
    memset(result, 0, sizeof(char));
    while(*pos<len && s[*pos]!=']')
    {
        if(s[*pos]<'0' || s[*pos]>'9')
        {    
            if(strlen(result) > 1)
                result = (char*)realloc(result, sizeof(char)+strlen(result));
            else
                result = (char*)realloc(result, sizeof(char));
            strncat(result, &s[*pos], 1);            
            *pos = *pos + 1;
        }
        else
        {
            int cnt = 0;   
            while(*pos<len && s[*pos]>='0' && s[*pos]<='9')
            {
                cnt = cnt*10 + s[*pos] - '0';
                *pos = *pos + 1;
            }
            *pos = *pos + 1;
            char* temp = decode(s, pos);
            *pos = *pos + 1;
            if(strlen(result) < strlen(temp))
                result = (char*)realloc(result, cnt*strlen(temp)*sizeof(char)+1);
            else
                result = (char*)realloc(result, cnt*len*sizeof(char)+strlen(result)+1);
            for(int i=0; i<cnt; ++i)
            {
                strncat(result, temp, strlen(temp));
            }
            cnt = 0;
        }          
    }
    return result;
}

char* decodeString(char* s) {
    int pos = 0;
    char *result = decode(s, &pos);
    result[strlen(result)] = '\0';
    return result;
}
```
```
class Solution {
public:
    string decodeString(string s) {
        /*method1-递归方法*/
        int pos = 0;
        return decode(s, pos);
    }
    
    string decode(string s, int& pos)
    {
        string result = "";
        int len = s.size();
        while(pos<len && s[pos]!=']')
        {
            if(s[pos] < '0' || s[pos] > '9')
                result += s[pos++];
            else
            {
                int cnt = 0;
                while(pos<len && s[pos]>='0' && s[pos]<='9')
                {
                    cnt = cnt * 10 + s[pos++] - '0';
                }
                pos++;
                string cur = decode(s, pos);
                pos++;
                while(cnt--)
                {
                    result += cur;
                }
            }
        }
        return result;
    }

    /*method2-非递归方法 使用两个栈 一个保存数字一个保存字母*/
    string decodeString(string s) {
        int len = s.size();
        int num = 0;
        stack<int> numstack;
        stack<string> strstack;
        string cur = "";
        string result = "";
        for(int i=0; i<len; ++i)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                num = 10*num + s[i] - '0';
            }
            else if(s[i] == '[')
            {
                numstack.push(num);
                strstack.push(cur);
                num = 0;
                cur.clear();
            }
            else if((s[i]>='a' && s[i]<='z') || (s[i]>='A' && s[i]<='Z'))
                cur += s[i];
            else if(s[i] == ']')
            {
                int k = numstack.top();
                numstack.pop();
                for(int j=0; j<k; ++j)
                    strstack.top() += cur;
                cur = strstack.top();
                strstack.pop();
            }
        }
        result = result + cur;
        return result;     
    }
};
```

