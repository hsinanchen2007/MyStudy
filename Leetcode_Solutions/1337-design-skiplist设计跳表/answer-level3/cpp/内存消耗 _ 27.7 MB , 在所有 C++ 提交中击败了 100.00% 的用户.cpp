### 解题思路
此处撰写解题思路

### 代码

```cpp
#include <iostream>

using namespace std;

struct Node {
    int value;
    Node *next;
    Node *below;
    Node(int _value, Node *_next, Node *_below) : value(_value), next(_next), below(_below) {}
    Node() {}
};
class Skiplist {
    const static int MAX_LEVEL = 1 << 4;
    Node *heads[MAX_LEVEL];
public:
    Skiplist() {
        for (int i = 0; i < MAX_LEVEL; ++i) {
            heads[i] = new Node(-1, nullptr, nullptr);
            if (i > 0) {
                heads[i]->below = heads[i - 1];
            }
        }
    }
    
    bool search(int target) {
        Node *p = this->heads[MAX_LEVEL - 1];
        while (p != nullptr) {
            while (p->next == nullptr && p->below != nullptr) {
                p = p->below;
            }
            while (p->next != nullptr && p->next->value < target) {
                p = p->next;
            }
            if (p->next != nullptr) {
                if (p->next->value > target) {
                    p = p->below;
                } else if (p->next->value < target) {
                    p = p->next;
                } else {
                    return true;
                }
            } else {
                p = p->below;
            }
        }
        return false;
    }


    
    void add(int num) {
        int newLevel = randomLevel();
        {
            Node *toBeAddNodeLeftIndex[newLevel];
            Node *toBeAddNodeLeft = this->heads[newLevel - 1];

            int _curLevel = newLevel - 1;
            while (toBeAddNodeLeft != nullptr) {
                while (toBeAddNodeLeft->next != nullptr && toBeAddNodeLeft->next->value < num) {
                    toBeAddNodeLeft = toBeAddNodeLeft->next;
                }
                toBeAddNodeLeftIndex[_curLevel] = toBeAddNodeLeft;
                if (toBeAddNodeLeft->below != nullptr) {
                    toBeAddNodeLeft = toBeAddNodeLeft->below;
                } else {
                    toBeAddNodeLeft = nullptr;
                }
                _curLevel--;
            }
            Node *lastBelowNode = nullptr;
            for (int i = 0; i <= newLevel - 1; ++i) {
                Node *idxP = toBeAddNodeLeftIndex[i];
                assert(idxP != nullptr);
                Node *newNode = new Node(num, idxP->next, lastBelowNode);
                idxP->next = newNode;
                lastBelowNode = newNode;
            }

        }
    }


    bool erase(int num) {
        Node *p = this->heads[MAX_LEVEL - 1];
        while (p != nullptr) {
            while (p->next == nullptr && p->below != nullptr) {
                p = p->below;
            }
            while (p->next != nullptr && p->next->value < num) {
                p = p->next;
            }
            if (p->next != nullptr) {
                if (p->next->value == num) {
                    Node *toBeDeletedNodeLeft = p;
                    while (toBeDeletedNodeLeft != nullptr) {
                        if (toBeDeletedNodeLeft->next != nullptr && toBeDeletedNodeLeft->next->value == num) {
                            if (toBeDeletedNodeLeft->next->next != nullptr) {
                                toBeDeletedNodeLeft->next = toBeDeletedNodeLeft->next->next;
                            } else {
                                toBeDeletedNodeLeft->next = nullptr;
                            }
                            if (toBeDeletedNodeLeft->below != nullptr) {
                                toBeDeletedNodeLeft = toBeDeletedNodeLeft->below;
                            } else {
                                toBeDeletedNodeLeft = nullptr;
                            }
                        }
                        while (toBeDeletedNodeLeft != nullptr && toBeDeletedNodeLeft->next != nullptr &&
                               toBeDeletedNodeLeft->next->value < num) {
                            toBeDeletedNodeLeft = toBeDeletedNodeLeft->next;
                        }
                    }

                    return true;
                } else if (p->next->value > num) {
                    p = p->below;
                } else if (p->next->value < num) {
                    p = p->next;
                }
            } else {
                p = p->below;
            }
        }

        return false;
    }

    int randomLevel() {
        int _level = 1;
        while (random() % 2 == 1 && _level < MAX_LEVEL) {
            _level++;
        }
        return _level;
    }

    
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */
```