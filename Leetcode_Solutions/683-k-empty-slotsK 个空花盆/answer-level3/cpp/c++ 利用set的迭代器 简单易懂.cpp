
用set来存已经开的花，因为c++中的set是自动排序的，set在插入元素后会返回指向相应位置的迭代器。  

获取到迭代器后，根据当前的迭代器，往前看一下已经开的花是哪盆，再往后看一下已经开的花是哪盆，看一下是不是刚好隔K个就行了。

<br>
```cpp
class Solution {
public:
    int kEmptySlots(vector<int>& bulbs, int K) {
        int N = bulbs.size();
        set<int> opened;
        
        for(int i = 0; i < N; i++){
            int curr = bulbs[i];                    //当前开的花
            auto iter = opened.insert(curr).first;  //插入后得到相应位置的迭代器

            if(*iter != *opened.begin()){           //如果不是被插到了开头，跟前边的比一下
                auto temp = iter;
                temp--;
                if(curr - *temp - 1 == K)
                    return i+1;
            }
            
            iter++;
            if(*iter != *opened.end()){              //如果不是被插到了结尾，跟后边的比一下
                if(*iter - curr - 1 == K)
                    return i+1;
            }
        }
        
        return -1;
    }
};
```