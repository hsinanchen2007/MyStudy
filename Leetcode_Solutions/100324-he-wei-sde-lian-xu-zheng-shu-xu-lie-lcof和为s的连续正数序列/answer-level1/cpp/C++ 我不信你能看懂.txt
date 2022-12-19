![image.png](https://pic.leetcode-cn.com/ce7f4bf6870d47a3bba3e97b93fbda2c43a977849518418658dd5c8ecc4bb6eb-image.png)
```
    vector<vector<int>> findContinuousSequence(int trg) {
        vector<vector<int>> res;
        if(trg<3) return res;
        for(int i=2,tmp=0;i<=trg/3;++i)
            if(trg%(2*i+1)==0 && trg/(2*i)<=i)
                res.push_back(sub_vector(i-trg/(2*i+1)+1,i+trg/(2*i+1)));
            else if(trg%i==0 && (trg/i)&1 && trg/i/2<=i)
                res.push_back(sub_vector(i-trg/i/2,i+trg/i/2));
        if(trg&1)
            res.push_back({trg/2,trg/2+1});
        return res;
    }
    vector<int> sub_vector(int begin,int end){
        vector<int> res;
        for(;begin<=end;++begin)
            if(begin!=0)
                res.push_back(begin);
        return res;
    }
```
