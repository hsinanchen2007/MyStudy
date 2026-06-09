```
struct CharNum{
    char c;
    int num;
    CharNum(char c, int num):c(c),num(num){};
    CharNum():c(' '),num(0){};
};
class StringIterator {
public:
    CharNum cn;
    vector<CharNum> vcn;
    StringIterator(string compressedString) {
        int len = 0;
        char c = ' ';
        int i = 0;
        while(i<compressedString.size())
        {
            c = compressedString[i++];
            len = 0;
            while(isdigit(compressedString[i]))
            {
                len = len*10 + compressedString[i++]-'0';
            }
            printf("c %c, len %d\n", c, len);
            vcn.push_back(CharNum(c, len));
        }
    }
    
    char next() {
        if(cn.num == 0 && vcn.size()>0)
        {
            cn = vcn.front();
            vcn.erase(vcn.begin());
        }
        if(cn.num>0)
        {
            cn.num--;
            return cn.c;
        }
        else
        {
            return ' ';
        }
    }
    
    bool hasNext() {
        return cn.num>0 || vcn.size()>0;
    }
};

```
