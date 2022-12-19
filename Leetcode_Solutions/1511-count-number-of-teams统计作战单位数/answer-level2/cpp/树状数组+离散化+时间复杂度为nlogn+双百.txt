使用树状数组，通过将原rating中的数据离散化，然后分别从左至右和从右至左两趟遍历实现对左右大于小于元素的计算。
```
class Solution {
public:
    map<int,int> mp;
    int *c,size;
    int lowbit(int m){
        return m&(-m);
    }
    int get_sum(int m){
        int res=0;
        while(m){
            res+=c[m];
            m-=lowbit(m);
        }
        return res;
    }
    void insert(int m){
        //tree[m]=1;
        while(m<=size){
           c[m]+=1;
           m+=lowbit(m);
        }
    }
    int numTeams(vector<int>& rating) {
        int res=0;
        if(rating.size()<=2)return 0;
        vector<int> helper=rating;
        sort(rating.begin(),rating.end());
        size=rating.size();
        for(int i=0;i<size;i++){//离散化处理
            mp[rating[i]]=(i+1);
        }
        vector<int> lessl,lessr,largerl,largerr;
        c=new int[size+1];memset(c,0,sizeof(int)*(size+1));
        for(int i=0;i<size;i++){
            int now=mp[helper[i]];
            lessl.push_back(get_sum(now-1));
            largerl.push_back(get_sum(size)-get_sum(now));
            insert(now);
        }
        memset(c,0,sizeof(int)*(size+1));
        for(int i=size-1;i>=0;i--){
            int now=mp[helper[i]];
            lessr.push_back(get_sum(now-1));
            largerr.push_back(get_sum(size)-get_sum(now));
            insert(now);
        }
        for(int i=0;i<size;i++){
            res+=lessl[i]*largerr[size-i-1];
            res+=lessr[size-i-1]*largerl[i];
        }
        return res;
    }
};
```
![image.png](https://pic.leetcode-cn.com/5cfadb921f1c7848a91b1ee2cc32c68637d8aa525c18f0dae725bb20118fbc2b-image.png)
