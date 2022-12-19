
```
class CustomStack {
public:
    vector<int> stac;
    int max;
    CustomStack(int maxSize) {
        max=maxSize;
    }
    
    void push(int x) {
     if(stac.size()==max) return;
     stac.push_back(x);
    
    }
    
    int pop() {
      if(stac.size()==0) return -1;
        int re;
        re=stac[stac.size()-1];
        stac.pop_back();
      return re;  
    }
    
    void increment(int k, int val) {
        int i;
        if(k>stac.size()) k=stac.size();
        for(i=0;i<k;i++){
            stac[i]+=val;
        }
    }
};
```
