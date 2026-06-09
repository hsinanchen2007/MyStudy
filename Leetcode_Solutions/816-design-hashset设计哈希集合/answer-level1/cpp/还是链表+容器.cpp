果不其然，效率排名靠前的依然清一色的数组怪...


```
class MyHashSet {
    
private:
    
    struct node{
        
        int value;
        node* next;
        
        node(int val):value(val), next(NULL){}
    };
    
    vector<node*> my_set;
    
    int size = 1000;
    
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        
        my_set = vector<node*>(size, new node(-1));//初始化集合
    }
    
    void add(int key) {
        
        int index = key % size;
        node* temp = my_set[index];//指向表头
        
        node* last_node;//特定表尾
        
        while(temp!=NULL){
            
            if(temp->value==key)//如果发现已经存在这个值，则返回
                return;
            
            last_node = temp;
            temp = temp->next;
        }
        
        node* new_node = new node(key);//将新值加入表尾
        last_node->next = new_node;
    }
    
    void remove(int key) {
        
        int index = key % size;
        node* temp = my_set[index];//指向表头
        
        node* last_node;//锁定上一个节点
        
        while(temp!=NULL){
            
            if(temp->value==key){//如果发现值存在 目标节点的上一个节点指向目标节点的下一个节点
                
                last_node->next = temp->next;
                return;   
            }
            
            last_node = temp;
            temp = temp->next;
        }
        
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        
        int index = key % size;
        node* temp = my_set[index];//指向表头
        
        while(temp!=NULL){
            
            if(temp->value==key)
                return true;
            
            temp = temp->next;
        }
        
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
```
