### 解题思路
此处撰写解题思路

### 代码

```cpp
class Solution {
public:
    int lastRemaining(int n, int m) {
        // if(n<1 || m<1) return -1;

        // unsigned int i=0;

        // list<int> numbers;
        // for(i=0; i<n; ++i)
        // {
        //     numbers.push_back(i);
        // }

        // list<int>::iterator iter=numbers.begin();
        // while(numbers.size()>1)
        // {
        //     for(i=1; i<m; ++i)
        //     {
        //         ++iter;
        //         if(iter==numbers.end()) iter=numbers.begin();
        //     }

        //     list<int>::iterator next=++iter;
        //     if(next==numbers.end()) next=numbers.begin();

        //     --iter;
        //     numbers.erase(iter);
        //     iter=next;
        // }

        // return *(iter);

        if(n<1 || m<1) return -1;

        int last=0;
        for(int i=2; i<=n; ++i)
        {
            last=(last+m)%i;
        }

        return last;
    }
};
```