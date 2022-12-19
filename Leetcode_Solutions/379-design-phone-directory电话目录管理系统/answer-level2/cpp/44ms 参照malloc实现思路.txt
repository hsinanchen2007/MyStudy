### 解题思路

链表储存已经分配的区间

### 代码

```cpp
class PhoneDirectory {
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    list<pair<int,int>> li;
    int mm;
    PhoneDirectory(int maxNumbers) {
        mm=maxNumbers;
        li.push_back({-1,0});
        li.push_back({mm,INT_MAX});
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        auto tmp1=li.begin();
        auto tmp=tmp1++;
        int ret;
        if((ret=tmp->second)>mm)return -1;
        if(++tmp->second==tmp1->first){
            tmp->second=tmp1->second;
            li.erase(tmp1);
        }
        return ret;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        for(auto &i:li){
            if(i.first>number)return true;
            if(i.second>number)return false;
        }
        return true;
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        for(auto it=li.begin();it!=li.end();++it){
            if(it->first>number)return ;
            if(it->first<=number&&it->second>number){
                if(it->first==number){
                    it->first+=1;
                }else if(it->second==number+1){
                    it->second-=1;
                }else{
                    auto tmp=*it;
                    tmp.first=it->first;tmp.second=number;
                    it->first=number+1;
                    li.insert(it,tmp);
                }
                return ;
            }
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */
```