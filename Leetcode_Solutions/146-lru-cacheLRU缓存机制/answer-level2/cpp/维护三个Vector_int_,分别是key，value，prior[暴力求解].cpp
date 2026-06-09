直接维护三个vector，通过index来对队列进行控制，当有对应的数据被使用，或者更新时，将所有的priorVec队列的值更新+1，并将当前值设置为0；
在进行替换时，只需要查找出priorVec中值最大的那个Index即可；
写的啰嗦了一点，可以将其中更新priorVec部分抽象为方法。
```
class LRUCache {
public:
    vector<int> vec;  //key
    vector<int> priorVec; //优先级
    vector<int> result;  //结果 value
    int index = 0;
    LRUCache(int capacity) {
        for (int i=0;i<capacity;i++) {
            vec.push_back(INT_MIN);
            priorVec.push_back(0);
            result.push_back(0);
        }
    }
    
    int get(int key) {
        for(int i=0;i<vec.size();i++){
            if(vec[i] == key) {
                for(int j=0;j<priorVec.size();j++) {
                    priorVec[j] = priorVec[j]+1;
                }
                priorVec[i] = 0;
                return result[i];
            }
        }
        return -1;
    }
    
    void put(int key, int value) {
        //如果秘钥存在会如何  todo::
        for(int i=0;i<vec.size();i++){
            if(vec[i] == key) {
                result[i] = value;
                for( int j=0;j<priorVec.size();j++){
                    priorVec[j] += 1;
                }
                priorVec[i] = 0;
                return;
            }
        }

        if(index < vec.size()){  //还没有装满
            result[index] = value;
            vec[index] = key;
            for(int i=0;i<priorVec.size();i++) {
                priorVec[i] = priorVec[i] + 1;
            }
            priorVec[index] = 0;
            index++;
        }else{  //装满了，找到priorVec最大的哪个
            int tmp = INT_MIN;
            int maxIndex = 0;
            for(int i =0;i<priorVec.size();i++){
                if (tmp<priorVec[i]) {
                    tmp = priorVec[i];
                    maxIndex = i;
                }
            }
            result[maxIndex] = value;
            vec[maxIndex] = key;
            for(int j =0;j<priorVec.size();j++){
                priorVec[j]  += 1;
            }
            priorVec[maxIndex] = 0;
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
```
