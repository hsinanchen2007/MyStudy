### 解题思路
每次提取一对字符和数字出来，当前的输出完了就提取下一对，如果到字符串结尾则返回空格和数量0，用以判断是否hasnext。

### 代码

```cpp
class StringIterator {
private:
    struct CharNum{
        char c;
        int reptime;
        CharNum(){
            c = ' ';
            reptime = 0;
        }
        CharNum(char _c,int _rep):c(_c),reptime(_rep){}
    };
    CharNum curnode;
    int nextIndex;
    string compstring;
public:
    StringIterator(string compressedString) {
        nextIndex = 0;
        compstring = compressedString;
        getnextnode();
    }
    void getnextnode(){
        if(nextIndex>=compstring.size()){
            curnode = CharNum(' ',0);
        } else {
            curnode.c = compstring[nextIndex++];
            int rep = 0;
            while(nextIndex < compstring.size() && compstring[nextIndex]<='9' && compstring[nextIndex]>='0'){
                rep = rep*10 + compstring[nextIndex] - '0';
                nextIndex++;
            }
            curnode.reptime = rep;
        }
        return;
    }
    char next() {
        char res = curnode.c;
        if(--curnode.reptime <= 0){
            getnextnode();
        }
        return res;
    }
    
    bool hasNext() {
        return curnode.reptime;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
```