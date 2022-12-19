### 解题思路
priority_queue 不提供 遍历功能也不提供迭代器。以heap处理规则
如果要用到小顶堆，则一般要把模板的3个参数都带进去。STL里面定义了一个仿函数greater<>，基本类型可以用这个仿函数声明小顶堆。

关于priority_queue中元素的比较

　　模板申明带3个参数：priority_queue<Type, Container, Functional>，其中Type 为数据类型，Container为保存数据的容器，Functional 为元素比较方式。

　　Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector。


#include <iostream>
#include <queue> 
using namespace std;
int main(){
    priority_queue<int, vector<int>, greater<int> > q;
    for( int i= 0; i< 10; ++i ) q.push(10-i);
    while( !q.empty() ){
        cout << q.top() << endl;
        q.pop();
    }
    return 0;
}

### 代码

```cpp
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int len = nums.size();
        priority_queue <int,vector<int>,greater<int>>ipp;
        for(int i : nums) {
            ipp.push(i);
            if(ipp.size()>k){
                ipp.pop();
            }
            }
        return ipp.top();
    } 
};
```