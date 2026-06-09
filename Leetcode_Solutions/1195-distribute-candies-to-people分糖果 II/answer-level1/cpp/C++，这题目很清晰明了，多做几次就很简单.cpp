对比官方答案，有两处可以改进，发放多少轮，可以直接解方程求出，最后发到多少个人可以先求出来，避免rest和tmp的比较判断，减少时间。
```
class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
    int x=1;
    while((num_people*x+1)*num_people*x/2<candies){
        ++x;
        }
    vector<int> vec;
    int rest=candies-(num_people*(x-1)+1)*num_people*(x-1)/2;
    int tmp,val;
    for(int i=0;i<num_people;i++){
        tmp = (x-1)*num_people+i+1;
        if(rest<tmp) {
            tmp=rest;
            rest=0;
        }
        else{
            rest-=tmp;
        }
        val=(i+1)*(x-1)+num_people*(x-2)*(x-1)/2+tmp;
        vec.push_back(val);
        
    }
    return vec;
    }
};

```
