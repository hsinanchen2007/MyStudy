### 解题思路
数学推导的贪心算法= =就不说了，看也看不懂。只说用链表的方法来模拟，构建环形链表的方法就是当遍历到end()时跳回begin()
注意链表在赋值之后才能添加iterator对象，不然会直接报错（原来的代码错误就是把next赋值放在了private）

### 代码

```cpp
class Solution {

public:
    int lastRemaining(int n, int m) {
        if(n<1||m<1)
            return -1;

        for(int i=0;i<n;i++){
            list_n.push_back(i);
        }
        
        list<int>::iterator next = list_n.begin();
        while(list_n.size()>1){
            list<int>::iterator curr = next;
            for(int i=1;i!=m;i++){
                ++curr;
                if(curr == list_n.end()){
                    curr = list_n.begin();
                }
            }
            next = ++curr;
            if(next == list_n.end())
                next = list_n.begin();
            --curr;
            list_n.erase(curr);
        }
        return list_n.front();
    }

private:
    list<int> list_n;

};
```