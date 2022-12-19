可以调整maxLevel参数的大小。
```
class Skiplist {
public:
    Skiplist() {
        levelNum = 0;
        maxLevel = 32;
        head = new levelNode(maxLevel, INT_MIN);
    }
    
    bool search(int target) {
        int currLevel = levelNum;
        levelNode* nd = head;
        while(nd && currLevel >= 0){
            if(nd != head && nd->val == target) return true;
            if(!nd->next[currLevel] || nd->next[currLevel]->val >= target){
                currLevel--;
            }else{
                nd = nd->next[currLevel];
            }
        }
        return nd->next[0] ? (nd->next[0]->val == target) : false;
    }

    int randomLevel(){
        int level = 0;
         while(rand() % 4 == 0){
             level++;
             if(level >= maxLevel) break;
         }
         return level;
    }
    
    void add(int num) {
        int currLevel = levelNum;
        levelNode *nd = head;
        vector<levelNode*> pres(levelNum + 1, nullptr);
        while(nd && currLevel >= 0){
            if(!nd->next[currLevel] || nd->next[currLevel]->val >= num){
                pres[currLevel] = nd;
                currLevel--;
            }else{
                nd = nd->next[currLevel];
            }
        }
        int newLevel = randomLevel();
        //cout<<"level:" << newLevel <<endl;
        levelNode* newNode = new levelNode(newLevel, num);
        if(newLevel > levelNum){
            for(int i = newLevel; i > levelNum; i--){
                head->next[i] = newNode;
            }
        }
        for(int i = 0; i <= min(newLevel, levelNum); i++){
            levelNode* next = pres[i]->next[i];
            pres[i]->next[i] = newNode;
            newNode->next[i] = next;
        }
        levelNum = max(newLevel, levelNum);
    }
    
    bool erase(int num) {
        int currLevel = levelNum;
        levelNode *nd = head;
        vector<levelNode*> pres(currLevel+1, nullptr);
        while(nd && currLevel >= 0){
            //cout<<nd->val << " " << currLevel<<endl;
            if(!nd->next[currLevel] || nd->next[currLevel]->val >= num){
                pres[currLevel] = nd;
                currLevel--;
            }else{
                nd = nd->next[currLevel];
            }
        }
        if(!nd || !nd->next[0] ||  nd->next[0]->val != num) return false;
        levelNode *del = nd->next[0];
        //cout<<"next"<<del->val <<endl;

        for(int i = 0; i < del->num; i++){
            //cout<<pres[i]->next.size()<<endl;
            pres[i]->next[i] = del->next[i];
        }
        //cout<<"shrink"<<endl;
        while(levelNum > 0 && head->next[levelNum] == nullptr){
            levelNum--;
        }
        delete del;
        return true;
    }

    struct levelNode{
        levelNode** next;
        int val;
        int num;
        levelNode(int l, int v): val(v), num(l+1){
            //next.resize(l+1, nullptr);
            next = new levelNode*[l+1];
            for(int i = 0; i <= l; i++) next[i] = nullptr;
        }
    };
    levelNode *head;
    int levelNum;
    int maxLevel;
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
```
