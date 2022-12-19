### 解题思路
这道理看懂题目就花了很长时间，有几个要注意的tips
1.当访问次数相同时，比如我访问了key=1,key=2,各一次，那么key==1先访问的，key==2后访问的，如果我需要再增加一个元素，我就把key==1删除
2.每次访问一个key时，我们需要把它的频率更新，然后把它最新的访问时间更新
3.每次put新元素时，如果key存在了，就把key的value更新，它的访问次数更新，它的最新访问时间更新
  如果key不存在，就看容量满了没有，如果满了，就找最少访问的元素删掉
                                如果没有满，就直接把这个元素加入队尾

### 代码

```cpp
struct keyvalue{
int value;
int key;
int fre; //使用频率
int time; //记录时间
};
class LFUCache {
public:
    int ca;
    int t=0; //初始化当前时间为0
    vector<keyvalue> v;

    LFUCache(int capacity) {
    ca=capacity;
    }

    int get(int key) {
        t++;//访问一次。当前时间加1
     for(int i=0;i<v.size();i++){
        keyvalue k=v[i];
        if(k.key==key){
        k.fre++;
        k.time=0;
        v.erase(v.begin()+i);
        v.push_back(k);
            return k.value;
        }
     }
     return -1;
    }

    void put(int key, int value) {
        if(ca==0)
            return;
        t++;//放入一个键，那么时间就会变多
        int flag=1;
        keyvalue k;k.key=key;k.value=value;k.fre=1;k.time=t;//使用频率记为0
        for(int i=0;i<v.size();i++){
        keyvalue k2=v[i];
        if(k2.key==key){
            flag=0;   //键存在了
            k2.fre++; //访问次数加1
            k2.value=value;
            k2.time=t;
            v.erase(v.begin()+i);
            v.push_back(k2);
            return ;
        }
     }
     if(flag==1){
        if(v.size()<ca){  //容量没有满
     //之前没有出现过这个key
        v.push_back(k);
     }

    else{//容量满了,找使用频率最少的
        int mark=0,mark2=0,mn=0;
        keyvalue k3;
        for(int i=0;i<v.size();i++){
                k3=v[i];
           if(i==0){
            mn=k3.fre;
            mark2=k3.time;
            mark=i;
            continue;
           }
           if(k3.fre<=mn){

            if(k3.fre<mn){
               mn=k3.fre;
               mark=i;
               mark2=k3.time;
            }
            if(k3.fre==mn&&k3.time<mark2){//如果频率相等且在缓存中的时间更长
            mark=i;
            mark2=k3.time; //把时间保存起来
            }
           }
        }
        v.erase(v.begin()+mark);
        v.push_back(k);
    }
    }

    }
};
```