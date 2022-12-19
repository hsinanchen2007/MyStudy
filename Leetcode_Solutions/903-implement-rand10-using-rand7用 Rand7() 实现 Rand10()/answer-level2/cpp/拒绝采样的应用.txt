// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

//要得到rand10(),首先得到rand10() * K，这里的关键是a的分布一定是均匀的（概率相同）
```
class Solution {
public:
    int rand10() {
        while(true)
        {
            int a=(rand7()-1)*7+rand7();//1-49
            if(a<=40) 
                return a%10+1;//n%10 得到 0-9  
        }
        return 0;
    }
};
```
