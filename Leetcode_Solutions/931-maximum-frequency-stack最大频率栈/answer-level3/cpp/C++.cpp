看了官方注解之后，添加了一些注释，用C++写了一版
```
class FreqStack {
public:
    unordered_map<int,int>freq;//key->freq;
    int maxFreq;
    unordered_map<int,stack<int>>group;//freq->key
    FreqStack() {
        maxFreq=0;
    }
    
    void push(int x) {
        freq[x]++;
        maxFreq=max(maxFreq,freq[x]);
        //假如原本x的freq为1，增加之后变成2，这里只是在频率为2的stack里新增了一个x，但是并没有删除频率为1的stack中的x。
        //这样可以保证，当x被pop之后，在频率为1的stack里元素的顺序不会被修改。
        group[freq[x]].push(x);
    }
    
    int pop() {
        int x=group[maxFreq].top();
        group[maxFreq].pop();
        freq[x]--;
        if(group[maxFreq].size()==0) maxFreq--;
        return x;
    }
};
```
