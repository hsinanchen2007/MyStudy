有点复杂，但是能在O（1）时间复杂度内解决问题。。。hashmap保存。
1. nums保存所有入栈数据，索引为时间标签，键值为数据。。
2. mx保存所有入栈数据，索引为数据本身，键值为数据的时间标签。
3. push操作时，则在nums和mx中同时插入数据。
4. pop操作时，由于hashmap自动对键值排序的原理，直接取nums最后一个元素，即为时间标签最大的元素，同时从mx中删除该元素对应的最后一个时间标签。
5. popmax操作时，由于hashmap自动对键值排序的原理，直接取mx最后一个元素，即为值最大的元素，同时从nums中删除该元素的时间标签。

```
class MaxStack {
public:
    /** initialize your data structure here. */
    MaxStack() {
        this->timestamp = 0;
    }
    void push(int x) {
       /*we get the last index*/
       nums[this->timestamp] = x;
       mx[x].push_back(this->timestamp);
       this->timestamp++;
    }
    int pop() {
       auto it = nums.end();
       it--;
       int key = nums[it->first];
       nums.erase(it->first);
       mx[key].pop_back();
       if(mx[key].size() == 0){
           mx.erase(key);
       } 
       return key;
    }
    int top() {
       auto it = nums.end();
       it--;
       return nums[it->first];
    }
    int peekMax() {
       auto it = mx.end();
       it--;
       return it->first;
    }
    int popMax() {
       auto it = mx.end();
       it--;
       int key = it->first;
       int ppidx = it->second.back();
       nums.erase(ppidx);
       mx[key].pop_back();
       if(mx[key].size() == 0){
           mx.erase(key);
       }
       return key;
    }
private:
    map<int,int> nums;
    map<int,vector<int>> mx;
    int timestamp;
};
```