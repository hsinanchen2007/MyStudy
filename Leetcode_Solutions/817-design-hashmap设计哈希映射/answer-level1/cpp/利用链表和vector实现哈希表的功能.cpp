提交后看了下排名靠前的，几乎清一色的单纯数组...感觉这道题用数组做就没意思了啊...

另外本题思路来源于题解中其他老哥的解答，非常感谢！


```
class MyHashMap {
    
private:
    
    struct node{
        
        int my_key;
        int my_val;
        node* next;
        
        node(int key, int val):my_key(key),my_val(val),next(NULL){}  
    };
    
    vector<node*> my_map;//用链表为节点的容器构造哈希表
    
    int size = 1000;
    
public:
    /** Initialize your data structure here. */
    MyHashMap() {
        
        my_map = vector<node*> (size, new node(-1,-1));//初始化表
    }
    
    /** value will always be non-negative. */
    void put(int key, int value) {
        
        int index = key % size;//通过哈希函数特定新数值对在容器中的相对位置
        
        node* temp = my_map[index];//指向这个相对位置的表头
        
        node* last_node;//特定当前表的表尾
        
        while(temp!=NULL){
            
            if(temp->my_key == key){//如果发现已经存在对应的键，则更新它的值
                
                temp->my_val = value;
                return;
            }
            
            last_node = temp;
            temp = temp->next;
        }
        
        //将新数值对插入到表尾
        node* new_node = new node(key,value);
        last_node->next = new_node;
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        
        int index = key % size;
        
        node* temp = my_map[index];
        
        while(temp!=NULL){
            
            if(temp->my_key==key){
                
                return temp->my_val;
            }
            
            temp = temp->next;
        }
        
        return -1;

        
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        
        int index = key % size;
        
        node* temp = my_map[index];

        
        while(temp!=NULL){
            
            if(temp->my_key==key){
                
                temp->my_val = -1;
                return;
            }
            temp = temp->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
```
