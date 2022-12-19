```
class Solution {
public:
    int findCelebrity(int n) {//贪心求得局部最优解+验证
        int candidate=0;
        for(int i=1;i<n;i++){
            candidate=knows(candidate,i)?i:candidate;
        }
        for(int i=0;i<n;i++){
            if(i==candidate) continue;
            if(!knows(i,candidate)||knows(candidate,i)) return -1;
        }
        return candidate;
    }
};
```
