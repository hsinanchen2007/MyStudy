```
class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        flag=0;
        it1=v1.begin();
        end1=v1.end();
        it2=v2.begin();
        end2=v2.end();
    }

    int next() {
        int num;
        if(flag%2) {
            if(it2!=end2) {
                num=*it2;
                it2++;
            }else {
                num=*it1;
                it1++;
            }
        }else {
            if(it1!=end1) {
                num=*it1;
                it1++;
            }else {
                num=*it2;
                it2++;
            }
        }
        flag=(flag+1)%2;
        return num;
    }

    bool hasNext() {
        return it1!=end1||it2!=end2;
    }
private:
    int flag;
    vector<int>::iterator it1;
    vector<int>::iterator end1;
    vector<int>::iterator it2;
    vector<int>::iterator end2;
};
```
