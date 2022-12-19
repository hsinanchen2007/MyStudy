递归调用其实是利用了系统的调用栈做数据的保存，所以一般都可以通过使用栈来替换递归调用。不太理解有些同学用了栈了，为什么还要用递归调用。
```
class NestedIterator {
private:
    vector<int> v;
    int size;
    int pos;
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        stack<NestedInteger> s;
        int n = nestedList.size();
        while(n--){
            s.push(nestedList[n]);
        }
        while(!s.empty()){
            NestedInteger t = s.top();
            if(t.isInteger()){
                v.push_back(t.getInteger());
                s.pop();
            }
            else{
                vector<NestedInteger> vn = t.getList();
                int m = vn.size();
                s.pop();
                while(m--){
                    s.push(vn[m]);
                }
            }
        }

        pos = 0;
        size = v.size();
    }

    int next() {
        return v[pos++];
    }

    bool hasNext() {
        return pos < size;
    }
};
```
这个实现相比起来有些头重脚轻--构造的时候花了几乎所有时间，而使用hasNext，next时极快。有些同学把栈作为成员变量保存，构造时仅仅扒一层皮就逆向堆入栈中，在用户调用hasNext时才做深入扒皮搜索。相比起来，后边这种实现就均衡一些。如果用户搞了一个很长的列表，然后就取前边几个元素就不用了，那后边这种实现要高效的多。如果是在计算能力超强的服务器上做构造，而后把对象传给能力较弱的移动设备来使用，则前边给出的代码实现有较明显的优势。