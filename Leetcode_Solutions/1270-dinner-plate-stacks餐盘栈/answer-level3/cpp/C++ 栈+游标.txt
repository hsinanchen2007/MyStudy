执行用时 : 644 ms, 在所有 C++ 提交中击败了100.00%的用户
内存消耗 : 154.2 MB, 在所有 C++ 提交中击败了100.00%的用户
说实话看到这个结果我是懵逼的，没踩个坑WA就不错了，竟然混了个双100...
这并不是一个好解法，因为不断在最左侧popAtStack和push循环的操作会让它退化成O(n^2/c)的算法，碰巧没遇到卡这个点的测试用例而已。
下面就随便分析下了，推荐大家看树状数组的题解。

该类需要提供三个接口：从最右边非空的栈pop，从任意栈顶pop，以及向最左边未满的栈push。
容易知道，如果每次操作可以得到正确的“最右的非空栈”和“最左的未满栈”，那么对vector(stack也一样)来说push_back和pop的操作本身是O(1)的。

当进行pop时:
1. 若取出的是栈底元素，则不断递减rightnotempty_直到遇到第一个非空的栈。平均O(1)最坏O(n/c)
2. 若取出的是使栈达到上限的元素，则判断leftnotfull是否在这个栈的右侧。是则leftnotfull_ -1。 O(1)

当进行popAtStack操作时:
1. 只有当当前位置是rightnotempty_时才需要修改它。平均O(1)最坏O(n/c)
2. leftnotfull_的操作与pop相同。O(1)

当进行push操作时:
1. 若push操作使当前栈达到上限，不断递增leftnotfull_直到遇到第一个未满的栈。O(n/c)
2. rightnotempty_在当前栈左侧，则移到这个位置。O(1)

关于最坏O(n)的操作为何平均是O(1)，假设操作序列是随机的，则当操作数n趋于正无穷时，所有因pushAtStack而未达到容量上限的栈会根据其所在的位置而非pushAtStack操作的时间被push依次填补；
rightnotempty_左侧出现连续空栈的概率会是一个高阶无穷小(证明略，懒得研究怎么打公式了...)
而push操作中递增leftnotfull_的开销就无法忽视了。在这个题解基础上优化的话，可以使用一个最小堆维护未达上限的栈，或者通过类似复杂度的容器比如map。


```cpp []
class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        capacity_ = capacity;
        leftnotfull_ = -1;
        rightnotempty_ = -1;
    }
    
    void push(int val) {
        if(leftnotfull_ == -1){
            if(vector_.size() == 0)
                vector_.resize(1);
            vector_[0].push_back(val);
            rightnotempty_ = 0;
            leftnotfull_ = 0;
        }
        else{
            vector_[leftnotfull_].push_back(val);
            if(rightnotempty_ < leftnotfull_)
                rightnotempty_ = leftnotfull_;
        }
        while(vector_[leftnotfull_].size() == capacity_)
        {
            ++leftnotfull_;
            if(leftnotfull_ >= vector_.size())
                vector_.push_back(vector<int>());
        }
    }
    
    int pop() {
        if(rightnotempty_ == -1)
            return -1;
        int i = vector_[rightnotempty_].back();
        vector_[rightnotempty_].pop_back();
        while(rightnotempty_ >= 0 && vector_[rightnotempty_].size() == 0)
            --rightnotempty_;
        if(leftnotfull_ > rightnotempty_)
            leftnotfull_ = rightnotempty_;
        return i;
    }
    
    int popAtStack(int index) {
        if(vector_.size() <= index || vector_[index].size() == 0)
            return -1;
        int i = vector_[index].back();
        vector_[index].pop_back();
        while(rightnotempty_ >= 0 && vector_[rightnotempty_].size() == 0)
            --rightnotempty_;
        if(leftnotfull_ > index)
            leftnotfull_ = index;
        return i;
    }
private:
    vector<vector<int>> vector_;
    int capacity_;
    int leftnotfull_;
    int rightnotempty_;
        
};
```
