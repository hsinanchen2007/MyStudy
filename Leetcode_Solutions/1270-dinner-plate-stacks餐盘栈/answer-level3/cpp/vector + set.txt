1. 用```buffer```保存需要扩展的栈，```free```列表保存当前存在空余空间的栈的索引；
2. ```push```操作：如果```free```列表为空，则表示当前没有空余的栈空间进行```dinner```操作，这是我们需要在在末尾扩展出一个新的栈，然后将输入压入新的栈中；如果当前的```free```列表不为空，则直接取```free```列表中的第一个栈的索引，然后将数据压入占中该栈中，如果该栈压入新的数据后已满，则将其从```free```列表中移除；
3. ```pop```操作：直接从```free```的末尾进行出栈操作即可，如果该栈由满栈变为有剩余空间的栈，则将其加入```free```列表中，如果该栈为空，则将其移除，并将其从```free```列表中移除；
4. ```popIndex```操作：直接从```buffer```的```index```处进行出栈操作即可，如果该栈由满栈变为有剩余空间的栈，则将其加入```free```列表中，如果该栈为空且该所以为```buffer```的末尾，则将其移除，并将其从```free```列表中移除；

```
class DinnerPlates {
public:
    DinnerPlates(int capacity) {
        this->capacity = capacity;
    }
    
    void push(int val) {
        if(free.empty()){
            stack<int> s;
            s.push(val);
            buffer.push_back(s);
            
            if(s.size() < this->capacity){
                free.insert(buffer.size()-1);
            }
        }else{
            auto it = free.begin();
            buffer[*it].push(val);
            if(buffer[*it].size() >= this->capacity){
                free.erase(*it);
            }
        }
    }
    
    int pop() {
        if(buffer.size() == 0){
            return -1;
        }
        
        while(buffer.back().empty()){
            free.erase(buffer.size()-1);
            buffer.pop_back();
        }
        
        int res = buffer.back().top();
        buffer.back().pop();
        free.insert(buffer.size()-1);
        if(buffer.back().empty()){
            free.erase(buffer.size()-1);
            buffer.pop_back();
        }
        
        return res;
    }
    
    int popAtStack(int index) {
        if(index >= buffer.size()||
            buffer[index].empty()){
            return -1;
        }
        
        int res = buffer[index].top();
        buffer[index].pop();
        free.insert(index);
        
        if(buffer.back().empty()){
            free.erase(buffer.size()-1);
            buffer.pop_back();
        }
        
        return res;
    }
private:
    vector<stack<int>> buffer;
    set<int> free;
    int capacity;
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */

```