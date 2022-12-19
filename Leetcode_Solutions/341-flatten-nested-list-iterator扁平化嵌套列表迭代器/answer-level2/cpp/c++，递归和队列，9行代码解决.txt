c++解法  
执行用时：12 ms
内存消耗：16.6 MB 
已经战胜86.73 % 的 cpp 提交记录
使用队列和递归方法 8行代码解决
```
class NestedIterator {
public:
    queue<int> nums;
    NestedIterator(vector<NestedInteger> &nestedList) {
        pushChild(nums,nestedList);
  
    }
    void pushChild(queue<int> &nums,vector<NestedInteger> &nestedList)
    {
        for(int i=0;i<nestedList.size();i++)
        {
            if(nestedList[i].isInteger()) nums.push(nestedList[i].getInteger());
            else pushChild(nums,nestedList[i].getList());
        }
    }

    int next() {
        int front=nums.front();
        nums.pop();
        return front;
    }

    bool hasNext() {
        return !nums.empty();
    }
};
```
