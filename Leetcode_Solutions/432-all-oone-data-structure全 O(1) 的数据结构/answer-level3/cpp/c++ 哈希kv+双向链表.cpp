分析题意可知：
1. 在O(1)时间内查询(inc和dec均需要查询)，那么哈希表是一个很好的选择。
2. 在O(1)时间内得到最大值和最小值，这说明最大值和最小值是可以直接获得的，即结构本身有序。
2. 在O(1)时间内修改，这里可以说明常用的有序数据结构如`std::map`均不能使用。倘若使用数组来处理，而数组的插入删除复杂度是O(N)的。但是可以注意到插入和删除都是在key的值为1时发生，即有序结构的最左端。而修改也仅是+1或者-1也仅是对相邻元素处理，因此考虑使用有序双向链表来存储数据。
3. 考虑到可能会出现多个value是相同的值，那么一个元素自增或自减可能要“越过”这些相同的元素(因为它们在有序链表是相邻的)，则修改的复杂度会退化为O(N)，因此这里需要用一个节点存储所有相同的value。

![image.png](https://pic.leetcode-cn.com/340c10bb1b1258f0dc38bb8cedeebd3112f044a1955be148e317603244974605-image.png)

![image.png](https://pic.leetcode-cn.com/2f715e316a88379a517f7413be18a89b1a6f404fea1443514e72e854a30b2215-image.png)

```cpp
class AllOne {
public:
    /** Initialize your data structure here. */
    struct Node{
        unordered_set<string> container;
        int val = 0;
        Node(int v):val(v){}
    };
    unordered_map<string, list<Node>::iterator> kv;
    list<Node> List;
    AllOne() {}
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if(kv.count(key)){
            auto oldNode = kv[key];
            auto newNode = next(oldNode, 1);
            if(newNode == List.end() || newNode->val>oldNode->val+1){
                newNode = List.insert(newNode, Node(oldNode->val+1));
            }

            newNode->container.insert(key);
            oldNode->container.erase(key);

            if(oldNode->container.empty()){
                List.erase(oldNode);
            }
            kv[key] = newNode;
        } else {
            auto newNode = List.begin();
            if(List.empty() || List.begin()->val>1)
                newNode = List.insert(List.begin(), Node(1));
            newNode->container.insert(key);
            kv[key] = newNode;
        }
    }

    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if(kv.count(key)){
            auto oldNode = kv[key];
            if(oldNode->val==1) {
                kv.erase(key);
            } else {
                auto newNode = next(oldNode, -1);
                if(oldNode==List.begin() || newNode->val<oldNode->val-1){
                    newNode = List.insert(oldNode, Node(oldNode->val-1));
                }
                newNode->container.insert(key);
                kv[key] = newNode;
            }

            oldNode->container.erase(key);
            if(oldNode->container.empty()){
                List.erase(oldNode);
            }
        }
    }

    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if(List.empty()) return "";
        return *List.rbegin()->container.begin();
    }

    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if(List.empty()) return "";
        return *List.begin()->container.begin();
    }
};
```
