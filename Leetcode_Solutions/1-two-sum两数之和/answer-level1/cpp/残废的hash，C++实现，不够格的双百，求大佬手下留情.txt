很迷，到现在不是很理解内存消耗上的问题，使用一个数组跟使用几个变量内存占用没什么区别。在下对于hashmap的实现理解不够深入，还没有手动构建hashmap的技术，因此采用了这样一个残废的假hash实现，思路类似，代码逻辑有点乱，仅仅纪念一下第一次试着写题解，大佬们轻喷，这是来自萌新的请求...
```
class entry{
    public:
    entry(){
        num=-1;pos=-1;
        next=nullptr;
    }
    entry(int n,int p){
        num=n;pos=p;next=nullptr;
    }
    int num;
    int pos;
    entry* next;
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        if(nums.size()<2)return result;
        int tablesize=100;
        entry* head[100];
        memset(head,0,sizeof(head));
        for(int i=0;i<nums.size();i++){
            int left=target-nums[i];
            int hush=abs(left)%tablesize;
            entry* p=head[hush];
            while(p!=nullptr){
                if(p->num==left){
                    result.push_back(p->pos);
                    result.push_back(i);
                    return result;
                }
                p=p->next;
            }
            hush=abs(nums[i])%tablesize;
            p=head[hush];
            head[hush]=new entry(nums[i],i);
            head[hush]->next=p;
        }
        return result;
    }
};
```
