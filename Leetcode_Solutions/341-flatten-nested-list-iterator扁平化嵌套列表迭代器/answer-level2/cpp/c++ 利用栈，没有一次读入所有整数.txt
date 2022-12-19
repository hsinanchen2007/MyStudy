没有在构造函数就把所有整数读出来，应该更符合迭代器要求。

利用两个栈，记录最新的一对[]的begin和end。


```cpp
class NestedIterator {
public:
    stack<vector<NestedInteger>::iterator> nests, layer_end;  
    //两个栈存放layer开始和结束的iterator
    NestedIterator(vector<NestedInteger> &nestedList) {
        nests.push(nestedList.begin());
        layer_end.push(nestedList.end());
    }

    int next() {
        //返回nests.top
        //将nests栈顶改为下一个迭代器
        int x = nests.top()->getInteger();
        
        while(++nests.top()==layer_end.top()){ //已到List尾
            nests.pop();
            layer_end.pop();
            if(nests.empty()) break;
        }
        
        return x;
    }

    bool hasNext() {
        //以下:将下一个integer的迭代器放入栈
        while(nests.size()){
            //[[]], [[],1,2]的情况
            if(nests.top()==layer_end.top()) {
                nests.pop(); layer_end.pop(); 
                if(nests.empty()) return false; //没有layer结束迭代
                nests.top()++; continue;
            }
            //case1：整数
            if(nests.top()->isInteger())
                return true;
            //case2: 列表
            vector<NestedInteger> &list = nests.top()->getList();
            //放入list首元素迭代器
            nests.push(list.begin());
            layer_end.push(list.end());//放入list.end
        }
        return false;
    }
    
};
```