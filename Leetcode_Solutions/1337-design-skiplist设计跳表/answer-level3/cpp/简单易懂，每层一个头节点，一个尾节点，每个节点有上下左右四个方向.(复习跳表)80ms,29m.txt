```c++
class Skiplist {
    class Node{
        public:
            Node* up;
            Node* down;
            Node* left;
            Node* right;
            int val;
            Node(int num){up = down = left= right = nullptr;val = num;}
        bool operator=(Node* node)const{
            return node -> val == val;
        }
    };
public:
    Node* head;
    Node* tail;
    int maxh,h;//maxh压层高，放置层过高，h记录已经建好的层数
    Skiplist() {
        head = new Node(-1);
        tail = new Node(-2);
        head -> right = tail;
        tail -> left = head;
        maxh = 14;
        h = 0;
    }
    
    bool search(int target) {
        auto cur = head;
        do{
            while(cur -> right -> val != -2 && cur -> right ->  val <= target) cur = cur -> right;
            if(cur -> val == target) return 1;
            cur = cur -> down;
        }while(cur);
        return 0;
    }
    
    void add(int num) {
        auto cur = head;
        Node* pre = nullptr;
        do{
            while(cur -> right -> val != -2 && cur -> right -> val <= num) cur = cur -> right;
            pre = cur;
            cur = cur -> down;
        }while(cur);
        pre = pre -> right;
        if(pre -> val == num) return;
        auto newNode = new Node(num);
        newNode -> right = pre;
        newNode -> left = pre -> left;
        pre -> left -> right = newNode;
        pre -> left = newNode;
        while(rand() % 10 >= 5 ){//模拟50%的投硬币
            cur = newNode;
            while(cur -> left -> val != -1 && !(cur -> left -> up)) cur = cur -> left;
            cur = cur -> left -> up;
            if(!cur){//新建一高层，此时头尾节点也该提高
                if(h > maxh) break;
                cur = new Node(-1);
                cur -> right = new Node(num);
                cur -> right -> left = cur;
                cur -> right -> down = newNode;
                newNode -> up = cur -> right;
                cur -> down = head;
                head -> up = cur;
                cur -> right -> right = new Node(-2);
                cur -> right -> right -> left = cur -> right;
                cur -> right -> right -> down = tail;
                tail -> up = cur -> right -> right;
                head = cur;
                tail = head -> right -> right;
                newNode = cur -> right;
                h++;
            }else{//上一层已经存在，则直接建个节点
                while(cur -> right -> val != -2 && cur -> right -> val <= num) cur = cur -> right;
                cur = cur -> right;
                auto t = new Node(num);
                t -> right = cur;
                t -> left = cur -> left;
                cur -> left -> right = t;
                cur -> left = t;
                t -> down = newNode;
                newNode -> up = t;
                newNode = t;
            }
        }
    }
    
    bool erase(int num) {
        auto cur = head;
        Node* pre = nullptr;
        do{
            while(cur -> right -> val != -2 && cur -> right -> val <= num) cur = cur -> right;
            pre = cur;
            cur = cur -> down;
        }while(cur);
        bool f = false;
        while(pre && pre -> val == num){
            f = true;
            pre -> right -> left = pre -> left;
            pre -> left -> right = pre -> right;
            cur = pre;
            pre = cur -> up;
            delete cur;
        }
        // if(f){
        //     cout<<num<<"--"<<endl;
        //     auto j = head;
        //     do{
        //         auto t = j;
        //     while(j -> right){
        //         cout<<j->val<<",";
        //         j = j -> right;
        //     }
        //     cout<<endl;
        //     j = t -> down; 
        //     }while(j);
        //     cout<<"---"<<endl;
        // }
        return f;
    }
};
```
