### 解题思路
题目意思比较复杂：（先看了眼别的老哥的题解才明白讲的个啥东西）
- 对于一个确定的有效括号（注意，这里说了给定的序列一定是有序的）
- 将该序列分割成两个子序列，这两个子序列应该互为整个序列的补集（就是说这两个序列不相交，没有公共元素，且序列元素合在一块就是全部元素）
**分割所得到的这两个序列也一定要是有效括号序列**
- 所得到的序列的嵌套深度depthA， depthB的最大值max(depthA, depthB)最小
### 解题关键
- 确定每个有效序列的嵌套深度
- 如何分割为序列A和序列B

- 对于嵌套深度我们可以用栈实现求解
- 分割序列有两种办法
    - 两次循环
        - 第一次循环得到所有位置的嵌套深度()成对保存
        - 第二次循环根据最大深度对所得到位置的嵌套深度进行划分（取最大深度的一半作为分割点）
    - 双指针
        - 通过分析两次循环我们可以知道我们并不需要直到所有位置的最大深度只需要知道当前形成有效括号的序列对的深度即可
        - 每两个中有一个归属于A，有一个归属于B。 
### 两次循环

12ms
```cpp
vector<int> maxDepthAfterSplitBasic(string seq) {
        // 将有效括号进行拆分
        // 中间对半分
        // 两遍循环
        vector<int> res(seq.size(), 1);
        stack<int> st;
        st.push(1);
        int i = 1;
        int depth = 1;
        while(i<seq.size()){
            if(seq[i] == '(') {
                if(st.empty()) st.push(1);
                else{
                    st.push(st.top()+1);
                    res[i] = st.top();
                }
            }
            else{
                depth = max(depth, st.top());
                res[i] = st.top();
                st.pop();
            }
            ++i;
        } // 取出最大深度
        int tag = (depth+1)>>1;
        for(int i=0; i<seq.size(); ++i){
            if(res[i] > tag) res[i] = 0;
            else res[i] = 1;
        } // 大于最大深度一半的置为0，其余置为1
        return res;
    }
```
### 双指针
```cpp
vector<int> maxDepthAfterSplitPro(string seq) {
        // 快慢指针
        vector<int> res(seq.size(), 1);
        stack<indexdepth> st;
        indexdepth temp;
        st.push({-1,0});
        st.push({0,1});
        int i = 1;
        while(i<seq.size()){
            if(seq[i] == '(') st.push({i,st.top().d+1});
            else{
                if(st.top().d%2==0){
                    res[i] = 0;
                    res[st.top().x] = 0;
                }
                else{
                    res[i] = 1;
                    res[st.top().x] = 1;
                }
                st.pop();
            }
            ++i;
        } // 取出最大深度
        return res;
    }
```

### 代码

4ms

```cpp
class Solution {
private:
    struct indexdepth{
        int x;
        int d;
    };
public:
    vector<int> maxDepthAfterSplit(string seq) {
        return maxDepthAfterSplitPro(seq);
    }
    /*vector<int> maxDepthAfterSplitBasic(string seq) {
        // 将有效括号进行拆分
        // 中间对半分
        // 两遍循环
        vector<int> res(seq.size(), 1);
        stack<int> st;
        st.push(1);
        int i = 1;
        int depth = 1;
        while(i<seq.size()){
            if(seq[i] == '(') {
                if(st.empty()) st.push(1);
                else{
                    st.push(st.top()+1);
                    res[i] = st.top();
                }
            }
            else{
                depth = max(depth, st.top());
                res[i] = st.top();
                st.pop();
            }
            ++i;
        } // 取出最大深度
        int tag = (depth+1)>>1;
        for(int i=0; i<seq.size(); ++i){
            if(res[i] > tag) res[i] = 0;
            else res[i] = 1;
        } // 大于最大深度一半的置为0，其余置为1
        return res;
    }*/
    vector<int> maxDepthAfterSplitPro(string seq) {
        // 快慢指针
        vector<int> res(seq.size(), 1);
        stack<indexdepth> st;
        indexdepth temp;
        st.push({-1,0});
        st.push({0,1});
        int i = 1;
        while(i<seq.size()){
            if(seq[i] == '(') st.push({i,st.top().d+1});
            else{
                if(st.top().d%2==0){
                    res[i] = 0;
                    res[st.top().x] = 0;
                }
                else{
                    res[i] = 1;
                    res[st.top().x] = 1;
                }
                st.pop();
            }
            ++i;
        } // 取出最大深度
        return res;
    }
};
```