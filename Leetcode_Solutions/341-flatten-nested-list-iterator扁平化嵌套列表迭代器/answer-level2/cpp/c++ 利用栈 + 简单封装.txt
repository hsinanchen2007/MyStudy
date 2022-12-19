```c++
class NestedIterator {
private:
    class status {
    private:
        const vector<NestedInteger>& nestedList;
        int curIndex;
    public:
        status(const vector<NestedInteger>& nsList) : nestedList(nsList), curIndex(0) {}
        const NestedInteger & getNI() {
            return nestedList[curIndex];
        }
        void move() {
            ++curIndex;
        }
        bool hasNext() {
            return curIndex < nestedList.size();
        }
    };

    const vector<NestedInteger> nestedList;
    stack<status> s;
    int nextInt;
    
public:
    
    NestedIterator(vector<NestedInteger> &nestedList_) : nestedList(nestedList_) {
        s.push(status(nestedList));
    }

    int next() {
        s.top().move();
        return this->nextInt;
    }

    bool hasNext() {
        while (!s.empty()) {
            if (!s.top().hasNext()) {
                s.pop();
                continue;
            }
            const NestedInteger& ni = s.top().getNI();
            if (ni.isInteger()) {
                this->nextInt = ni.getInteger();
                return true;
            } else {
                s.top().move();
                const vector<NestedInteger>& listNi = ni.getList();
                if (!listNi.empty()) s.push(status(listNi));
            }
        }
        return false;
    }
};
```

nextInt 指向的就是下一个数字。
大致思路是判断下一个元素是int还是list，
如果是int,hasNext() 就返回true。
如果是list,就判断list是否为空，list为空，那就++curIndex,指向当前栈顶的vector里的下一个元素，如果当前栈顶的vector没有下一个元素了，就pop(),取上一个vector。
重复以上步骤。

执行用时 : 24 ms , 在所有 C++ 提交中击败了 91.63% 的用户
