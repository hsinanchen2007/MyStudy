方法一
```
class Solution {
public:
    int hammingDistance(int x, int y) {
        int count=0;
        while(x>0||y>0){ 
            if(x%2!=y%2) count++;
            x /= 2; 
            y /= 2;   
        }
        return count;
    }
};
```
方法二 异或
```
class Solution {
public:
    int hammingDistance(int x, int y) {
        int tmp=x^y;
        int count=0;
        while(tmp){
            if(tmp&1) count++;
            tmp >>= 1;
        }
        return count;
    }
};
```

